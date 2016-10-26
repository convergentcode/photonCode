// connect LEDs to digital pins
int RED = D2;              // LED connected to D1
int BLU = D1;  
int GRN = D0;  

//analog 0 is the "wiper" on a potentiometer
//analog 1 is the CDS photo sensor
int POT = A0;
int CDS = A1;
int potVal = 0;
int lightVal = 0;
int delayVal = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("Hello World!");  
  pinMode(RED, OUTPUT);    // sets pin as output
  pinMode(BLU, OUTPUT);    // sets pin as output
  pinMode(GRN, OUTPUT);    // sets pin as output
}

void loop()
{
// if we were using the potentiometer, we could set delayVal based
// on the varying voltage we get when we twist the knob
  delayVal = analogRead(POT);
  Serial.println(delayVal);

// let's use the value of a photosensor 
// connect one lead to 3v3, the other lead to a 10K resistor/analog1
// other end of the 10K resistor to ground
// small voltage changes happen at A1 when light changes


  lightVal = analogRead(CDS);


// print value to serial monitor so we can look at it
// divide large number by 20 to get a good delay value
  Serial.println(lightVal);
  delayVal = lightVal/20;

// blink LEDs in sequence based on delay value
// faster when darker?  slower when there is more light

  digitalWrite(RED, HIGH); // sets the LED on
  delay(delayVal);              // waits for 200mS
  digitalWrite(RED, LOW);  // sets the LED off
  delay(delayVal);              // waits for 200mS
  digitalWrite(BLU, HIGH); // sets the LED on
  delay(delayVal);              // waits for 200mS
  digitalWrite(BLU, LOW);  // sets the LED off
  delay(delayVal);              // waits for 200mS
  digitalWrite(GRN, HIGH); // sets the LED on
  delay(delayVal);              // waits for 200mS
  digitalWrite(GRN, LOW);  // sets the LED off
  delay(delayVal);              // waits for 200mS
}