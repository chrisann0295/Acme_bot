/*  Arduino DC Motor Control - PWM | H-Bridge | L298N
         Example 02 - Arduino Robot Car Control
    by Dejan Nedelkovski, www.HowToMechatronics.com
*/
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
int LeftMotorSpeed = 0;
int RightMotorSpeed = 0;
void setup() {
  Serial.print("Hellow world");
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void loop() {
  int xAxis = analogRead(A0); // Read Joysticks X-axis
  int yAxis = analogRead(A1); // Read Joysticks Y-axis
  
  // Y-axis used for forward and backward control
  // MOVE BACKWARD 
  if (yAxis < 470) {
    // Set Motor A backward
    // Setting In1 and In3 to HIGH: direction backward
    digitalWrite(in1, HIGH);
    

    // Setting In2 and In4 to LOW: direction backward
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    // MAPPING:
    // 470 --> 0
    // 0   --> 255
    LeftMotorSpeed = map(yAxis, 470, 0, 0, 255);
    RightMotorSpeed = map(yAxis, 470, 0, 0, 255);
  }
//
//  // MOVE FORWARD
//  else if (yAxis > 550) {
//    // Set Motor A forward
//    // Setting In1 and In3 to LOW: direction forward
//    digitalWrite(in1, LOW);
//    digitalWrite(in3, LOW);
//    
//    // Setting In2 and In4 to HIGH: direction forward
//    digitalWrite(in2, HIGH);
//    digitalWrite(in4, HIGH);
//
//    // MOTOR SPEEDS
//    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
//    // MAPPING
//    // 550  --> 0
//    // 1023 --> 255
//    LeftMotorSpeed = map(yAxis, 550, 1023, 0, 255);
//    RightMotorSpeed = map(yAxis, 550, 1023, 0, 255);
//  }
//
//  // STAY
//  // If joystick stays in middle the motors are not moving
//  else {
//    LeftMotorSpeed = 0;
//    RightMotorSpeed = 0;
//  }
//
//  // TURNING
//  // X-axis used for left and right control
//  // TURN LEFT
//  if (xAxis < 470) {
//
//    // TO TURN LEFT: Left motor backward, Right motor forward
//    // Set Motor Left backward
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//
//    // Set Right Motor forward    
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);
//
//    // MOTOR SPEEDS
//    // Convert the declining X-axis readings from 470 to 0 into increasing 0 to 255 value
//    // MAPPING
//    // 470  --> 0
//    // 0    --> 255
//    LeftMotorSpeed = map(xAxis, 470, 0, 0, 255);
//    RightMotorSpeed = map(xAxis, 470, 0, 0, 255);
//
//    
//              //int xMapped = map(xAxis, 470, 0, 0, 255);
//              // TO MOVE LEFT: decrease left motor speed, increase right motor speed
//              //    LeftMotorSpeed = LeftMotorSpeed - xMapped;
//              //    RightMotorSpeed = RightMotorSpeed + xMapped;
//              // Confine the range from 0 to 255
//              //    if (LeftMotorSpeed < 0) {
//              //      LeftMotorSpeed = 0;
//              //    }
//              //    if (RightMotorSpeed > 255) {
//              //      RightMotorSpeed = 255;
//              //    }
//  }
//  // TURN RIGHT
//  if (xAxis > 550) {
//    // TO TURN RIGHT: Right motor backward, Left motor forward
//    // Set Right motor backward
//    digitalWrite(in3, LOW);
//    digitalWrite(in4, HIGH);
//
//    // Set Left motor forward
//    digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//
//    LeftMotorSpeed = map(xAxis, 550, 1023, 0, 255);
//    RightMotorSpeed = map(xAxis, 550, 1023, 0, 255);
//
//
//    // ===================================== OLD CODE ==========================
//        //      Convert the increasing X-axis readings from 550 to 1023 into 0 to 255 value
//        //      int xMapped = map(xAxis, 550, 1023, 0, 255);
//        //      // Move right - decrease right motor speed, increase left motor speed
//        //      LeftMotorSpeed = LeftMotorSpeed + xMapped;
//        //      RightMotorSpeed = RightMotorSpeed - xMapped;
//        //      // Confine the range from 0 to 255
//        //      if (LeftMotorSpeed > 255) {
//        //        LeftMotorSpeed = 255;
//        //      }
//        //      if (RightMotorSpeed < 0) {
//        //        RightMotorSpeed = 0;
//        //      }
//    // =========================================================================
//  }
//
      //   OPTIONAL (ONLY IF MOTOR DOESNT WORK)
      //   Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
  if (LeftMotorSpeed < 100) {
    LeftMotorSpeed = 0;
  }
  if (RightMotorSpeed < 100) {
      RightMotorSpeed = 0;
  }
//  analogWrite(enA, LeftMotorSpeed); // Send PWM signal to motor A
//  analogWrite(enB, RightMotorSpeed); // Send PWM signal to motor B
}
