int lightbulb = 2;
int pir = 7; 
int led = 3;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(pir, INPUT);
  pinMode(led , OUTPUT);
  pinMode(lightbulb , OUTPUT);
}

void loop()
{
   int val = digitalRead(pir);
    Serial.println(val);
  
  
    if (val == HIGH){
    digitalWrite(led,HIGH);
    digitalWrite(lightbulb, HIGH);
    }
  
  
    else {
    digitalWrite(led,LOW);
    digitalWrite(lightbulb,LOW);
  }    
  
}
