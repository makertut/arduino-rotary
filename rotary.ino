// defines pins numbers

const int stepPin = 5;

const int dirPin = 2;

const int enPin = 8;

//

int val;

int encoder0PinA = 3;

int encoder0PinB = 4;

int encoder0Pos = 0;

int encoder0PinALast = LOW;

int n = LOW;

int maxKnob = 20;

int stepperSpeed = 2000;

int maxSpeed     = 600;

int minSpeed     = 2000;



void setup() {



  Serial.begin(9600);



  pinMode (encoder0PinA, INPUT);

  pinMode (encoder0PinB, INPUT);



  // Sets the two pins as Outputs

  pinMode(stepPin,OUTPUT);

  pinMode(dirPin,OUTPUT);



  pinMode(enPin,OUTPUT);

  digitalWrite(enPin,LOW);



  // Set Dir to Home switch

  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction





}

void loop() {



        motorStep(1);



    getKnob();



}

void motorStep( int MAX){



   for(int x = 0; x < MAX; x++) {

        digitalWrite(stepPin,HIGH);

        delayMicroseconds(stepperSpeed);

        digitalWrite(stepPin,LOW);

        delayMicroseconds(stepperSpeed);

      }

   

}

void getKnob(){

     n = digitalRead(encoder0PinA);

  if ((encoder0PinALast == LOW) && (n == HIGH)) {

    if (digitalRead(encoder0PinB) == LOW) {

      encoder0Pos--;

    } else {

      encoder0Pos++;

    }

    if( encoder0Pos > maxKnob ){

         encoder0Pos = maxKnob;

    }

    else if( encoder0Pos < 0 ){

         encoder0Pos = 0;

    }



    int r= encoder0Pos * 100;



    r = minSpeed - r;

    r = (r < maxSpeed)?maxSpeed : r;



    stepperSpeed = r;

 

   // Serial.print (encoder0Pos);

  //  Serial.println();



    Serial.println ( r );

  }

  encoder0PinALast = n;

}
