#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#include <Servo.h>



#define DirectionPin  (10u)

#define BaudRate      (1000000ul)

#define ID            (1u)



char auth[] = "HQPNZxPXef9xKPu70TIh5zQmfVu5Yl0N";

char ssid[] = "Rik";

char pass[] = "07238314";


int speed = 100;
int i;

Servo servo1; //silen lqv
Servo servo2; //siled desen
Servo servo3; //lqv preden
Servo servo4; //lqv zaden
Servo servo5; //desen preden
Servo servo6; //desen zaden


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  delay(1000); // Give time for Dynamixel to start on power-up 

  servo1.attach(16);
  servo1.write(180);
  servo2.attach(5);
  servo2.write(180);
  servo3.attach(4);
  servo3.write(90);
  servo4.attach(0);
  servo4.write(90);
  servo5.attach(2);
  servo5.write(90);
  servo6.attach(14);
  servo6.write(90);
 }

 /*
  * servo1 180 vdiga paqka
  * servo2 180 vdiga paqka
  * servo3 180 krakata nazad
  * servo4 180 krakata nazad
  * servo5 180 krakata nazad
  * servo6 180 krakata nazad
  */


void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1)
{
   speed = param.asInt();
}

BLYNK_WRITE(V2)
{
  int x = param[0].asInt();
  int y = param[1].asInt();

  if( (y == 0) ){ // turn left
      down();
  }else if( ( y == 1000) ){ // turn right
      up();
  }
}



void up()
{
  servo1.write(0);
  delay(1000);
  servo3.write(0);
  servo6.write(0);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo3.write(90);
  servo6.write(90);
  servo4.write(180);
  servo5.write(180);
  delay(1000);
  servo2.write(0);
  delay(1000);
  servo4.write(0);
  servo5.write(0);
  delay(1000);
  servo2.write(180);
  delay(1000);
  servo4.write(90);
  servo5.write(90);
  servo3.write(180);
  servo6.write(180);
  delay(1000);
}


void down()
{
  servo1.write(0);
  delay(1000);
  servo3.write(180);
  servo6.write(180);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo3.write(90);
  servo6.write(90);
  servo4.write(0);
  servo5.write(0);
  delay(1000);
  servo2.write(0);
  delay(1000);
  servo4.write(180);
  servo5.write(180);
  delay(1000);
  servo2.write(180);
  delay(1000);
  servo4.write(90);
  servo5.write(90);
  servo3.write(0);
  servo6.write(0);
  delay(1000);
}
