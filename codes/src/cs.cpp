#include <WiFi.h>  
#include <WiFiUdp.h>  
#include <ArduinoOTA.h>  
  
//    Can be client or even host   //  
#ifndef STASSID  
#define STASSID "Pavan"  // Replace with your network credentials  
#define STAPSK  "pavan1234"  
#endif  
  
const char* ssid = STASSID;  
const char* password = STAPSK;  
int A,B,P,Q;     
int C,R;   
  
void OTAsetup() {  
  WiFi.mode(WIFI_STA);  
  WiFi.begin(ssid, password);  
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {  
    ESP.restart();  
  }  
  ArduinoOTA.begin();  
}  
  
void OTAloop() {  
  ArduinoOTA.handle();  
}  
    
  
void setup(){  
  OTAsetup();  
  
  //-------------------//  
  // Custom setup code //  
  //-------------------//  
    pinMode(2, INPUT);    
    pinMode(3, INPUT);   
    pinMode(4, INPUT);     
    pinMode(5, INPUT);      
    pinMode(6, OUTPUT);       
    pinMode(8, OUTPUT);    
}  
  
void loop() {  
  OTAloop();  
  delay(10);  // If no custom loop code ensure to have a delay in loop  
  //-------------------//  
  // Custom loop code  //  
  //-------------------//  
  
  A = digitalRead(2);  
  B= digitalRead(3);  
  P = digitalRead(4);  
  Q= digitalRead(5);  
  C=(!(!A&&(A||B)))||(B); 
  R=(!Q)||(!P&&(P||Q));  
  
  digitalWrite(8, R);  
  digitalWrite(6, C);   
  
}
