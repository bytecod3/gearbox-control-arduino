/**
 * Author: Edwin Mwiti Maingi
 * Email: emwiti658@gmail.com
 * Date: 31st October 2023
 */


// speed definitions
#define MIN_ANALOG_VAL 0
#define MAX_ANALOG_VAL 255

#define MIN_A_SPEED 0  // gear 1
#define MAX_A_SPEED 51

#define MIN_B_SPEED 52 // gear 2
#define MAX_B_SPEED 103

#define MIN_C_SPEED 104 // gear 3
#define MAX_C_SPEED 155

#define MIN_D_SPEED 156 //gear 4
#define MAX_D_SPEED 207

#define MIN_E_SPEED 208 // gear 5
#define MAX_E_SPEED 255

#define MOTOR_OFF 0

// set up reverse

// pins
int motor_pin = A2; // pin connected to motor
int potentiometer_pin = A3; // sensor to control speed - ranges from 0 -255
String gear = ""; // gears-> 1,2,3,4,5, R
int converted_speed = 0; // ranges depending on the set Gear
int analog_value = 0; // value read from "sensor to control speed"

// timing variables 
unsigned long current_time = 0, previous_time = 0; 
unsigned long interval = 600;

void setup() {
  // pinmodes
  pinMode(motor_pin, OUTPUT);
  pinMode(potentiometer_pin, INPUT);

  // set up bluetooth stuff....
  
}

void loop() {

  current_time = millis();

  if(current_time - previous_time >= interval){
  
      
    // check data from serial - bluetooth data
    if (Serial.available() > 0){
      gear = Serial.read();
    }
  
    // set speed depending on the gear received from bluetooth
    analog_value = analogRead(potentiometer_pin);
  
    switch(gear){
      case "A":
        // speed can range 0 - 51 
        converted_speed = map(analog_value, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_A_SPEED, MAX_A_SPEED);
        analogWrite(motor_pin, converted_speed);
  
        break;
  
       case "B":
        
        converted_speed = map(analog_value, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_B_SPEED, MAX_B_SPEED);
        analogWrite(motor_pin, converted_speed);
  
        break;
  
       case "C":
        converted_speed = map(analog_value, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_C_SPEED, MAX_C_SPEED);
        analogWrite(motor_pin, converted_speed);
  
        break;
  
       case "D":
        converted_speed = map(analog_value, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_D_SPEED, MAX_D_SPEED);
        analogWrite(motor_pin, converted_speed);
  
        break;
  
       case "E":
        converted_speed = map(analog_value, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_E_SPEED, MAX_E_SPEED);
        analogWrite(motor_pin, converted_speed);
  
        break;
  
      default:
        analogWrite(motor_pin, MOTOR_OFF)
    }
  
    previous_time = current_time; // update time
  }

  
}
