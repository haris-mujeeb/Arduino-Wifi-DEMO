#include "WiFiS3.h"
#include "wifi_setup.h"
#include "web_server.h"


int led = LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

int main() {
  setup();
  while (true) {
    loop();
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("WiFi Web Server");
  pinMode(led, OUTPUT);

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  setupWiFi(); // Call the WiFi setup function from wifi_setup.cpp

  server.begin();
  printWiFiStatus(); // Call the WiFi status function from wifi_setup.cpp
}

void loop() {
  handleClient(server, led); // Call the web server client handling function from web_server.cpp
}