int M1driverPUL = 12;    // motor1 Pulse pin
int M1driverDIR = 11;    // motor1 Direection pin


int M2driverPUL = 10;    // motor2 Pulse pin
int M2driverDIR = 9;    // motor2 Direection pin


char c;
int i,j,k,l;
int full_cycle=400;
int half_cycle=200;
int stepsPerTurn = 200;
int RPM = 160;
float stepsPerSecond = (stepsPerTurn*RPM)/60;
float waitInMilliseconds = (1/stepsPerSecond)*1000;

void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode (M1driverPUL, OUTPUT);
  pinMode (M1driverDIR, OUTPUT);
  pinMode (M2driverPUL, OUTPUT);
  pinMode (M2driverDIR, OUTPUT);
  Serial.println("motor state:initialize");
  delay(200);
  
}

void loop() {
 //motor loop for X-axis direction 

  while (Serial.available() > 0)
  c = Serial.read();
  {
    if (c=='L')
    {
    Serial.println("motor state:left");
    digitalWrite(M1driverDIR,LOW);
    for(i=0;i<full_cycle;i++)
    {
    digitalWrite(M1driverPUL,HIGH);
    delay(waitInMilliseconds);
    digitalWrite(M1driverPUL,LOW);
    delay(waitInMilliseconds);
    }
    }
      else if (c=='R')
          {
          Serial.println("motor state:right");
          digitalWrite(M1driverDIR,HIGH);
          for(j=0;j<full_cycle;j++)
          {
          digitalWrite(M1driverPUL,HIGH);
          delay(waitInMilliseconds);
          digitalWrite(M1driverPUL,LOW);
          delay(waitInMilliseconds);
          }
           }
//motor loop for Y-axis direction 
             else if (c=='U')
              { Serial.println("motor state:up");
                digitalWrite(M2driverDIR,HIGH);
                for(k=0;k<full_cycle;k++)
                {
                digitalWrite(M2driverPUL,HIGH);
                delay(waitInMilliseconds);
                digitalWrite(M2driverPUL,LOW);
                delay(waitInMilliseconds);
                }
              }   
                    else if (c=='D')
                    { 
                      Serial.println("motor state:down");  
                      digitalWrite(M2driverDIR,LOW);
                      for(l=0;l<full_cycle;l++)
                      {
                      digitalWrite(M2driverPUL,HIGH);
                      delay(waitInMilliseconds);
                      digitalWrite(M2driverPUL,LOW);
                      delay(waitInMilliseconds);
                      }
                    }   
}
}
