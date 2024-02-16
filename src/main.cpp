#include <Arduino.h>
#include "wifi_set.h"
#include "blink_timer.h"
#include "external_blink.h"
#include "hx711_weight.h"
#include "hx711_calibration.h"

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(115200);
  delay(10);
  Serial.printf("Hello from the setup: %d\n", result);
  //pinMode(LED_BUILTIN, OUTPUT);

  // Blink Timer
  set_blink_timer();

  // External Blink
  set_external_blink();

  // Weight setup
  weight_setup();
  //calibrate_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello from the loop!");
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(1000);
  // connect_to_wifi_blocking();
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);
  // check_wifi_status();
  // delay(5000);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(1000);

  // Blink Timer
  loop_blink_timer();

  // External Blink
  loop_external_blink();

  // Weight measure
  weight_loop();
  //calibrate_loop();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}