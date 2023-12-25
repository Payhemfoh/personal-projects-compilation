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
    
    closed_finger = 0
    
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
            #finger tips are 4, 8, 12, 16, 20
            #if finger lower than 2, 6, 10, 14. 18 means is close
            #check only y coordinates of finger
            closed_finger = 0
            
            if lm_list[4][1] > lm_list[2][1]:   #thumb use x instead of y
                closed_finger += 1
            
            tipIds = [8, 12, 16, 20]
            for i in tipIds:
                if lm_list[i][2] > lm_list[i-2][2]:
                    closed_finger += 1
        
        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        
        # draw the fps
        cv2.putText(img, str(round(closed_finger))+" Finger closed", (10, 50), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2)
        cv2.putText(img, str(round(fps)), (50, 10), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2)
        
        cv2.imshow("Webcam", img)
        cv2.waitKey(1)