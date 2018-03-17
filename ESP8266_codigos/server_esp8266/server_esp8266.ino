#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "Yure";
const char* password = "12345678";

ESP8266WebServer server(80);


void handleRoot() {
  String site;
  site = "<html>\n";
  site += "<head><title>Ola mundo</title></head>";
  site += "<body style = \"color: blue\">\n";
  site += "<center><h1>Ola mundo(autor: Yure Albuquerque)</h1></center>";
  site += "<a href >";
  site += "</form>";
  site += "</body>";
  site += "</html>";
  server.send(200, "text/html", site);
}

void handle2() {
  String site;
  site = "<html>\n";
  site += "<head><title>Ola mundo</title></head>";
  site += "<body style = \"color: red\">\n";
  site += "<center><h1>Segunda Pagina</h1></center>";
  site += "<form><input type=\"radio\" name=\"sex\" value=\"male\"> Masculino";
  site += "<br><input type = \"radio\" name=\"sex\" value=\"female\"> Feminino";
  site += "</form>";
  site += "</body>";
  site += "</html>";
  server.send(200, "text/html", site);
}

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  //WiFi.begin(ssid, password);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.begin();
  delay(10000);
  Serial.println(WiFi.localIP());
}

void loop(void) {
  server.handleClient();
}
