

int moisturesensor = 1;
int sensorValue = 0;
#define RED_LED 3
#define PINK_LED 4
#define BLUE_LED 2

int wet = 500;

int moist = 700;

int dry = 900;

void setup() 
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(PINK_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  
}
  
  
void loop() {
  sensorValue = analogRead(1);
  delay(1000);
  Serial.print("sensor=");
  Serial.println(sensorValue);
  writeLEDs();
  
}

void writeLEDs() {
  
  if(sensorValue > dry){
    digitalWrite(RED_LED, HIGH);
   
  }else{
    digitalWrite(RED_LED, LOW);
  }
 
  if(wet < sensorValue && sensorValue < dry){
    digitalWrite(PINK_LED, HIGH);
    
  }else{    
    digitalWrite(PINK_LED, LOW);
  }
  
  if(sensorValue < wet){
    digitalWrite(BLUE_LED, HIGH);
  }else{
    digitalWrite(BLUE_LED, LOW);
  }
}

