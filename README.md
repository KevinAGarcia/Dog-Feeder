# Dog-Feeder

An automatic dog feeder is a device designed to dispense food to your dog at pre-determined intervals or on-demand without requiring your direct involvement. It can be a convenient solution for pet owners who have busy schedules, need to be away from home for extended periods, or want to regulate their dog's feeding schedule more effectively. 

The purpose of this project is to understand how arduino UNO works to perform multiple tasks simultaneously or respond to external events while still maintaining a sense of time. Millis() fucntion is used for implementing non-blocking delays and timing in Arduino sketches. Unlike the delay() function, which pauses the entire program for a specified duration, millis() allows you to create time-dependent behavior without blocking the execution of other tasks.

The elements needed for this project are :

  1 Arduino UNO
  1 Protoboard
  1 LCD DE 16*2
  1 Step motor sg90 
  5 buttons 
  1 potentiometer
  1 bottle


how code works :

 
1. Initialization:
A LiquidCrystal object is initialized for the LCD and a Servo object for the servo motor.
Pins for buttons (backButtonPin, upButtonPin, downButtonPin, doorButtonPin, acceptButtonPin) are set as INPUT_PULLUP, assuming that the buttons are connected to ground and will be pulled up when not pressed.
The servo motor is attached to servoPin and set to the initial position (0 degrees).
  
2. Main Loop:
The main loop consists of two major parts: setting the time and running the countdown.

Setting the Time:

If menuRequested is true, it enters a loop where the user can set the countdown time in hours using the up and down buttons. The selected time is displayed on the LCD.
The menu is exited when the accept button is pressed (digitalRead(acceptButtonPin) == LOW), and it transitions to the countdown display.

3. Countdown:
The countdown begins after the time is set. The loop waits for the specified duration (selectedHours * 3600000) while checking for the back button to return to the time-setting menu or the door button to open/close the door (assuming the servo motor controls a door mechanism).

After the countdown, the servo motor moves to 120 degrees for 0.5 seconds, then returns to 0 degrees for another 0.5 seconds before detaching. This might represent an action like opening and closing a door.

Finally, menuRequested is set to true to restart the process.


How to assemble the prototype: 

![image](https://github.com/kevin343/Dog-Feeder/assets/113644566/9818591f-6eb6-4bd0-b4aa-dffcadd3c579)


Arduino Uno energizes the lcd screen, and the brightness can be regulated with the potentiometer. 

![image](https://github.com/kevin343/Dog-Feeder/assets/113644566/cafff166-d540-4e41-aaca-9feb203a4040)

The step motor is connected to the arduino UNO and the step motor is mounted in a bottle.

![image](https://github.com/kevin343/Dog-Feeder/assets/113644566/5bade602-8f91-4bdf-abb9-636aa2ed6ad4)

In the step motor there is a cap connected to it that opens and closes to release the dog food according to the timer.

[![Watch the video](https://img.youtube.com/vi/<VIDEO_ID>/hqdefault.jpg)](https://drive.google.com/file/d/1GpBfkmbJkDjKbLzO0bZ1dHtq154fZY8U/view?usp=drive_link)



[<img src="https://img.youtube.com/vi/<VIDEO_ID>/hqdefault.jpg" width="600" height="300"
/>](https://www.youtube.com/embed/<VIDEO_ID>)











