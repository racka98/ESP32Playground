#pragma once

#define WIFI_SSID "The-Net"
#define WIFI_PASSWORD "lanparty0598"

void connect_to_wifi_blocking(void);

void check_wifi_status_non_blocking(void);

void check_wifi_status();