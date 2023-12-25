import cv2
import mediapipe as mp
import time
import math


class HandDetector:
    # initialize hand detection and tracking module
    def __init__(self, static_mode=False, maxHands=2, model_complexity=1, min_detect_confidence=0.5,
                 min_track_confidence=0.5):
        self.mpHands = mp.solutions.hands
        self.hands = self.mpHands.Hands(static_mode, maxHands, model_complexity, min_detect_confidence,
                                        min_track_confidence)
        self.mpDraw = mp.solutions.drawing_utils
        self.results = None
        self.fingerTipIds = [8, 12, 16, 20]
        # variables to track frame rate
        self.pTime = time.time()
        self.cTime = time.time()

    def track_hands(self, img, draw=True):
        # convert image and send to process to detect hand
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.hands.process(imgRGB)

        # draw tracked hand pose
        if draw:
            if self.results and self.results.multi_hand_landmarks:
                for landmark in self.results.multi_hand_landmarks:
                    self.mpDraw.draw_landmarks(img, landmark, self.mpHands.HAND_CONNECTIONS)

    def findPosition(self, img, hand_no=0, draw=True):
        self.landmark_list = []

        # draw tracked hand pose
        if self.results.multi_hand_landmarks:
            hand = self.results.multi_hand_landmarks[hand_no]

            # display information for landmarks of hand detected
            for id, lm in enumerate(hand.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)
                self.landmark_list.append([id, cx, cy])
                if draw:
                    cv2.circle(img, (cx, cy), 10, (255, 0, 0), cv2.FILLED)

        return self.landmark_list

    def fingersUp(self):
        fingers = []
        
        if self.landmark_list[4][1] > self.landmark_list[2][1]:   #thumb use x instead of y
            fingers.append(0)
        else:
            fingers.append(1)
            
        
        for i in self.fingerTipIds:
            if self.landmark_list[i][2] > self.landmark_list[i-2][2]:
                fingers.append(0)
            else:
                fingers.append(1)
        
        return fingers
    
    def findDistance(self, p1, p2, img, draw=True, r=15, t=3):
        x1,y1 = self.landmark_list[p1][1:]
        x2,y2 = self.landmark_list[p2][1:]
        cx, cy = (x1+x2)//2, (y1+y2)//2
                
        distance = math.hypot(x2-x1, y2-y1)
        
        #mark the 2 circles on finger tips
        if draw:
            cv2.circle(img, (x1,y1), 15, (255, 0, 255), cv2.FILLED)
            cv2.circle(img, (x2,y2), 15, (255, 0, 255), cv2.FILLED)
            cv2.circle(img, (cx,cy), 15, (255, 0, 255), cv2.FILLED)
            cv2.line(img, (x1,y1), (x2,y2), (0, 255, 0), 3)
        
        return distance, img, [x1, y1, x2, y2, cx, cy]

    # calculate fps
    def calc_fps(self):
        self.cTime = time.time()
        fps = 1 / (self.cTime - self.pTime)
        self.pTime = self.cTime
        return fps


if __name__ == "__main__":
    # initialize camera
    cap = cv2.VideoCapture(0)
    detector = HandDetector()

    while True:
        success, img = cap.read()
        img = cv2.flip(img, 1)

        detector.track_hands(img)
        lm_list = detector.findPosition(img)
        if len(lm_list) > 0:
            print(lm_list[0])

        # draw the fps
        cv2.putText(img, str(round(detector.calc_fps())), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)

        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(10)
