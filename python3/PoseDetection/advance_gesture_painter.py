import cv2
import time
import numpy as np
import os
from hand_tracking_module import HandDetector

wCap, hCap = 1280, 720
brushThickness = 5
eraserThickness = 5

if __name__ == '__main__':
    folderPath = "Header"
    myList = os.listdir(folderPath)
    
    overlayList = []
    for imPath in myList:
        image = cv2.imread(f"{folderPath}/{imPath}")
        overlayList.append(image)
    drawColors = [
        (0, 0, 255),
        (0, 255, 0),
        (255, 0, 0),
        (0,0,0)
    ]
    
    cap = cv2.VideoCapture(0)
    cap.set(3, wCap)
    cap.set(4, hCap)
    
    currentPaintMode = 0
    detector = HandDetector(min_detect_confidence=0.75)
    xp = 0
    yp = 0
    
    imgCanvas = np.zeros((720, 1280, 3), np.uint8)
    
    while cap.isOpened():
        success, img = cap.read()
        img = cv2.flip(img, 1)
        
        if not success:
            continue
        
        img = cv2.resize(img, (1280, 720))
        
        #detect hand
        detector.track_hands(img)
        lm_list = detector.findPosition(img, draw=False)
        if len(lm_list) != 0:
            x1,y1 = lm_list[8][1:] #tip of index finger
            x2,y2 = lm_list[12][1:] #tip of middle finger
            
            #check which finger is up
            fingers = detector.fingersUp()
            
            if fingers[1] and fingers[2]:
                xp, yp=0, 0
                #selection mode = 2 finger up
                cv2.rectangle(img, (x1, y1-25),(x2, y2+25), drawColors[currentPaintMode], cv2.FILLED )
                #checking for click
                if y1 < 125:
                    if 393 < x1 < 477:
                        currentPaintMode = 0
                    elif 572 < x1 < 664:
                        currentPaintMode = 1
                    elif 751 < x1 < 835:
                        currentPaintMode = 2
                    elif 986 < x1 < 1106:
                        currentPaintMode = 3
                    
            elif fingers[1] and fingers[2] == False:
                cv2.circle(img, (x1,y1), 15, drawColors[currentPaintMode], cv2.FILLED)
                #drawing mode = index finger up
                
                if xp==0 and yp==0:
                    xp, yp = x1, y1     #to cater very first point will be 0,0
                
                if currentPaintMode == 3:
                    cv2.line(imgCanvas, (xp,yp), (x1,y1), drawColors[currentPaintMode], eraserThickness)
                else:
                    cv2.line(imgCanvas, (xp,yp), (x1,y1), drawColors[currentPaintMode], brushThickness)
            xp, yp = x1, y1
                
        imgGrey = cv2.cvtColor(imgCanvas, cv2.COLOR_BGR2GRAY)
        _, imgInv = cv2.threshold(imgGrey, 50, 255, cv2.THRESH_BINARY_INV)
        imgInv = cv2.cvtColor(imgInv, cv2.COLOR_GRAY2BGR)
        img = cv2.bitwise_and(img, imgInv)
        img = cv2.bitwise_or(img, imgCanvas)
        
        #draw the header image
        img[0:150,0:1280] = overlayList[currentPaintMode]
        #img = cv2.addWeighted(img, 0.8, imgCanvas, 0.2, 0)
        
        cv2.imshow("Canvas", img)
        cv2.waitKey(1)

