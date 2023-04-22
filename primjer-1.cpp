#define MQ2pin 0  // Analogni pin A0 

float sensorValue;  //variabla za smjestanje ocitane vrijednosti

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
	Serial.println("MQ2 Zagrijavanje... cekaj 20 sekundi!");
  delay(20000); // 20 sekundi odgode
}

void loop() {
	sensorValue = analogRead(MQ2pin); // ocitanu vrijednost A0 smjesit u varijablu SensorValue

	Serial.print("Vrijednost senzora: ");  //ispis teksta na Serial Monitor
	Serial.println(sensorValue); // ispis vrijednosti na Serial Monitor
	
	delay(2000); // odgoda prije sljedeceg ocitanja
}
