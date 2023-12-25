import cv2
import mediapipe as mp
import time
import math

class PoseTracker:
    #initialize pose tracking model
    def __init__(self, imageMode=False, model_complexity=1, smooth_landmarks=True, 
                 enable_segmentation=False, smooth_segmentation=True, 
                 min_detect_confidence=0.5, min_track_confidence=0.5):
        self.mpPose = mp.solutions.pose
        self.pose = self.mpPose.Pose(imageMode, model_complexity, smooth_landmarks, 
                                     enable_segmentation, smooth_segmentation, min_detect_confidence,
                                        min_track_confidence)
        self.mpDraw = mp.solutions.drawing_utils
        self.results = None

        # variables to track frame rate
        self.pTime = time.time()
        self.cTime = time.time()
    
    def track_pose(self, img, draw=True):
         # convert image and send to process to detect hand
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.pose.process(imgRGB)
        # draw tracked pose
        if draw:
            if self.results and self.results.pose_landmarks:
                self.mpDraw.draw_landmarks(img, self.results.pose_landmarks, self.mpPose.POSE_CONNECTIONS)
    
    def findPosition(self, img, draw=True):
        self.landmark_list = []

        # draw tracked pose
        if self.results.pose_landmarks:
            pose = self.results.pose_landmarks
            
            # display information for landmarks of pose detected
            for id, lm in enumerate(pose.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)
                self.landmark_list.append([id, cx, cy])
                if draw:
                    cv2.circle(img, (cx, cy), 10, (255, 0, 0), cv2.FILLED)

        return self.landmark_list
    
    # calculate fps
    def calc_fps(self):
        self.cTime = time.time()
        fps = 1 / (self.cTime - self.pTime)
        self.pTime = self.cTime
        return fps

    def findAngle(self, img, p1, p2, p3, draw=True):
        #get landmarks
        x1, y1 = self.landmark_list[p1][1:]
        x2, y2 = self.landmark_list[p2][1:]
        x3, y3 = self.landmark_list[p3][1:]
        
        #get angle
        angle = math.degrees(math.atan2(y3-y2, x3-x2) - math.atan2(y1-y2, x1-x2))
        
        if angle < 0:
            angle += 360
        
        #draw
        if draw:
            cv2.line(img, (x1,y1), (x2,y2), (0,255,0),3)
            cv2.line(img, (x2,y2), (x3,y3), (0,255,0),3)
            cv2.circle(img, (x1,y1), 10, (255,0,0),cv2.FILLED)
            cv2.circle(img, (x1,y1), 15, (255,0,0),2)
            cv2.circle(img, (x2,y2), 10, (255,0,0),cv2.FILLED)
            cv2.circle(img, (x2,y2), 15, (255,0,0),2)
            cv2.circle(img, (x3,y3), 10, (255,0,0),cv2.FILLED)
            cv2.circle(img, (x3,y3), 15, (255,0,0),2)
            cv2.putText(img,str(int(angle)), (x2 + 20, y2 + 20), cv2.FONT_HERSHEY_PLAIN, (0, 0, 255), 2)
        
        return angle
            

if __name__ == "__main__":
    # initialize camera
    cap = cv2.VideoCapture("video.mp4")
    detector = PoseTracker()

    while True:
        success, img = cap.read()

        detector.track_pose(img)
        lm_list = detector.findPosition(img)
        if len(lm_list) > 0:
            print(lm_list[0])

        # draw the fps
        cv2.putText(img, str(round(detector.calc_fps())), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)

        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(10)