import cv2
import time
import numpy as np
import pyautogui
from hand_tracking_module import HandDetector

wCap, hCap = 640, 480
frameBorder = 150
#smoothing = 5

if __name__ == '__main__':
    cap = cv2.VideoCapture(0)
    cap.set(3, wCap)
    cap.set(4, hCap)
    
    detector = HandDetector(maxHands=1, min_detect_confidence=0.8)
    cTime = time.time()
    pTime = time.time()
    
    screenWidth, screenHeight = pyautogui.size()
    isClicked = False
    
    while cap.isOpened():
        success, img = cap.read()
        img = cv2.flip(img, 1)
        
        if not success:
            continue
        
        #detect hand
        detector.track_hands(img)
        lm_list = detector.findPosition(img, draw=False)
        if len(lm_list) != 0:
            x1,y1 = lm_list[8][1:] #tip of index finger
            x2,y2 = lm_list[12][1:] #tip of middle finger
            
            #check which finger is up
            fingers = detector.fingersUp()
            
            cv2.rectangle(img, (frameBorder, 50), (wCap-frameBorder, 50+hCap-frameBorder*2), (255, 0, 255), 2)
            
            if fingers[1] and fingers[2] == False:
                #move mode = index finger up    
                isClicked = False
                #convert coordinates
                x3 = np.interp(x1, (frameBorder, wCap-frameBorder), (0, screenWidth))
                y3 = np.interp(y1, (50, 50+hCap-frameBorder*2), (0, screenHeight))
                
                #pyautogui use move to instruct mouse cursor movement, hence need to get current location and calculate pixel to move
                curr_x, curr_y = pyautogui.position()
                x4 = x3 - curr_x
                y4 = y3 - curr_y
                
                #smoothen value
                #clocX = x4/smoothing
                #clocY = y4/smoothing
                
                #move mouse
                pyautogui.move(x4,y4)
                cv2.circle(img, (x1,y1), 15, (255, 0, 255), cv2.FILLED)
            
            elif fingers[1] and fingers[2]:
                #click mode = 2 finger up
                
                #checking for click
                #if distance short == click
                distance, img, line_info = detector.findDistance(8,12, img)
                if distance < 50 and not isClicked:
                    cv2.circle(img, (line_info[4],line_info[5]), 15, (0, 255, 0), cv2.FILLED)
                    pyautogui.click()
                    isClicked = True
                elif distance > 50:
                    isClicked = False
                
        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        
        # draw the fps
        cv2.putText(img, str(round(fps)), (10, 50), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2)
        
        cv2.imshow("Mouse control", img)
        cv2.waitKey(1)
