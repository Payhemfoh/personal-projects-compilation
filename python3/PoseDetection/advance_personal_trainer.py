import cv2
import time
import numpy as np
from pose_tracking_module import PoseTracker


if __name__ == '__main__':
    cap = cv2.VideoCapture(0)
    
    detector = PoseTracker()
    count = 0
    direction = 0
    progress = 0
    cTime = time.time()
    pTime = time.time()
    while cap.isOpened():
        success, img = cap.read()
        
        if not success:
            continue
        
        img = cv2.resize(img, (1280, 720))
        
        #detect hand
        detector.track_pose(img)
        lm_list = detector.findPosition(img, draw=False)
        if len(lm_list) != 0:
            #right arm
            angle = detector.findAngle(img, 12, 14, 16)
            
            #left arm
            #detector.findAngle(img, 11, 13, 15)
            
            #right leg
            #detector.findAngle(img, 23, 25, 27)
            
            #left leg
            #detector.findAngle(img, 22, 24, 26)
            
            progress = np.interp(angle, [210, 310], [0, 100]) 
            
            color = (255, 0, 255)
            #check direction
            if progress == 100:
                color = (0, 255, 0)
                if direction == 0:
                    count += 0.5
                    direction = 1
            elif progress == 0:
                color = (0, 255, 0)
                if direction == 1:
                    count += 0.5
                    direction = 0
        
        #render progress bar
        cv2.putText(img, f"{count}%", (50, 100), cv2.FONT_HERSHEY_PLAIN, 2, color, 2)
        cv2.rectangle(img, (50, 150), (85, 400), color, 3)
        cv2.rectangle(img, (50, 400-int(progress*2.5)), (85, 400), color, cv2.FILLED)
        cv2.putText(img, f"{int(progress)}%", (50, 450), cv2.FONT_HERSHEY_PLAIN, 2, color, 2)
        
        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        
        # draw the fps
        cv2.putText(img, str(round(fps)), (10, 50), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2)
        
        cv2.imshow("Webcam", img)
        cv2.waitKey(1)
