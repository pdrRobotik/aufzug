#include <FtduinoSimple.h>
#include <AccessNode.h>

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:
  run();
}

// M1 = Förderband-Lager
// M2 = Förderband-Aufzug
// M3 = Aufzug
// I1 = Taster (Unten)
// I2 = Taster (Oben)
// I3 = Lichtschranke

void run()
{
  // Aufzug fährt in die Ausgangsposition
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
  while (!ftduino.input_get(Ftduino::I1)) delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  // Lichtschranke wird überprüft
  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  while (ftduino.input_get(Ftduino::I3)) delay(1);
  delay(800);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  // Aufzug fährt nach oben
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
  while (!ftduino.input_get(Ftduino::I2)) delay(1);
  // Laufbänder gehen an und wieder aus
  delay(700);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  delay(1000);
  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
  delay(3000);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}
