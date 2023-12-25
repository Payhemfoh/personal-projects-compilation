import cv2
import mediapipe as mp
import time

if __name__ == "__main__":
    # initialize camera
    cap = cv2.VideoCapture("video.mp4")

    mpPose = mp.solutions.pose
    pose = mpPose.Pose()
    mpDraw = mp.solutions.drawing_utils

    cTime = time.time()
    pTime = time.time()
    while True:
        success, img = cap.read()
        #img = cv2.flip(img, 1)

        # convert image and send to process to detect hand
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        results = pose.process(imgRGB)

        # draw tracked hand pose
        if results.pose_landmarks:
            mpDraw.draw_landmarks(img, results.pose_landmarks, mpPose.POSE_CONNECTIONS)
            for id, lm in enumerate(results.pose_landmarks.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)
                cv2.circle(img, (cx, cy), 10, (255, 0, 0), cv2.FILLED)

        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime

        # draw the fps
        cv2.putText(img, str(round(fps)), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)

        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(1)