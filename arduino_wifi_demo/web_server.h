// web_server.h

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "WiFiS3.h"
#include <Arduino.h>

void handleClient(WiFiServer& server, int ledPin);

#endif