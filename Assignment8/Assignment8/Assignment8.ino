#include <WiFi.h>
#include <HTTPClient.h>

#include <ESP32Servo.h>
const char* ssid = "Infusion Guest";
const char* password =  "TheBestCoffee";
//int microNumber = 1350;
Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32
int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 22;
int Counter = 0;
void setup() {
  //wifi code
 
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  
  
  // put your setup code here, to run once:
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin); // attaches the servo on pin 18 to the servo object
 // delay(1000);
  if (pos == 0 ){//done
      delay(1000);
      myservo.writeMicroseconds(1500);
  }
  if(pos>1 && pos<20){//done
      int microNumber = 50;
      microNumber = microNumber + pos;
      myservo.writeMicroseconds(microNumber);
      delay(50);
      myservo.writeMicroseconds(1500);
      
    }
    if(pos>21 && pos<40){//done
      int microNumber = 50;
      microNumber = microNumber + pos;
      myservo.writeMicroseconds(microNumber);
      delay(90);
      myservo.writeMicroseconds(1500);
      
      
    }
     if(pos>41 && pos<60){// NEEEDS FIXING 
      int microNumber = 200;
      microNumber = microNumber + pos;
      myservo.writeMicroseconds(microNumber);
      delay(350);
      myservo.writeMicroseconds(1500);
      
    }
     if(pos>71 && pos<80){// DONE Dont mess with
      int microNumber = 200;
      microNumber = microNumber + pos;
      myservo.writeMicroseconds(microNumber);
      delay(120);
      myservo.writeMicroseconds(1500);
      
    }
    
    if(pos>81 && pos <= 99){//Done
      int microNumber = 140;
      microNumber = microNumber + pos;
      myservo.writeMicroseconds(microNumber);
      delay(135);
      myservo.writeMicroseconds(1500);
    }
     if(pos>99 && pos <= 120){//Done
      int microNumber = 135;
      microNumber = microNumber + pos;
      myservo.writeMicroseconds(microNumber);
      delay(160);
      myservo.writeMicroseconds(1500);
    }

  /*
   * microseconds 1000-  counter counteclockwise rotation 
   * microseconds 1500-  Sit still 
   * microseconds 2000-   counteclockwise rotation 
   */
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin("http://35.164.123.86:3000/getValue"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        String tempVal;
        // getting first two characters of string to get the Temp values from node.js server
        for(int i=0; i<2;i++){
          tempVal= tempVal + payload.charAt(i);
          
          }
          Serial.println(tempVal);
          // convert to integer to update the position value 
          int numVal = tempVal.toInt();
          // turn pos to the tempature value 
          pos = numVal;
          // to only run once or when the tempval changes 
         
          if(Counter == 0){

            //moving code
               if (pos == 0 ){//done
                    delay(1000);
                    myservo.writeMicroseconds(1500);
                }
                if(pos>1 && pos<20){//done
                    int microNumber = 50;
                    microNumber = microNumber + pos;
                    myservo.writeMicroseconds(microNumber);
                    delay(50);
                    myservo.writeMicroseconds(1500);
                    
                  }
                  if(pos>21 && pos<40){//done
                    int microNumber = 50;
                    microNumber = microNumber + pos;
                    myservo.writeMicroseconds(microNumber);
                    delay(90);
                    myservo.writeMicroseconds(1500);
                    
                    
                  }
                   if(pos>41 && pos<60){// NEEEDS FIXING 
                    int microNumber = 200;
                    microNumber = microNumber + pos;
                    myservo.writeMicroseconds(microNumber);
                    delay(350);
                    myservo.writeMicroseconds(1500);
                    
                  }
                   if(pos>71 && pos<80){// DONE Dont mess with
                    int microNumber = 200;
                    microNumber = microNumber + pos;
                    myservo.writeMicroseconds(microNumber);
                    delay(120);
                    myservo.writeMicroseconds(1500);
                    
                  }
                  
                  if(pos>81 && pos <= 99){//Done
                    int microNumber = 140;
                    microNumber = microNumber + pos;
                    myservo.writeMicroseconds(microNumber);
                    delay(135);
                    myservo.writeMicroseconds(1500);
                  }
                   if(pos>99 && pos <= 120){//Done
                    int microNumber = 135;
                    microNumber = microNumber + pos;
                    myservo.writeMicroseconds(microNumber);
                    delay(160);
                    myservo.writeMicroseconds(1500);
                  }
                  Counter = 1;
            }
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
  
  
}
