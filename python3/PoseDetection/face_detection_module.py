import cv2
import mediapipe as mp
import time

class FaceDetector:
    #initialize face tracking model
    def __init__(self, min_detect_confidence=0.5, long_range_model=False):
        self.mpFaceDetection = mp.solutions.face_detection
        self.mpDraw = mp.solutions.drawing_utils
        self.faceDetection = self.mpFaceDetection.FaceDetection(min_detect_confidence, 0 if long_range_model==False else 1)
        self.results = None

        # variables to track frame rate
        self.pTime = time.time()
        self.cTime = time.time()
    
    def detect_face(self, img, draw=True):
         # convert image and send to process to detect face
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.faceDetection.process(imgRGB)
    
    def findPosition(self, img, draw=True, margin=10):
        landmark_list = []

        # draw detected faces
        if self.results.detections:
            for id, detection in enumerate(self.results.detections):
                #mpDraw.draw_detection(img, detection)
                bBoxC = detection.location_data.relative_bounding_box
                iH, iW, iC = img.shape
                bBox = int(bBoxC.xmin * iW - margin), int(bBoxC.ymin * iH - margin),\
                    int(bBoxC.width * iW + margin * 2), int(bBoxC.height * iH + margin * 2)
                landmark_list.append([id, bBox])
                if draw:
                    img = self.fancyDraw(img, bBox)
                    cv2.putText(img, str(round(detection.score[0]*100))+"%", (bBox[0], bBox[1]-20), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 0), 2)

        return landmark_list
    
    def fancyDraw(self,img,bBox, l=30, t=5, rt=1):
        x, y, w, h = bBox
        x1, y1 = x+w, y+h
        
        #draw face detection block
        cv2.rectangle(img, bBox, (255, 0, 255), rt)
        
        #bold top left corner
        cv2.line(img,(x,y),(x+l,y), (255, 0, 255), t)
        cv2.line(img,(x,y),(x,y+l), (255, 0, 255), t)
        
        #bold top right corner
        cv2.line(img,(x1,y),(x1-l,y), (255, 0, 255), t)
        cv2.line(img,(x1,y),(x1,y+l), (255, 0, 255), t)
        
        #bold bottom left corner
        cv2.line(img,(x,y1),(x+l,y1), (255, 0, 255), t)
        cv2.line(img,(x,y1),(x,y1-l), (255, 0, 255), t)
        
        #bold bottom right corner
        cv2.line(img,(x1,y1),(x1-l,y1), (255, 0, 255), t)
        cv2.line(img,(x1,y1),(x1,y1-l), (255, 0, 255), t)
        return img
    
    # calculate fps
    def calc_fps(self):
        self.cTime = time.time()
        fps = 1 / (self.cTime - self.pTime)
        self.pTime = self.cTime
        return fps


if __name__ == "__main__":
    # initialize camera
    cap = cv2.VideoCapture("video.mp4")
    detector = FaceDetector(0.75, True)

    while True:
        success, img = cap.read()

        detector.detect_face(img)
        lm_list = detector.findPosition(img)
        if len(lm_list) > 0:
            print(lm_list[0])

        # draw the fps
        cv2.putText(img, str(round(detector.calc_fps())), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)

        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(10)