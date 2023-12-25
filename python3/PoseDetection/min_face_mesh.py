import cv2
import mediapipe as mp
import time

if __name__ == '__main__':
    # initialize camera
    cap = cv2.VideoCapture("video.mp4")
    
    mpFaceMesh = mp.solutions.face_mesh
    mpDraw = mp.solutions.drawing_utils
    faceMesh = mpFaceMesh.FaceMesh()
    drawSpec = mpDraw.DrawingSpec(thickness=1, circle_radius=2)
    
    
    cTime = time.time()
    pTime = time.time()
    while True:
        success, img = cap.read()
        
         # convert image and send to process to detect face
        imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        results = faceMesh.process(imgRGB)
        
        # draw detected faces
        if results.multi_face_landmarks:
            for id, face_landmark in enumerate(results.multi_face_landmarks):
                #mpDraw.draw_detection(img, detection)
                mpDraw.draw_landmarks(img, face_landmark, mpFaceMesh.FACEMESH_CONTOURS, drawSpec, drawSpec)
                """
                bBoxC = detection.location_data.relative_bounding_box
                iH, iW, iC = img.shape
                bBox = int(bBoxC.xmin * iW), int(bBoxC.ymin * iH),\
                    int(bBoxC.width * iW), int(bBoxC.height * iH)
                cv2.rectangle(img, bBox, (255, 0, 255), 2)
                cv2.putText(img, str(round(detection.score[0]*100)), (bBox[0], bBox[1]-20), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)"""
        
        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        
        # draw the fps
        cv2.putText(img, str(round(fps)), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)
        
        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(10)