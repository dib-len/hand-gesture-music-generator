# HackDay #19 - Hand Gesture Music Generator

Using AI to pick up hand gestures which will then be translated into different sounds!
Unfortunately, we were unable to finish connecting both sides so we have to separate parts of this project, though both seem to work on their own! :)
 
On the AI side of things, OpenCV (cv2) was used to access webcam feed and then we used MediaPipe to read each frame to track the hand. To figure out the finger “openness” level in the ranges of 0.0 and 1.0 some basic math and logic was used to determine that we would have to normalise the finger length by dividing it by a reference hand size, which is the distance between the middle finger “base” (MCP) and the wrist in this case.

I’ve attached my sketches for this below which helped me visualise this better, though if this also helps you understand this in any way please pat yourself on the back.

<img width="590" alt="Sketch" src="https://github.com/user-attachments/assets/17479d05-076d-44b8-8952-5c65ac953685">
<br><br>

Here is an example of the hand tracking in motion:

<img width="590" alt="Thumbs up!" src="https://github.com/user-attachments/assets/fb924f4b-fc0f-422e-8694-5bc2f62939df">
<br><br>
These data values of “finger openness” were then stored as a JSON which were then meant to be opened and read live and turned into sound. I am aware JSON is probably not the best choice for real-time applications, but it was simple enough to use for this project given the time limitations!
