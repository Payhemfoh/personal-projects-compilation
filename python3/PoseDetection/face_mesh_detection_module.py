import cv2
import mediapipe as mp
import time

class FaceMeshDetector:
    #initialize face tracking model
    def __init__(self, static_mode=False, maxFaces=2, refine_landmark=False, min_detect_confidence=0.5, min_tracking_confidence=0.5):
        self.mpFaceMesh = mp.solutions.face_mesh
        self.mpDraw = mp.solutions.drawing_utils
        self.faceMesh = self.mpFaceMesh.FaceMesh(static_mode, maxFaces, refine_landmark, min_detect_confidence, min_tracking_confidence)
        self.drawSpec = self.mpDraw.DrawingSpec(thickness=1, circle_radius=1)
        self.results = None

        # variables to track frame rate
        self.pTime = time.time()
        self.cTime = time.time()
    
    def detect_face(self, img, draw=True):
        # convert image and send to process to detect hand
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        self.results = self.faceMesh.process(imgRGB)

        # draw tracked hand pose
        if draw:
            if self.results and self.results.multi_face_landmarks:
                for landmark in self.results.multi_face_landmarks:
                    self.mpDraw.draw_landmarks(img, landmark, self.mpFaceMesh.FACEMESH_CONTOURS, self.drawSpec, self.drawSpec)

    def findPosition(self, img, face_no=0, draw=True):
        landmark_list = []

        # draw tracked hand pose
        if self.results.multi_face_landmarks:
            face = self.results.multi_face_landmarks[face_no]

            # display information for landmarks of hand detected
            for id, lm in enumerate(face.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)
            landmark_list.append(face)

        return landmark_list

    
    # calculate fps
    def calc_fps(self):
        self.cTime = time.time()
        fps = 1 / (self.cTime - self.pTime)
        self.pTime = self.cTime
        return fps


if __name__ == "__main__":
    # initialize camera
    cap = cv2.VideoCapture("video.mp4")
    detector = FaceMeshDetector()

    while True:
        success, img = cap.read()

        detector.detect_face(img)
        lm_list = detector.findPosition(img)
        if len(lm_list) > 0:
            print(len(lm_list))

        # draw the fps
        cv2.putText(img, str(round(detector.calc_fps())), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)

        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(10)