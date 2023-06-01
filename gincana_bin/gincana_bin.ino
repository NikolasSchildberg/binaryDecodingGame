// PREENCHA SUA PALAVRA, LETRA POR LETRA
char palavra[8] = {'B','A','N','A','N','A','D','A'};
// E O NÚMERO DE CARACTERES QUE ELA POSSUI
int n_letras = 7;

// PRONTO! :)

int del = 5000;
int binario[4] = {0,0,0,0};
int remains = 0;
char letter = ' ';

void setup() {
  // starts communication to Serial monitor
  Serial.begin(9600);
  
  // declares LEDs
  for (int led = 10; led <=13; led ++){
    pinMode(led, OUTPUT);
  }

  char alfab[26] ={
    'A','B','C','D','E',
    'F','G','H','I','J',
    'K','L','M','N','O',
    'P','Q','R','S','T',
    'U','V','W','X','Y',
    'Z'
  };

  // iterates through given word
  for( int countt = 0 ; countt < n_letras ; countt ++ ){
    letter = palavra[countt];

    // finds position of given letter in the alphabet
    for (int index = 0; index<26; index ++){
      if (alfab[index] == letter){
        remains = index + 1;
      }
    }

    // fills the array "binario" with bits, based on given decimal
    for(int pos = 0; remains > 0; pos ++){
      binario[pos] = remains %2;
      remains = remains/2;
    }

    // turns on LEDs based on the contents of the array "binario"
    for (int count = 0; count < 4; count ++){
      digitalWrite(count+10,binario[count]);
      binario[count] = 0;
    }

  Serial.print(letter);
  delay(del);
  }

  // resets the LEDs to off
  for (int count = 0; count < 4; count ++){
      digitalWrite(count+10,0);
    }
  remains = 0;
}

void loop() {
}