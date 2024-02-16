#include "external_blink.h"

void set_external_blink() {
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(ORANGE_PIN, OUTPUT);
}

void loop_external_blink() {
    digitalWrite(ORANGE_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    delay(200);
    digitalWrite(ORANGE_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    delay(200);
    digitalWrite(ORANGE_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    delay(200);
    digitalWrite(ORANGE_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    delay(200);
}