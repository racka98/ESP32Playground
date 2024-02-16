#pragma once

#define WIFI_SSID "The-Net" // Put your wifi name here
#define WIFI_PASSWORD "password" // Put your wifi password here

void connect_to_wifi_blocking(void);

void check_wifi_status_non_blocking(void);

void check_wifi_status();