import cv2
import numpy as np
from ultralytics import YOLO
import time

# Load YOLOv8 Model (Use yolov8n.pt for fastest speed)
model = YOLO("yolov8n.pt")

# Mobile Camera URL (Use MJPEG stream for better speed)
video_url = "http://192.168.137.185:8080/shot.jpg"  # Faster than /video

# Frame skipping to improve speed
frame_skip = 2  # Process every 3rd frame
frame_count = 0

while True:
    start_time = time.time()  # Track FPS

    # Capture frame from mobile camera
    cap = cv2.VideoCapture(video_url)
    ret, frame = cap.read()
    if not ret:
        continue  # Skip if frame not received

    frame_count += 1
    if frame_count % frame_skip != 0:  
        continue  # Skip processing every 2 frames to speed up

    # Resize frame for faster processing
    frame = cv2.resize(frame, (640, 480))  

    # Run YOLOv8 on the frame
    results = model(frame, conf=0.5)  # Set confidence threshold

    # Draw bounding boxes
    for result in results:
        for box in result.boxes:
            cls = int(box.cls[0])  # Class index
            conf = float(box.conf[0])  # Confidence score

            # Get bounding box coordinates
            x1, y1, x2, y2 = map(int, box.xyxy[0])

            # COCO class 0 = "Person"
            if cls == 0 and conf > 0.5:  
                label = f"Human {conf:.2f}"
                color = (0, 255, 0)  

                # Draw bounding box and label
                cv2.rectangle(frame, (x1, y1), (x2, y2), color, 2)
                cv2.putText(frame, label, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

    # Calculate FPS
    fps = 1 / (time.time() - start_time)
    cv2.putText(frame, f"FPS: {fps:.2f}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)

    # Show the video
    cv2.imshow("YOLOv8 Human Detection (Optimized)", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):  # Press 'q' to exit
        break

cap.release()
cv2.destroyAllWindows()
