import cv2
import time
import math
import numpy as np
from hand_tracking_module import HandDetector
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume

#global cam size
wCam, hCam = 640, 480

if __name__ == '__main__':
    cap = cv2.VideoCapture(0)
    cap.set(3, wCam)
    cap.set(4, hCam)
    
    devices = AudioUtilities.GetSpeakers()
    interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
    volume = interface.QueryInterface(IAudioEndpointVolume)
    vol_percentage = int(volume.GetMasterVolumeLevelScalar() * 100)
    
    detector = HandDetector(maxHands=1, min_detect_confidence=0.75)
    
    cTime = time.time()
    pTime = time.time()
    while cap.isOpened():
        success, img = cap.read()
        img = cv2.flip(img, 1)
        if not success:
            continue
        
        #detect hand
        detector.track_hands(img)
        lm_list = detector.findPosition(img, draw=False)
        if len(lm_list) != 0:
            #print(lm_list[4], lm_list[8]) 4 and 8 are top of first and second fingers respectively according to mediapipe website
            
            #if 3,4, and 5th fingers are not open, then skip this
            closed_finger = 0
            tipIds = [12, 16, 20]
            for i in tipIds:
                if lm_list[i][2] > lm_list[i-2][2]:
                    closed_finger += 1
            
            if(closed_finger == 0): #only adjust volume if no finger closed
                x1,y1 = lm_list[4][1], lm_list[4][2]
                x2,y2 = lm_list[8][1], lm_list[8][2]
                
                cx, cy = (x1+x2)//2, (y1+y2)//2
                
                length = math.hypot(x2-x1, y2-y1)
                
                if length >= 200:   
                    length = 200    #limit maximum value to 200
                
                #mark the 2 circles on finger tips
                if length < 50 or length == 200:
                    cv2.circle(img, (cx,cy), 15, (0, 0, 255), cv2.FILLED)   #button press effect
                    cv2.circle(img, (x1,y1), 15, (0, 0, 255), cv2.FILLED)
                    cv2.circle(img, (x2,y2), 15, (0, 0, 255), cv2.FILLED)
                else:
                    cv2.circle(img, (x1,y1), 15, (255, 0, 255), cv2.FILLED)
                    cv2.circle(img, (x2,y2), 15, (255, 0, 255), cv2.FILLED)
                    cv2.circle(img, (cx,cy), 15, (255, 0, 255), cv2.FILLED)
                cv2.line(img, (x1,y1), (x2,y2), (0, 255, 0), 3)
                
                new_vol_value = np.interp(length, [50, 200], [0, 1])
                volume.SetMasterVolumeLevelScalar(new_vol_value, None)
        
        #render volume bar
        vol_percentage = volume.GetMasterVolumeLevelScalar() * 100
        cv2.rectangle(img, (50, 150), (85, 400), (0, 255, 0), 3)
        cv2.rectangle(img, (50, 400-int(vol_percentage*2.5)), (85, 400), (0, 255, 0), cv2.FILLED)
        cv2.putText(img, f"{int(vol_percentage)}%", (50, 450), cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 0), 2)
        
        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        
        # draw the fps
        cv2.putText(img, str(round(fps)), (10, 50), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2)
        
        cv2.imshow("Webcam", img)
        cv2.waitKey(1)