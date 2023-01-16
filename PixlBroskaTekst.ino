#define MAPIRAJ 32
#define ZASLON_DOLZINA 4
#define ZASLON_VISINA 5
// hitrost
#define HITROST 6       
// prikaži besedilo
#define PRIKAZI_BESEDILO " HELLO WORLD "
// preslikaznake v 4x5 mrežo
unsigned long mapirajZnake[59];
// nastavi znak v mapirajZnake
void Znk(char Znak, unsigned long vrednost) {
  mapirajZnake[Znak - MAPIRAJ] = vrednost;
}
// odmik našega niza na zaslonu
int odmik = 0;
unsigned long lastMillis = 0;
unsigned long currentMillis = 0;
unsigned int timeout;
char mojaStruna[] = PRIKAZI_BESEDILO;
int length = sizeof(mojaStruna);
// upodobi niz v danem zamiku
void renderString(char *Struna, int odmik) {
  int index = 0;
  while (Struna[index]) {
    upodobiZnak(Struna[index], odmik - index * (ZASLON_DOLZINA + 1));
    index++;
  }
}

// upodobi znak v danes zamiku
void upodobiZnak(char Znak, int znakOffnst) {
  if (znakOffnst<= -ZASLON_DOLZINA || znakOffnst> ZASLON_DOLZINA) {
    // ugasni "zaslon"
    return;
  }

  unsigned long graphic = mapirajZnake[Znak - MAPIRAJ];

  for (byte y = 0; y < ZASLON_VISINA; y++) {
    for (byte x = 0; x < ZASLON_DOLZINA; x++) {
      
      NastaviPixel(3 - x + znakOffnst, y, graphic & 0x1);
      graphic = graphic >> 1;
    }
  }
}

// na danih koordinatah prižgi led diodo oz. osvetli pixel
void NastaviPixel(byte x, byte y, boolean ledStanje) {
  if (x >= 0 && x < ZASLON_DOLZINA) {
    if (y <= x) {
      x++;
    }
    nastaviLed(y, x, ledStanje);
  }
}
// vklopi pin-e, da LED zasveti
void nastaviLed(byte vin, byte gnd, boolean ledStanje) {
  delayMicroseconds(500);
  pinMode(0, INPUT); 
  pinMode(1, INPUT); 
  pinMode(2, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, INPUT); 
  if(!ledStanje) return;
  pinMode(vin, OUTPUT);   
  pinMode(gnd, OUTPUT); 
  digitalWrite(vin, HIGH);
  digitalWrite(gnd, LOW); 
}
// steče ob vklopu naprave 1x
void setup() {
  // ustvari seznam znakov
  // Rows:   1---2---3---4---5---
  Znk('A', 0b10011001111110010110);
  Znk('B', 0b01111001011110010111);
  Znk('C', 0b11100001000100011110);
  Znk('D', 0b01111001100110010111);
  Znk('E', 0b11110001011100011111);
  Znk('F', 0b00010001011100011111);
  Znk('G', 0b01101001110100011110);
  Znk('H', 0b10011001111110011001);
  Znk('I', 0b11100100010001001110);
  Znk('J', 0b00100101010001001110);
  Znk('K', 0b10010101001101011001);
  Znk('L', 0b11110001000100010001);
  Znk('M', 0b10011001111111111001);
  Znk('N', 0b10011001110110111001);
  Znk('O', 0b01101001100110010110);
  Znk('P', 0b00010001011110010111);
  Znk('Q', 0b10000110110110010110);
  Znk('R', 0b10010101011110010111);
  Znk('S', 0b11111000111100011111);
  Znk('T', 0b01000100010001001110);
  Znk('U', 0b01101001100110011001);
  Znk('V', 0b00100101100110011001);
  Znk('W', 0b01101111111110011001);
  Znk('X', 0b10011001011010011001);
  Znk('Y', 0b00110100011010011001);
  Znk('Z', 0b11110010010010001111);
  Znk(' ', 0b00000000000000000000);
  Znk('1', 0b11100100010001100100);
  Znk('2', 0b11110001011010000111);
  Znk('3', 0b01111000011010000111);
  Znk('4', 0b01001111010101100100);
  Znk('5', 0b01111000011100011111);
  Znk('6', 0b01101001011100010110);
  Znk('7', 0b00010010010010001111);
  Znk('8', 0b01101001011010010110);
  Znk('9', 0b01101000111010010110);
  Znk('0', 0b01101001110110110110);
  Znk('a', 0b00101001000110010010);
  Znk('b', 0b00100100100001000010);
  Znk('c', 0b01000010000100100100);
  // čas zamika med znaki
  timeout = 1000 / HITROST;
}
// se ponavlja v neskončnost
void loop() {
  currentMillis = millis();
  renderString(mojaStruna, odmik);
  if (currentMillis - lastMillis > timeout) {
    lastMillis = currentMillis;
    // premakni niz za en "pixsel"
    odmik++;
    // po koncu niza, začni znova od začetka
    if (odmik > length * (ZASLON_DOLZINA + 1)) {
      odmik = -ZASLON_DOLZINA;
    }
  }
}
