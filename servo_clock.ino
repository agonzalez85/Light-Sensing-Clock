#include <Servo.h>

/**
  * This Arduino project creates a unique clock that uses a light sensor to determine the time 
  * of day and displays it using a servo motor. The servo positions an arrow to point at "Morning," 
  * "Day," or "Night" based on the ambient light level.
  *
  @author Andy Gonzalez
  @date 4/2023
*/

// Pin definitions
const int SERVO_PIN = 9;
const int LIGHT_SENSOR_PIN = A5;

// Constants
const int SERVO_MIN_ANGLE = 0;
const int SERVO_MAX_ANGLE = 180;
const int LIGHT_MIN_VALUE = 0;
const int LIGHT_MAX_VALUE = 1023;

// Global variables
Servo clockServo;
int lightValue;
int servoPosition;

void setup() 
{
  Serial.begin(9600);
  clockServo.attach(SERVO_PIN);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() 
{
  readLightSensor();
  calculateServoPosition();
  moveServo();
  printDebugInfo();
  delay(500); // Adjust delay as needed for responsiveness
}

void readLightSensor() 
{
  lightValue = analogRead(LIGHT_SENSOR_PIN);
}

void calculateServoPosition()
{
  servoPosition = map(lightValue, LIGHT_MIN_VALUE, LIGHT_MAX_VALUE, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE);
}

void moveServo() 
{
  clockServo.write(servoPosition);
}

void printDebugInfo() 
{
  Serial.print("Light value: ");
  Serial.print(lightValue);
  Serial.print(", Servo position: ");
  Serial.println(servoPosition);
}
