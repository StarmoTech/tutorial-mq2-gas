#define MQ2pin 0  // Analogni pin A0 
int buzzer = 13; // digitalni pin 13

float sensorValue;  //variabla za smjestanje ocitane vrijednosti

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
  pinMode(buzzer, OUTPUT); // postavi buzzer pin 13 kao izlazni
	Serial.println("MQ2 Zagrijavanje... cekaj 20 sekundi!");
  delay(20000); // 20 sekundi odgode
}

void loop() {
	sensorValue = analogRead(MQ2pin); // ocitanu vrijednost A0 smjesit u varijablu SensorValue

	Serial.print("Vrijednost senzora: ");  //ispis teksta na Serial Monitor
	Serial.println(sensorValue); // ispis vrijednosti na Serial Monitor
	if (sensorValue >= 500) {  // ako je vrijednost senzora veća ili jedna 500 pokreni funkciju
   alarm(500, 500); // Promjenom broja u funkciji uticete na duzinu delay 
  }
	delay(1000); // odgoda prije sljedeceg ocitanja
}

// funkcija za alarm
void alarm(int onVrijeme, int offVrijeme) {
	Serial.println("Alarm pokrenut"); // ispis upozorenja
  tone(buzzer, 4000 ); // frekvencija 4000Hz ili 4KHz
  delay(onVrijeme);  // vrijeme upaljenog signala      
  noTone(buzzer); // ugasi signal
  delay(offVrijeme); // vrijeme ugasenog signala      
}
