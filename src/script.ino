// Ponto.
int dp = 6;
 
// Segmentos.
int a = 18;
int b = 14;
int c = 7;
int d = 1;
int e = 0;
int f = 17;
int g = 8;
 
// Dígitos.
int dig1 = 19;
int dig2 = 16;
int dig3 = 15;
int dig4 = 9;
 
int buttonState = 0;

byte segmentos[7] = { a,b,c,d,e,f,g };
byte digitos[4] = { dig1,dig2,dig3,dig4 };
 
// Array de bits dos números
byte bitsNumeros[4][7] = { { 0,1,1,1,1,1,0 },  // = U
                            { 1,0,0,1,1,1,1 },  // = E
                            { 1,1,0,0,1,1,1 },  // = P
                            { 1,1,1,1,1,1,1 },  // = B
                          };
// Atributos de acumuladores.
int acm = 0;
int acmNumeros = 0;
int acmSegmentos = 0;

// Habilitar dígito.
void habilitarDigito(int digito)
{
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
void desabilitarDigitos()
{
      digitalWrite(dig1, HIGH);
      digitalWrite(dig2, HIGH);
      digitalWrite(dig3, HIGH);
      digitalWrite(dig4, HIGH);    
}

void setup()
{
    pinMode(dp, OUTPUT);
 
    // Iniciando pinos do arduino.
    for(acm=0; acm < sizeof(segmentos); acm++)     
        pinMode(segmentos[acm], OUTPUT);
        
    // Iniciando pinos do arduino.
    for(acm=0; acm < sizeof(digitos); acm++)     
        pinMode(digitos[acm], OUTPUT);
    
}
 
void loop()
{
    digitalWrite(dp, HIGH);
    desabilitarDigitos();
    habilitarDigito(1);
    construirSegmentosDigitos(0);
    delay(5);
    desabilitarDigitos();
    habilitarDigito(2);
    construirSegmentosDigitos(1);
    delay(5);
    desabilitarDigitos();
    habilitarDigito(3);
    construirSegmentosDigitos(2);
    delay(5);
    desabilitarDigitos();
    habilitarDigito(4);
    construirSegmentosDigitos(3);
    delay(5);
}

// Imprime o número no display a partir dos segmentos do array.
void construirSegmentosDigitos(int numero)
{
      for (acmSegmentos=0; acmSegmentos < 7; acmSegmentos++){ // Com 7 segmentos.
          if (bitsNumeros[numero][acmSegmentos] == 1){
              digitalWrite(segmentos[acmSegmentos], HIGH);
          } else {
              digitalWrite(segmentos[acmSegmentos], LOW);
          }
      }
}
