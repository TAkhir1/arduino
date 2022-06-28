#include <PZEM004Tv30.h>

/* Hardware Serial3 is only available on certain boards.
 * For example the Arduino MEGA 2560
*/
PZEM004Tv30 pzem(D7,D6);
int relay = D1;
int buzzer = D2;

void setup() {
  Serial.begin(115200);
  pinMode (D1,OUTPUT);
  pinMode (D2,OUTPUT);
}

void loop() {
    float voltage = pzem.voltage();
    if(!isnan(voltage)){
        Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
    } else {
        Serial.println("Error reading voltage");
    }

    float current = pzem.current();
    if(!isnan(current)){
        Serial.print("Current: "); Serial.print(current); Serial.println("A");
    } else {
        Serial.println("Error reading current");
    }

    float power = pzem.power();
    if(!isnan(power)){
        Serial.print("Power: "); Serial.print(power); Serial.println("W");
    } else {
        Serial.println("Error reading power");
    }

    float energy = pzem.energy();
    if(!isnan(energy)){
        Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
    } else {
        Serial.println("Error reading energy");
    }

    float frequency = pzem.frequency();
    if(!isnan(frequency)){
        Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
    } else {
        Serial.println("Error reading frequency");
    }

    float pf = pzem.pf();
    if(!isnan(pf)){
        Serial.print("PF: "); Serial.println(pf);
    } else {
        Serial.println("Error reading power factor");
    }
    if(power > 15){
      digitalWrite, (D1, HIGH);
      //delay (10);
    }
    else if (power <= 15){
      digitalWrite, (D1, LOW);
      //delay(10);
    }
    if(energy=15){
      digitalWrite, (D2,HIGH);
      delay(10);
    }
    Serial.println();
    delay(1000);
}
