const int TriggerPin1 = 11;
const int EchoPin1 = 10;
const int TriggerPin2 = 6;
const int EchoPin2 = 5; 

long duration;
int distance1, distance2;
float r;
unsigned long temp=0;
int temp1=0;
int l=0;

void calculate_dist (void);
void calculate_dist (void)
{
  digitalWrite(TriggerPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin1, LOW);

  duration = pulseIn(EchoPin1,HIGH,5000);
  r = 3.4*duration/2;
  distance1 = r/100.00;

  digitalWrite(TriggerPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin2, LOW);

  duration = pulseIn(EchoPin2,HIGH,5000);
  r = 3.4*duration/2;
  distance2 = r/100.00;

  delay(100);  
}

void setup()
{
  Serial.begin(9600);
  pinMode(TriggerPin1,OUTPUT);
  pinMode(EchoPin1,INPUT);
  pinMode(TriggerPin2,OUTPUT);
  pinMode(EchoPin2,INPUT);
  delay(1000);
}

void loop()
{
  calculate_dist();

  if(distance2>=15 && distance2<=35)
  {
    temp =millis();
    while(millis()<=(temp+300))
    calculate_dist();
    if(distance2>=15 && distance2<=35)
    {
      temp = distance2;
      while(distance2<=50 || distance2==0)
      {
        calculate_dist();
        if((temp+6)<distance2)
        {
          Serial.println("Down");
        }
        else if((temp-6)<distance2)
        {
          Serial.println("Up");
        }
      }
    }
    else
    {
      Serial.println("Play");
    }
  }
  else if(distance1>=15 && distance1<=35)
  {
    temp=millis();
    while(millis()<=(temp+300))
    {
      calculate_dist();
      if(distance2<=35 && distance2>=15)
      {
        Serial.println("Close");
        l=1;
        break;
      }
    }
    if(l==0)
    {
      Serial.println("Change");
      while(distance1>=15 && distance1<=35)
      calculate_dist();
    }
    l=0;
  }
}

