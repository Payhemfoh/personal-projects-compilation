import cv2
import time
from face_detection_module import FaceDetector
from face_mesh_detection_module import FaceMeshDetector

if __name__ == '__main__':
    cap = cv2.VideoCapture("video.mp4")
    face_detector = FaceDetector(0.75, True)
    face_mesh_detector = FaceMeshDetector(False, 1, True)
    
    cTime = time.time()
    pTime = time.time()
    while cap.isOpened():
        success, img = cap.read()
        
        if not success:
            continue
        
        #detect faces appear in the frame
        face_detector.detect_face(img)
        landmark_list = face_detector.findPosition(img)
        
        for i, face in landmark_list:
            #crop the image
            img_cropped = img[face[1]:face[1]+face[3],  face[0]:face[0]+face[2]]
            
            #feed the cropped image to the face mesh detector
            face_mesh_detector.detect_face(img_cropped)
            
            img[face[1]:face[1]+face[3],  face[0]:face[0]+face[2]] = img_cropped
            
        
        # calculate fps
        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime
        
        # draw the fps
        cv2.putText(img, str(round(fps)), (10, 100), cv2.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)
        
        # show the final image
        cv2.imshow("Webcam", img)
        cv2.waitKey(10)