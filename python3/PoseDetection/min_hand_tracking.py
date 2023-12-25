import cv2
import mediapipe as mp
import time

if __name__ == "__main__":
    #initialize camera
    cap = cv2.VideoCapture(0)

    #initialize hand detection and tracking module
    mpHands = mp.solutions.hands
    hands = mpHands.Hands()
    mpDraw = mp.solutions.drawing_utils

    #variables to track frame rate
    pTime = time.time()
    cTime = time.time()

    while True:
        success, img = cap.read()
        img = cv2.flip(img, 1)

        #convert image and send to process to detect hand
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        results = hands.process(imgRGB)

        #draw tracked hand pose
        if results.multi_hand_landmarks:
            for landmark in results.multi_hand_landmarks:

                #display information for landmarks of hand detected
                for id, lm in enumerate(landmark.landmark):
                    print(id, lm)
                    h, w, c = img.shape
                    cx, cy = int(lm.x*w), int(lm.y*h)
                    print(cx,cy)
                    if id==4:
                        cv2.circle(img, (cx,cy), 10, (255,0,0), cv2.FILLED)

                mpDraw.draw_landmarks(img, landmark, mpHands.HAND_CONNECTIONS)

        #calculate fps
        cTime = time.time()
        fps = 1/(cTime - pTime)
        pTime = cTime

        #draw the fps
        cv2.putText(img, str(round(fps)), (10,100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)

        #show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(1)
