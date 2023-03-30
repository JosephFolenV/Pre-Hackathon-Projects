#include <WiFi.h>
#include <HTTPClient.h>
  
const char* ssid = "JPhone";
const char* password =  "abcdefgh";

// This is esp32 code for asserting pins 12 & 13 to high depending on the value returned by the get request to the URL
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");
  
}
  
void loop() {
  
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
  
    HTTPClient http;
  
    http.begin("https://websocketcackend.herokuapp.com/api/get/message"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
    //Magic Section
    //Do X if site returns Y
    String payload = http.getString();
    if(payload == "\"true\"")
    {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
    }
    else if (payload == "\"false\"")
    {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
    }
    
    if (httpCode > 0) { //Check for the returning code
        Serial.println(httpCode);
        Serial.println(payload);
      }
  
    else {
      Serial.println("Error on HTTP request");
    }
    http.end(); //Free the resources
  }
  
  delay(10000);
}