#include <LiquidCrystal.h>
const int rs =8, en =9, d4 =10, d5 =11, d6 =12, d7 =13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Wire.h>
#include "MAX30105.h"
MAX30105 particleSensor;
#define debug Serial

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX,TX

int buz=7;

char b;
char a;

void setup()
{  
  pinMode(buz,OUTPUT);
  digitalWrite(buz,0);
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("WELCOME, Place");
  lcd.setCursor(0,1);
  lcd.println("Finger on sensor");
  debug.begin(9600);
  debug.println("MAX30105 Basic Readings Example");

  // Initialize sensor
  if (particleSensor.begin() == false)
  {
    debug.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  particleSensor.setup(); //Configure sensor. Use 6.4mA for LED drive

  mySerial.begin(9600);

  Serial.println("1. 0-20");
  Serial.println("2. 21-65");
  Serial.println("3. 65 ABOVE");

  while (Serial.available()== 0) {} // wait for user input
    a = Serial.read(); // read the incoming character

    Serial.println("1. BEFORE FOOD");
    Serial.println("2. AFTER FOOD");
  
}

void loop()
{
  // debug.print(" R[");
  // debug.print(particleSensor.getRed());
  // debug.print("] IR[");
  // debug.print(particleSensor.getIR());
  // debug.print("] G[");
  // debug.print(particleSensor.getGreen());
  // debug.print("]");
  // debug.println();
  while (Serial.available()== 0) {} // wait for user input
      b = Serial.read(); // read the incoming character
      lcd.clear();
      lcd.setCursor(0,0);
  
  if(a == '1' && b =='1'){
    
    lcd.println("enter into before food");
    if(particleSensor.getIR()>100000 && particleSensor.getIR()<=125000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("PRE DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" PRE DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();

    }
    else if(particleSensor.getIR()>125000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>70000 && particleSensor.getIR()<100000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println( " NORMAL DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()<70000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("LOW DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" LOW DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else
    {
      digitalWrite(buz,0);
      
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
    }
  }

 

  if(a =='1' && b == '2'){
     if(particleSensor.getIR()>140000 && particleSensor.getIR()<=200000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("PRE DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" PRE DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>200000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>100000 && particleSensor.getIR()<140000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()<100000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("LOW DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" LOW DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else
    {
      digitalWrite(buz,0);
      
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
    }
  }

  

  if(a == '2' && b == '1'){
    if(particleSensor.getIR()>100000 && particleSensor.getIR()<=130000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("PRE DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" PRE DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>130000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>80000 && particleSensor.getIR()<100000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }


    else if(particleSensor.getIR()<80000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("LOW DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" LOW DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
 else
    {
      digitalWrite(buz,0);
      
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
    }

   

  }
  if(a == '2' && b == '2'){
    if(particleSensor.getIR()>140000 && particleSensor.getIR()<=200000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("PRE DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" PRE DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>200000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>100000 && particleSensor.getIR()<140000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()<100000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("LOW DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" LOW DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else
    {
      digitalWrite(buz,0);
      
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
    }
  }
  
 

  if(a == '3' && b == '1'){
    if(particleSensor.getIR()>130000 && particleSensor.getIR()<=180000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("PRE DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" PRE DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>180000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>80000 && particleSensor.getIR()<130000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()<80000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("LOW DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" LOW DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else
    {
      digitalWrite(buz,0);
      
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
    }
  }

 

  if(a == '3' && b == '2'){
    if(particleSensor.getIR()>160000 && particleSensor.getIR()<=200000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("PRE DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" PRE DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>200000)
    {
      digitalWrite(buz,1);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("DIABETIC");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" DIABETIC");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()>90000 && particleSensor.getIR()<160000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else if(particleSensor.getIR()<90000)
    {
      digitalWrite(buz,0);
      lcd.setCursor(0,0);
      lcd.print("IR:" + String(particleSensor.getIR()/1000.0));
      lcd.print(" mg/dl");
    delay(150);
      lcd.setCursor(0,1);
      lcd.print("LOW DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" LOW DIABETES");
       delay(10000);
 digitalWrite(buz,0);
      lcd.clear();
    }
    else
    {
      digitalWrite(buz,0);
      
      lcd.setCursor(0,1);
      lcd.print("NORMAL DIABETES");
      mySerial.print("IR:" + String(particleSensor.getIR()/1000.0));
      mySerial.println(" NORMAL DIABETES");
    }
  }

  // else if( a == ' ' || b == ' ')
  // {
  //   lcd.setCursor(0,1);
  //   lcd.print("Enter response");
  // }

  else if(( a == '4' || '5' || '6' || '7' || '8' || '9' || '0') || 
            ( b == '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0' ))
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Invalid Input");

  }


  else{
    lcd.setCursor(0,1);
    lcd.print("Enter response");
  }
}