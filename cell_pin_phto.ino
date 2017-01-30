#define cellPin A5
#define LEDPin 3

int maxValue=0, minValue=1023;

void setup() {
  Serial.begin(9600);
  pinMode (LEDPin,OUTPUT);
}

void loop() {
  int cellValue= analogRead(cellPin);
  if (cellValue > maxValue) maxValue = cellValue;
  if (cellValue < minValue) minValue = cellValue;
  
  //cellValue = constrain(cellValue,180,840); //no < 180 && no >840
  int mappedValue = map ( cellValue,minValue,maxValue,0,255);
  Serial.println(cellValue);

  analogWrite (LEDPin, mappedValue);

}
