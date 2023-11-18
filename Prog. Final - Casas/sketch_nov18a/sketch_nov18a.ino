//MICROCONTROLADOR - ESP32
#include <DHT.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>                                       //Responsável pelo Servo Motor
Servo myServo;                                                // Variável do Motor
int servoPin = 4;                                             // Define pino do motor
/* Put your SSID & Password */
const char* ssid = "CIDADE INTELIGENTE";  // Enter SSID here
const char* password = "0123456789";  //Enter Password here
/* Put IP Address details */
IPAddress local_ip(192,168,9,2);
IPAddress gateway(192,168,9,2);
IPAddress subnet(255,255,255,0);

WebServer server(80);

uint8_t LED1pin = 14;
bool LED1status = LOW;

uint8_t LED2pin = 5;
bool LED2status = LOW;

uint8_t LED3pin = 32;
bool LED3status = LOW;
uint8_t LED4pin = 22;
bool LED4status = LOW;
uint8_t LED5pin = 21;
bool LED5status = LOW;
uint8_t LED6pin = 19;
bool LED6status = LOW;
uint8_t LED7pin = 18;
bool LED7status = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);
  pinMode(LED5pin, OUTPUT);
  pinMode(LED6pin, OUTPUT);
  pinMode(LED7pin, OUTPUT);
  myServo.attach(servoPin);                                 // configura myServo para enviar informação para ServoPin
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(500);
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.on("/led3on", handle_led3on);
  server.on("/led3off", handle_led3off);
  server.on("/led4on", handle_led4on);
  server.on("/led4off", handle_led4off);
  server.on("/led5on", handle_led5on);
  server.on("/led5off", handle_led5off);
  server.on("/led6on", handle_led6on);
  server.on("/led6off", handle_led6off);
  server.on("/led7on", handle_led7on);
  server.on("/led7off", handle_led7off);
  server.onNotFound(handle_NotFound);
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(ssid);
}
void loop() {
  server.handleClient();
  if(LED1status)
  {digitalWrite(LED1pin, HIGH);}
  else
  {digitalWrite(LED1pin, LOW);}
  
  if(LED2status)
  {digitalWrite(LED2pin, HIGH);}
  else
  {digitalWrite(LED2pin, LOW);}

 if(LED3status)
  {digitalWrite(LED3pin, HIGH);}
  else
  {digitalWrite(LED3pin, LOW);}
   if(LED4status)
  {digitalWrite(LED4pin, HIGH);}
  else
  {digitalWrite(LED4pin, LOW);}
   if(LED5status)
  {digitalWrite(LED5pin, HIGH);}
  else
  {digitalWrite(LED5pin, LOW);}
   if(LED6status)
  {digitalWrite(LED6pin, HIGH);
  }
  else
  {digitalWrite(LED6pin, LOW);}
   if(LED7status)
  {digitalWrite(LED7pin, HIGH);
  myServo.write(150);}
  else
  {digitalWrite(LED7pin, LOW);
  myServo.write(-150);}
}

