#include <Servo.h>
Servo Pipe_Servo;
Servo Gate_Servo;
// define the variables
int sensorInd = A0; //Pin A0 (analog)
int sensorpin = 2; //Digital Pin nr. 2
int indValue;
int n=0;
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // trigPin=output
pinMode(echoPin, INPUT); // echoPin = input
Serial.begin(9600); // Starts the serial communication
// Codes that run only once[
//--System Initialization--
   Pipe_Pos=Pipe_Servo.read();//Read the last value given to Pipe servo
    Gate_Pos=Gate_Servo.read();//Read the last value given to Pipe servo
   Serial.println("Motor_PIPE Position");
    Serial.println(Pipe_Pos);
    Serial.println("Motor_GATE Position");
    Serial.println(Gate_Pos);
    delay(5000);
   
    Pipe_Servo.attach(11);
   if (Pipe_Pos<90){
     
     for(i=Pipe_Pos; i<=90; i=i+1){
      Pipe_Servo.write(i);
      delay(15);
      }
    }
      
      else {
        for(i=Pipe_Pos; i>=90; i=i-1){
        Pipe_Servo.write(i);
        delay(15); 
      
        }
      }
delay(1000); //Delay (wait) for servo pipe to go to the bin.
   //Next rotate the gate servo.
    //And control the speed of Gate Servo.
    Gate_Servo.attach(10);
    for(n=0; n<=45; n=n+1){  //angleo
      Gate_Servo.write(n);
      delay(20); //Controll the speeed of Gate servo
   }  
   delay(1000); //Delay (wait) and then bring back the Gate_Servo to its
     //initial position.
    //Bring Back Gate_Servo to initial position
     //So from actual position 2-> n=45; we go backwards up to n=0.
    for(n=45; n>=0; n=n-1){ 
      Gate_Servo.write(n);
      delay(25); //Control the speed of Gate servo 
     }
delay(5000);
}
   Serial.println("Motor_PIPE Position");
    Serial.println(Pipe_Pos);
    Serial.println("Motor_GATE Position");
    Serial.println(Gate_Pos);
}
}
