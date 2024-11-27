import cv2
import mediapipe as mp

cap = cv2.VideoCapture(0)

mp_hands = mp.solutions.hands.Hands(min_detection_confidence=0.7, min_tracking_confidence=0.5)
mp_drawing = mp.solutions.drawing_utils

def calculate_finger_openness(hand_landmarks):
    finger_mapping = {
        "thumb": (hand_landmarks[4], hand_landmarks[2]),
        "index": (hand_landmarks[8], hand_landmarks[5]),
        "middle": (hand_landmarks[12], hand_landmarks[9]),
        "ring": (hand_landmarks[16], hand_landmarks[13]),
        "pinky": (hand_landmarks[20], hand_landmarks[17])
    }

    finger_openness_mapping = {}

    wrist = hand_landmarks[0]
    middle_finger_base = hand_landmarks[9]
    hand_size = ((middle_finger_base.x - wrist.x) ** 2 + (middle_finger_base.y - wrist.y) ** 2) ** 0.5
    
    for finger, (finger_tip, finger_base) in finger_mapping.items():
        finger_distance = ((finger_tip.x - finger_base.x) ** 2 + (finger_tip.y - finger_base.y) ** 2) ** 0.5
        finger_openness_mapping[finger] = min(finger_distance / hand_size, 1.0)

    return finger_openness_mapping

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    convert_to_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = mp_hands.process(convert_to_rgb)

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            finger_openness = calculate_finger_openness(hand_landmarks.landmark)
            mp_drawing.draw_landmarks(frame, hand_landmarks, mp.solutions.hands.HAND_CONNECTIONS)

    cv2.imshow("Webcam Feed", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()