void handle_OnConnect() {
  LED1status = LOW;
  LED2status = LOW;
  LED3status = LOW;
  LED4status = LOW;
  LED5status = LOW;
  LED6status = LOW;
  LED7status = LOW;
  Serial.println("GPIO4 Status: OFF | GPIO5 Status: OFF | GPIO23 Status: OFF | GPIO22 Status: OFF | GPIO21 Status: OFF | GPIO19 Status: OFF | GPIO18 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true,LED2status,LED3status,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false,LED2status,LED3status,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led2on() {
  LED2status = HIGH;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,true,LED3status,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led2off() {
  LED2status = LOW;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,false,LED3status,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led3on() {
  LED3status = HIGH;
  Serial.println("GPIO23 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,true,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led3off() {
  LED3status = LOW;
  Serial.println("GPIO23 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,false,LED4status,LED5status,LED6status,LED7status)); 
}

void handle_led4on() {
  LED4status = HIGH;
  Serial.println("GPIO22 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,true,LED5status,LED6status,LED7status)); 
}

void handle_led4off() {
  LED4status = LOW;
  Serial.println("GPIO22 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,false,LED5status,LED6status,LED7status)); 
}

void handle_led5on() {
  LED5status = HIGH;
  Serial.println("GPIO21 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,true,LED6status,LED7status)); 
}

void handle_led5off() {
  LED5status = LOW;
  Serial.println("GPIO21 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,false,LED6status,LED7status)); 
}

void handle_led6on() {
  LED6status = HIGH;
  Serial.println("GPIO19 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,LED5status,true,LED7status)); 
}

void handle_led6off() {
  LED6status = LOW;
  Serial.println("GPIO19 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,LED5status,false,LED7status)); 
}

void handle_led7on() {
  LED7status = HIGH;
  Serial.println("GPIO18 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,LED5status,LED6status,true)); 
}

void handle_led7off() {
  LED7status = LOW;
  Serial.println("GPIO18 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,LED2status,LED3status,LED4status,LED5status,LED6status,false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat,uint8_t led3stat,uint8_t led4stat,uint8_t led5stat,uint8_t led6stat,uint8_t led7stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<link href=\"https://fonts.googleapis.com/css?family=Open+Sans:300,400,600\" rel=\"stylesheet\">\n";
  ptr +="<title>ManuJURCK</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-pair { display: flex; flex-direction: row; justify-content: space-between; }\n";
  ptr += ".button-container { flex: 1; margin: 0 5px; }\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on1 {background-color: #f39c12;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off1 {background-color: #f39c12;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="h2 {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +=".side-by-side{display: inline-block;vertical-align: middle;position: relative;}\n";
  ptr +=".humidity-icon{background-color: #3498db;width: 30px;height: 30px;border-radius: 50%;line-height: 36px;}\n";
  ptr +=".humidity-text{font-weight: 600;padding-left: 15px;font-size: 19px;width: 160px;text-align: left;}\n";
  ptr +=".humidity{font-weight: 600;font-size: 19px;color: #3498db;}\n";
  ptr +=".temperature-icon{background-color: #f39c12;width: 30px;height: 30px;border-radius: 50%;line-height: 40px;}\n";
  ptr +=".temperature-text{font-weight: 600;padding-left: 15px;font-size: 19px;width: 160px;text-align: left;}\n";
  ptr +=".temperature{font-weight: 600;font-size: 19px;color: #f39c12;}\n";
  ptr +=".superscript{font-size: 17px;font-weight: 600;position: absolute;right: -20px;top: 15px;}\n";
  ptr +=".data{padding: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>CIDADE INTELIGENTE</h1>\n";
  ptr +="<h3>SISTEMA DE CONTROLE</h3>\n";
  ptr +="<div id=\"webpage\">\n";
   ptr +="<div class=\"data\">\n";
   ptr +="<div class=\"side-by-side temperature-icon\">\n";
  ptr += "<svg viewBox=\"-5.76 -5.76 59.52 59.52\" id=\"Layer_2\" data-name=\"Layer 2\" xmlns=\"http://www.w3.org/2000/svg\" fill=\"#000000\" stroke=\"#000000\" stroke-width=\"3.312\"><g id=\"SVGRepo_bgCarrier\" stroke-width=\"0\"></g><g id=\"SVGRepo_tracerCarrier\" stroke-linecap=\"round\" stroke-linejoin=\"round\"></g><g id=\"SVGRepo_iconCarrier\"><defs><style>.cls-1{fill:none;stroke:#ffffff;stroke-linecap:round;stroke-linejoin:round;}</style></defs><path class=\"cls-1\" d=\"M24,4.5A13.51,13.51,0,0,1,37.41,17.91c0,8-7.32,11.09-7.32,15.24v1.21H17.91V33.15c0-4.17-7.32-7.21-7.32-15.24A13.51,13.51,0,0,1,24,4.5ZM17.91,34.36H30.09v4.57H17.91Zm0,4.57H30.09V43.5H17.91Z\"></path></g></svg>";
   ptr +="</div>\n";
   ptr +="<div class=\"side-by-side temperature\">CASA (1)</div>\n";
   ptr +="<div class=\"side-by-side temperature\">";
   ptr +="</div>\n";
   ptr += "<div class=\"button-pair\">\n";//para colocar botoes lado a lado
   if(led1stat)
  {ptr +="<div class=\"button-container\"><p>Bloco (1) <br> Status : ON</p><a class=\"button button-off1\" href=\"/led1off\">OFF</a></div>\n";}
  else
  {ptr +="<div class=\"button-container\"><p>Bloco (1) <br> Status : OFF</p><a class=\"button button-on1\" href=\"/led1on\">ON</a></div>\n";}

  if(led2stat)
  {ptr +="<div class=\"button-container\"><p>Bloco (2) <br> Status : ON</p><a class=\"button button-off1\" href=\"/led2off\">OFF</a></div>\n";}
  else
  {ptr +="<div class=\"button-container\"><p>Bloco (2) <br> Status : OFF</p><a class=\"button button-on1\" href=\"/led2on\">ON</a></div>\n";}
 ptr += "</div>\n";//fechando div para formar pares de botoes 
 if(led3stat)
  {ptr +="<div class=\"button-container\"><p>Exterior <br> Status : ON</p><a class=\"button button-off1\" href=\"/led3off\">OFF</a></div>\n";}
  else
  {ptr +="<div class=\"button-container\"><p>Exterior <br> Status : OFF</p><a class=\"button button-on1\" href=\"/led3on\">ON</a></div>\n";}
   ptr +="<div class=\"data\">\n";
   ptr +="<div class=\"side-by-side humidity-icon\">\n";
ptr += "<svg viewBox=\"-5.76 -5.76 59.52 59.52\" id=\"Layer_2\" data-name=\"Layer 2\" xmlns=\"http://www.w3.org/2000/svg\" fill=\"#000000\" stroke=\"#000000\" stroke-width=\"3.312\"><g id=\"SVGRepo_bgCarrier\" stroke-width=\"0\"></g><g id=\"SVGRepo_tracerCarrier\" stroke-linecap=\"round\" stroke-linejoin=\"round\"></g><g id=\"SVGRepo_iconCarrier\"><defs><style>.cls-1{fill:none;stroke:#ffffff;stroke-linecap:round;stroke-linejoin:round;}</style></defs><path class=\"cls-1\" d=\"M24,4.5A13.51,13.51,0,0,1,37.41,17.91c0,8-7.32,11.09-7.32,15.24v1.21H17.91V33.15c0-4.17-7.32-7.21-7.32-15.24A13.51,13.51,0,0,1,24,4.5ZM17.91,34.36H30.09v4.57H17.91Zm0,4.57H30.09V43.5H17.91Z\"></path></g></svg>";
   ptr +="</div>\n";
   ptr +="<div class=\"side-by-side humidity\">CASA (2)</div>\n";
   ptr +="<div class=\"side-by-side humidity\">";
   ptr +="</div>\n";
     ptr += "<div class=\"button-pair\">\n";//para colocar botoes lado a lado
  if(led5stat)
  {ptr +="<div class=\"button-container\"><p>Bloco (1) <br> Status: ON</p><a class=\"button button-off\" href=\"/led5off\">OFF</a></div>\n";}
  else
  {ptr +="<div class=\"button-container\"><p>Bloco (1) <br> Status: OFF</p><a class=\"button button-on\" href=\"/led5on\">ON</a></div>\n";}
  if(led6stat)
  {ptr +="<div class=\"button-container\"><p>Bloco (2) <br> Status: ON</p><a class=\"button button-off\" href=\"/led6off\">OFF</a></div>\n";}
  else
  {ptr +="<div class=\"button-container\"><p>Bloco (2) <br> Status: OFF</p><a class=\"button button-on\" href=\"/led6on\">ON</a></div>\n";}
   ptr += "</div>\n";//fechando div para formar pares de botoes 
  if(led7stat)
  {ptr +="<p>Garagem <br> Status: ON</p><a class=\"button button-off\" href=\"/led7off\">OFF</a>\n";}
  else
  {ptr +="<p>Garagem <br> Status: OFF</p><a class=\"button button-on\" href=\"/led7on\">ON</a>\n";}
   ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
