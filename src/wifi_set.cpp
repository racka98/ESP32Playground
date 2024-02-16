#include "wifi_set.h"

#include <Arduino.h>
#include <WiFi.h>       // for non blocking wifi fn
#include <WiFiMulti.h>  // for blocking wifi fn

WiFiMulti wifiMulti;

void connect_to_wifi_blocking(void) {
    wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

    // blocking code [wifiMulti.run() attempts to connects to the AP]
    while (wifiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    Serial.println("Connected successfully!");
}

void check_wifi_status() {
    // update the built-in LED
    digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
}

bool isConnected = false;

// check wifi status in a non blocking way
void check_wifi_status_non_blocking(void) {
    if (WiFi.status() == WL_CONNECTED && !isConnected) {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Connected");
        isConnected = true;
    }

    if (WiFi.status() != WL_CONNECTED) {
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        Serial.println("Connecting......");
        delay(1000);
        isConnected = false;
    }
}