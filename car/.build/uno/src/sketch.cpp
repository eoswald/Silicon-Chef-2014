#include <Arduino.h>

void setup();
void loop();
void forward(int speed);
void reverse(int speed);
#line 1 "src/sketch.ino"
#define TOP_LEFT		 2
#define TOP_RIGHT		 3
#define BOTTOM_LEFT	 4
#define BOTTOM_RIGHT 5
#define PWM_PIN 6

void setup() {
	pinMode(TOP_LEFT, OUTPUT);
	pinMode(TOP_RIGHT, OUTPUT);
	pinMode(BOTTOM_LEFT, OUTPUT);
	pinMode(BOTTOM_RIGHT, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);
}

void loop() {
}

void forward(int speed) {
	digitalWrite(TOP_LEFT, HIGH);
	digitalWrite(TOP_RIGHT, LOW);
	digitalWrite(BOTTOM_LEFT, LOW);
	digitalWrite(BOTTOM_RIGHT, HIGH);
	analogWrite(PWM_PIN, speed);
}

void reverse(int speed) {
	digitalWrite(TOP_LEFT, LOW);
	digitalWrite(TOP_RIGHT, HIGH);
	digitalWrite(BOTTOM_LEFT, HIGH);
	digitalWrite(BOTTOM_RIGHT, LOW);
	analogWrite(PWM_PIN, speed);
}
