#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;

const int servoPin = 9;
const int backButtonPin = A0;
const int upButtonPin = A1;
const int downButtonPin = A2;
const int doorButtonPin = A3;
const int acceptButtonPin = A4;

int selectedHours = 1;
boolean timeSet = false;
boolean menuRequested = true;
boolean doorOpen = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Set Time (hrs)");

  pinMode(backButtonPin, INPUT_PULLUP);
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
  pinMode(doorButtonPin, INPUT_PULLUP);
  pinMode(acceptButtonPin, INPUT_PULLUP);

  servo.attach(servoPin);
  servo.write(0); // Set the servo to 0 degrees initially
  servo.detach();
}

void loop() {
  if (menuRequested) {
    // Show the initial menu and wait for the user to set the time
    lcd.clear();
    lcd.print("Set Time (hrs)");
    lcd.setCursor(0, 1);
    lcd.print(selectedHours);
    timeSet = false;

    while (menuRequested) {
      // Check if the up button is pressed
      if (digitalRead(upButtonPin) == LOW) {
        selectedHours++;
        if (selectedHours > 12) {
          selectedHours = 1;
        }
        lcd.setCursor(0, 1);
        lcd.print("  ");
        lcd.setCursor(0, 1);
        lcd.print(selectedHours);
        delay(200); // Button debounce delay
      }

      // Check if the down button is pressed
      if (digitalRead(downButtonPin) == LOW) {
        selectedHours--;
        if (selectedHours < 1) {
          selectedHours = 12;
        }
        lcd.setCursor(0, 1);
        lcd.print("  ");
        lcd.setCursor(0, 1);
        lcd.print(selectedHours);
        delay(200); // Button debounce delay
      }

      // Check if the accept button is pressed
      if (digitalRead(acceptButtonPin) == LOW) {
        menuRequested = false;
        lcd.clear();
        lcd.print("Countdown");
        delay(500); // Button debounce delay
      }
    }
  }

  // Start the countdown
  unsigned long startTime = millis();
  while (millis() - startTime < selectedHours *3600000) {
    // Check if the back button is pressed
    if (digitalRead(backButtonPin) == LOW) {
      menuRequested = true;
      break;
    }
     // Check if the door button is pressed
    if (digitalRead(doorButtonPin) == LOW) {
      if (doorOpen) {
        servo.attach(servoPin);
        servo.write(0); // Close the door
        delay(500); // Button debounce delay
        doorOpen = false;
        servo.detach(); // Detach the servo
      } else {
        servo.attach(servoPin); // Attach the servo
        servo.write(180); // Open the door
        delay(500); // Button debounce delay
        servo.detach();
        doorOpen = true;
      }
    }
  }

  if (!menuRequested) {
    // Perform the servo movement
    servo.attach(servoPin);
    servo.write(120);
    delay(500); // Move servo to 150 degrees for 3 seconds
    servo.write(0);
    delay(500); // Pause at 0 degrees for 0.5 seconds
    servo.detach();

    menuRequested = true;
  }
}
