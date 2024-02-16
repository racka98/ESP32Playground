/**
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/
#include "HX711.h"
#include "hx711_calibration.h"


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 18;


HX711 scale_calib;

bool _resume = false;
float scale_factor = 1.0f;

void calibrate_setup() {
  //Serial.begin(38400);
  Serial.println("HX711 Calibration");

  Serial.println("Initializing the scale");

  // Initialize library with data output pin, clock input pin and gain factor.
  // Channel selection is made by passing the appropriate gain:
  // - With a gain factor of 64 or 128, channel A is selected
  // - With a gain factor of 32, channel B is selected
  // By omitting the gain factor parameter, the library
  // default "128" (Channel A) is used here.
  scale_calib.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale_calib.read());

  Serial.print("read average: \t\t");
  Serial.println(scale_calib.read_average(20));  	// print the average of 20 readings from the ADC

  Serial.print("get value: \t\t");
  Serial.println(scale_calib.get_value(5));		// print the average of 5 readings from the ADC minus the tare weight (not set yet)


  Serial.println("Start calibration:");
  Serial.println("Place the load cell an a level stable surface.");
  Serial.println("Remove any load applied to the load cell.");
  Serial.println("Send 't' from serial monitor to set the tare offset.");

  scale_calib.set_scale(scale_factor);

  while (_resume == false) {
    if (Serial.available() > 0) {
      if (Serial.available() > 0) {
        char inByte = Serial.read();
        if (inByte == 't') scale_calib.tare();
        _resume = true;
      }
    }
  }
  Serial.println("Scale Tared \t");

  Serial.println("Now, place your known mass on the loadcell.");
  Serial.println("Then send the weight of this mass (i.e. 100.0) from serial monitor.");

  float known_mass = 0.0f;
  float adc_value = 0.0f;
  _resume = false;
  while(_resume == false) {
    if (Serial.available() > 0) {
      known_mass = Serial.parseFloat();
      if (known_mass != 0) {
        Serial.print("Known mass is: ");
        Serial.println(known_mass);
        _resume = true;
      }
    }
  }

  adc_value = scale_calib.get_units();
  Serial.print("Calculated ADC value is: ");
  Serial.println(adc_value);
  scale_factor = adc_value / known_mass;

  Serial.print("Calculated Scale Factor is: ");
  Serial.println(scale_factor);

  scale_calib.set_scale(scale_factor);

  Serial.println("Readings;");
}

void calibrate_loop() {
    Serial.print("one reading:\t");
  Serial.print(scale_calib.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale_calib.get_units(10), 1);

  scale_calib.power_down();			        // put the ADC in sleep mode
  delay(5000);
  scale_calib.power_up();
}