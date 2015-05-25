//#include <LiquidCrystal.h> //Carrega a biblioteca LiquidCrystal  

//#define Luz_Fundo  9

//LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

// Ponto.
int dp = 5;

// Segmentos.
int a = 9;
int b = 13;
int c = 4;
int d = 6;
int e = 7;
int f = 10;
int g = 3;

// Dígitos.
int dig1 = 8;
int dig2 = 11;
int dig3 = 12;
int dig4 = 2;

byte segmentos[7] = { a, b, c, d, e, f, g };
byte digitos[4] = { dig1,dig2,dig3,dig4 };

// Array de bits dos números
byte bitsNumeros[4][7] = { { 0, 1, 1, 1, 1, 1, 0 }, // = U
                            { 1, 0, 0, 1, 1, 1, 1 }, // = E
                            { 1, 1, 0, 0, 1, 1, 1 }, // = P
                            { 1, 1, 1, 1, 1, 1, 1 }, // = B
};
// Atributos de acumuladores.
int acm = 0;
int acmNumeros = 0;
int acmSegmentos = 0;

// Habilitar dígito.
void habilitarDigito(int digito){
  
  if (digito == 1)
    digitalWrite(dig1, LOW);
  else if (digito == 2)
    digitalWrite(dig2, LOW);
  else if (digito == 3)
    digitalWrite(dig3, LOW);
  else if (digito == 4)
    digitalWrite(dig4, LOW);
}

// Desabilitar todos os digitos.
void desabilitarDigitos(){
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
}

void setup(){
  
  //Serial.begin(9600);
/* lcd.begin(16, 2);
  pinMode(Luz_Fundo, OUTPUT);
  digitalWrite(Luz_Fundo, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("lucas m lima");
*/
  pinMode(dp, OUTPUT);
  
  // Iniciando pinos do arduino.
  for (acm = 0; acm < sizeof(segmentos); acm++)
    pinMode(segmentos[acm], OUTPUT);

  // Iniciando pinos do arduino.
  for (acm = 0; acm < sizeof(digitos); acm++)
    pinMode(digitos[acm], OUTPUT);
  
  boolean infinito = true;
  while (infinito == true)
    loopInfinito();
}

void loop() {}

// Imprime o número no display a partir dos segmentos do array.
void construirSegmentosDigitos(int numero){
  
  for (acmSegmentos = 0; acmSegmentos < 7; acmSegmentos++){
    if (bitsNumeros[numero][acmSegmentos] == 1){
      digitalWrite(segmentos[acmSegmentos], HIGH);
    } else {
      digitalWrite(segmentos[acmSegmentos], LOW);
    }
  }
}

// Laço de número até o valor máximo.
void loopInfinito(){

  //digitalWrite(dp, HIGH);

  /*desabilitarDigitos();
  habilitarDigito(1);
  construirSegmentosDigitos(0);
  delay(5);
  desabilitarDigitos();
  habilitarDigito(2);
  construirSegmentosDigitos(1);
  delay(5);
  desabilitarDigitos();
  habilitarDigito(3);*/
  construirSegmentosDigitos(3);
  /*delay(5);
  desabilitarDigitos();
  habilitarDigito(4);
  construirSegmentosDigitos(3);
  delay(5);*/
}
