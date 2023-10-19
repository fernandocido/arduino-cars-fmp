 //Code for Arduino remote car

//Motor
#define bCtrl 2  //define the direction control pin of the back motor as 2
#define bPwm 6   //define the PWM control pin of the back motor as 6
#define fCtrl 4 //define the direction of the front motor as 4
#define fPwm 5 //define the PWM control of the front motor as 5

//Bluetooth
char bluetoothValue; //used to save the Bluetooth value

//Movement
void carForward() {
  digitalWrite(bCtrl, LOW);
  analogWrite(bPwm, 255);
}

void carBackwards() {
  digitalWrite(bCtrl, HIGH);
  analogWrite(bPwm, 255);
}

void carRight() {
  digitalWrite(fCtrl, HIGH);
  analogWrite(fPwm, 250);
}

void carLeft() {
  digitalWrite(fCtrl, LOW);
  analogWrite(fPwm, 250);
}

void carStop() {
  digitalWrite(bCtrl, LOW);
  analogWrite(bPwm, 0);
  digitalWrite(fCtrl, LOW);
  analogWrite(fPwm, 0);
}

void setup() {
  // Serial Communication
  Serial.begin(9600); // Set up serial communication at 9600
}

void loop() {
  if (Serial.available()) {
    bluetoothValue = Serial.read();
    Serial.println(bluetoothValue);
    switch (bluetoothValue) {
      case 'F': // Bluetooth command to move 'FORWARD'
        carForward();
        break;
      case 'B': // Bluetooth command to move 'BACKWARDS'
        carBackwards();
        break;
      case 'L': // Bluetooth command to move 'LEFT'
        carLeft();
        break;
      case 'R': // Bluetooth command to move 'RIGHT'
        carRight();
        break;
      default:
        carStop();
        break;
    }
  } 
}
