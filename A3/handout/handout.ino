#include <Arduino.h>
#include <TTGO.h>
TTGOClass *ttgo;

char * HOSTNAME = "test12345678";
char * WifiPASS = "";
#include <WiFi.h>
#include <WebServer.h>



WebServer server(80);


void setup() {
    Serial.begin(115200);

    

    // Start Wifi AP
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(HOSTNAME, WifiPASS);
    Serial.println(WiFi.softAPIP());


      
    // handle index -- HTTP Server

    
    server.on("/", []() {
      digitalWrite(21, 1);
      String v = server.arg("v");
  
      
      
      Serial.println(v);
      // write `v` String to Screen
      //eg: you did this in A1
      ttgo = TTGOClass::getWatch();
      ttgo->begin();
      ttgo->openBL();

      ttgo->eTFT->fillScreen(TFT_BLACK);
      ttgo->eTFT->setTextColor(TFT_WHITE, TFT_BLACK);
      ttgo->eTFT->setTextFont(4);
      //sending String V as it contains input variable
      ttgo->eTFT->drawString(v,32,110);
  
      server.send(200, "text/html", "<html><head><script>function foo(){var v = document.getElementById('theText').value;window.location.href=\"./?v=\" + v}</script></head><body><input type='text' maxlength='100' id='theText'><button  onclick='foo()'  > Submit </button></body><script>document.getElementById(\"theText\").value=window.location.search.replace(\"?v=\",\"\")</script><html>");
    
    });
    // server route on 
    server.on("/on", [](){
        server.send(200, "text/html", "<html><head><script>function foo(){var v = document.getElementById('theText').value;window.location.href=\"./?v=\" + v}</script></head><body><input type='text' maxlength='100' id='theText'><button  onclick='foo()'  > Submit </button></body><script>document.getElementById(\"theText\").value=window.location.search.replace(\"?v=\",\"\")</script><html>");
    });
    // server route off
    server.on("/off", [](){
        server.send(200, "text/html", "<html><head><script>function foo(){var v = document.getElementById('theText').value;window.location.href=\"./?v=\" + v}</script></head><body><input type='text' maxlength='100' id='theText'><button  onclick='foo()'  > Submit </button></body><script>document.getElementById(\"theText\").value=window.location.search.replace(\"?v=\",\"\")</script><html>");
    });

    

       

    
    server.begin();
  
    
}

void loop() {
    server.handleClient();  
}
