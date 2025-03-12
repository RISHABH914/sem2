import cv2
import tensorflow as tf
import numpy as np

# Load trained model
model = tf.keras.models.load_model("human_animal_model.h5")

# Define video stream source (Mobile Camera via IP Webcam)
video_url = "http://192.168.137.185:8080/video"
cap = cv2.VideoCapture(video_url)

# Function to preprocess frames
def preprocess_frame(frame):
    frame = cv2.resize(frame, (224, 224))
    frame = np.expand_dims(frame, axis=0) / 255.0
    return frame

while True:
    ret, frame = cap.read()
    if not ret:
        break

    processed_frame = preprocess_frame(frame)
    prediction = model.predict(processed_frame)[0]

    # Assuming the model output is [Human_Probability, Animal_Probability]
    human_prob = prediction[0] * 100  # Convert to percentage
    animal_prob = prediction[1] * 100

    label = "Human" if human_prob > animal_prob else "Animal"
    confidence = max(human_prob, animal_prob)

    # Display classification and confidence
    text = f"{label}: {confidence:.2f}%"
    cv2.putText(frame, text, (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    cv2.imshow("Human vs. Animal Detection", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):  # Press 'q' to exit
        break

cap.release()
cv2.destroyAllWindows()
