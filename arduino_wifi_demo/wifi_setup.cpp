// wifi_setup.cpp

#include "wifi_setup.h"

char ssid[32];
char pass[64];

void getWiFiCredentials();
void connectWiFi();

void setupWiFi() {
  getWiFiCredentials();
  connectWiFi();
}

void getWiFiCredentials() {
  Serial.println("Enter WiFi SSID:");
  while (Serial.available() == 0);
  Serial.readBytesUntil('\n', ssid, sizeof(ssid) - 1);
  ssid[strlen(ssid)] = '\0';

  Serial.print("SSID: ");
  Serial.println(ssid);

  Serial.println("Enter WiFi Password:");
  while (Serial.available() == 0);
  Serial.readBytesUntil('\n', pass, sizeof(pass) - 1);
  pass[strlen(pass)] = '\0';

  Serial.print("Password: ");
  Serial.println("********");
}

void connectWiFi() {
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void printWiFiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}