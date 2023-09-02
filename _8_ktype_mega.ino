#include "max6675.h" //this is for modules
int z=0;
//DO=SO, CS=CS, CLK=SCK
//Sensor 1
int thermoDO1 = 44; //Check the pins of the modules
int thermoCS1 = 42;
int thermoCLK1 = 40;
float temp1 = 0;
MAX6675 thermocouple1(thermoCLK1, thermoCS1, thermoDO1);

//Sensor 2
int thermoDO2 = 38;
int thermoCS2 = 36;
int thermoCLK2 = 34;
float temp2 = 0;
MAX6675 thermocouple2(thermoCLK2, thermoCS2, thermoDO2);

//Sensor 3
int thermoDO3 = 32;
int thermoCS3 = 30;
int thermoCLK3 = 28;
float temp3 = 0;
MAX6675 thermocouple3(thermoCLK3, thermoCS3, thermoDO3);

//Sensor 4
int thermoDO4 = 26;
int thermoCS4 = 24;
int thermoCLK4 = 22;
float temp4 = 0;
MAX6675 thermocouple4(thermoCLK4, thermoCS4, thermoDO4);

//Sensor 5
int thermoDO5 = 53;
int thermoCS5 = 51;
int thermoCLK5 = 49;
float temp5 = 0;
MAX6675 thermocouple5(thermoCLK5, thermoCS5, thermoDO5);

//Sensor 6
int thermoDO6 = 47;
int thermoCS6 = 45;
int thermoCLK6 = 43;
float temp6 = 0;
MAX6675 thermocouple6(thermoCLK6, thermoCS6, thermoDO6);

//Sensor 7
int thermoDO7 = 41;
int thermoCS7 = 39;
int thermoCLK7 = 37;
float temp7 = 0;
MAX6675 thermocouple7(thermoCLK7, thermoCS7, thermoDO7);

//Sensor 8
int thermoDO8 = 35;
int thermoCS8 = 33;
int thermoCLK8 = 31;
float temp8 = 0;
MAX6675 thermocouple8(thermoCLK8, thermoCS8, thermoDO8);
float tempP = 0;
void setup() {
  Serial.begin(9600);

  //Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  //delay(1000);
}
//YOU CAN USE ALL THE SENSORS IF YOU WANT I JUST USING 5, 6 AND 7 IN THIS CASE!!
void loop() {
  // basic readout test, just print the current temp
  //temp1 = thermocouple1.readCelsius();
  //temp2 = thermocouple2.readCelsius();
  //temp3 = thermocouple3.readCelsius();
  //temp4 = thermocouple4.readCelsius();
  temp5 = thermocouple5.readCelsius();
  temp6 = thermocouple6.readCelsius();
  temp7 = thermocouple7.readCelsius();
  //temp8 = thermocouple8.readCelsius();
  //tempP = (temp1+temp2+temp3+temp4+temp5+temp6+temp7+temp8)/8;
  //Serial.print("z"); 
  Serial.print(z);
  Serial.print(",");
  //Serial.print("Temp1: "); 
  //Serial.print(temp1);
  //Serial.print(",");
  //Serial.print("Temp2: "); 
  //Serial.print(temp2);
  //Serial.print(",");
  //Serial.print("Temp3: "); 
  //Serial.print(temp3);
  //Serial.print(",");
  //Serial.print("Temp4: "); 
  //Serial.print(temp4);
  //Serial.print(",");
  //Serial.print("Temp5: "); 
  Serial.print(temp5);
  Serial.print(",");
  //Serial.print("Temp6: "); 
  Serial.print(temp6);
  Serial.print(",");
  //Serial.print("Temp7: "); 
  Serial.print(temp7);
  //Serial.print(",");
  //Serial.print("Temp8: "); 
  //Serial.print(temp8);
  Serial.print("\n");
  //Serial.print("TempP: "); 
  //Serial.print(tempP);
  //Serial.println(",");
  // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
  delay(30000);
  z=z+30;
}
/*You don't need to use that many pins on the Arduino.
Arduino has hard SPI on pins 11, 12 and 13. (using hard SPI is faster than the soft(x3) SPI you are using here)
Arduino pin D12 is MISO (Master In Slave Out), so ALL devices SO (Slave Out) can go to this pin.
Arduino pin D13 is SCK (clock), so ALL devices SCK can go to this pin.
The CS (Cable Select) from each device go to separate pins of your choice on the Arduino.
The Arduino then uses the CS pins to select which device it wants data from.
This way it leaves more pins to add more devices.
In this case you are not sending any data to the devices, so pin D11, MOSI (Master Out Slave In) is not used. (don't use this pin for CS)
*/
