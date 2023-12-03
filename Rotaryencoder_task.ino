#include<Servo.h>
//Rotary encoder inputs

#define inputCLK 4
#define inputDT 5

//Create a Servo object

Servo myservo;

int counter=0;
int currentStateCLK;
int previousStateCLK;

void setup() {
  // set encoder pins as inputs
  pinMode(inputCLK,INPUT);
  pinMode(inputDT,INPUT);
  //setup Serial Monitor
  Serial.begin(9600);

  //Attach servo on pin 9 to the servo object
  myservo.attach(9);

  //Read the initial state of inputCLK
  //Assign to previousStateCLK variable
  previousStateCLK=digitalRead(inputCLK);
 
}

void loop() {
  // Read the current state of inputCLK
  currentStateCLK=digitalRead(inputCLK);

  // If the previous and current state of the inputCLk are different,then pulse generated

  if(currentStateCLK!=previousStateCLK && currentStateCLK==1)
  {
    //the encoder is rotating counterclockwise ifDT!=CLK
    if(digitalRead(inputDT) !=currentStateCLK)
    {
      counter--;
      if(counter<0)
      {
        counter=0;
      }
    }
  
  else
  {
    //Encoder is rotating clockwise
    counter++;
    if(counter>180)
    {
      counter=180;
    }
  }
}
  //Move the servo
  myservo.write(counter);
  Serial.print("Position: ");
  Serial.println(counter);
  //update previousStateCLK with the current state
  previousStateCLK=currentStateCLK;
}
