/*MotorPower test
 * James Cheatham
 * 20April17
 */

//These set names to drive the two motors on the vehicle  I changed the names from motorPin to drivePin
//the code was pulled from a tutorial on the L293D.  I'm driving the motors from a battery connected to the 
//battery of the r/c donor and I'm powering the chip from the arduino.

//L293D
//Motor A  Not mine
const int drivePin1  = 5;  // Pin 14 of L293
const int drivePin2  = 6;  // Pin 10 of L293
//Motor B  Not mine
const int drivePin3  = 10; // Pin  7 of L293
const int drivePin4  = 9;  // Pin  2 of L293

//Ping sensor settings
const int pingPin = 11;  // pin connected to Echo Pin in the ultrasonic distance sensor
const int trigPin  = 12; // pin connected to trig Pin in the ultrasonic distance sensor

//This will run only one time.
void setup(){
 
    //Set pins as outputs  not my code
    pinMode(drivePin1, OUTPUT);
    pinMode(drivePin2, OUTPUT);
    pinMode(drivePin3, OUTPUT);
    pinMode(drivePin4, OUTPUT);
    
    //sensor setup
    pinMode(pingPin, INPUT); //Set the connection pin output mode Echo pin
    pinMode(trigPin, OUTPUT);//Set the connection pin output mode trog pin
    
    
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4

    //This code  will turn Motor A clockwise for 2 sec.
    forward();
    delay(2000); 
    halt();
    //This code will turn Motor A counter-clockwise for 2 sec.
    backward();
    delay(2000);
    halt();
    //This code will turn Motor B clockwise for 2 sec.
    left();
    delay(2000); 
    strt();
    //This code will turn Motor B counter-clockwise for 2 sec.
    right();
    delay(2000);
    strt();    
    
    //And this code will stop motors
    strt();
    halt();

}


void loop(){
  

}
// This section sets motor controls

//roll forward
void forward(){
  digitalWrite(drivePin1, HIGH);
  digitalWrite(drivePin2, LOW);
}

//roll backward
void backward(){
  digitalWrite(drivePin1, LOW);
  digitalWrite(drivePin2, HIGH);
}

//Stop motion
void halt(){
  digitalWrite(drivePin1, LOW);
  digitalWrite(drivePin2, LOW);
}

//Turn Right
void right(){
  digitalWrite (drivePin3, HIGH);
  digitalWrite (drivePin4, LOW);
}

//Turn Left
void left(){
  digitalWrite (drivePin3, LOW);
  digitalWrite (drivePin4, HIGH);
}

//go straight
void strt(){
  digitalWrite (drivePin3, LOW);
  digitalWrite (drivePin4, LOW);
}
//not my code
int ping(int pingPin) 
{ 
   // establish variables for duration of the ping, 
   // and the distance result in inches and centimeters: 
   long duration, cm; 
   // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. 
   // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 
   pinMode(trigPin, OUTPUT); 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, LOW); 

   pinMode(pingPin, INPUT); 
   duration = pulseIn(pingPin, HIGH); 

   // convert the time into a distance 
   cm = microsecondsToCentimeters(duration); 
   return cm ; 
} 

long microsecondsToCentimeters(long microseconds) 
{ 
   // The speed of sound is 340 m/s or 29 microseconds per centimeter. 
   // The ping travels out and back, so to find the distance of the 
   // object we take half of the distance travelled. 
   return microseconds / 29 / 2; 


