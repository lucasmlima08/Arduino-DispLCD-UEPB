// Ponto 
int dp = 5;
 
// Segmentos
int a = 2;
int b = 4;
int c = 10;
int d = 9;
int e = 8;
int f = 3;
int g = 6;
 
// Digitos
int dig1 = 11;
int dig2 = 7;
int dig3 = 12;
int dig4 = 1;
 
int buttonState = 0;
 
// Array de segmentos.
byte segmentos[7] = { a,b,c,d,e,f,g };

// Array de dígitos.
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


boolean infinito = true;
void setup()
{
    // Iniciando pinos do arduino.
    for(acm=1; acm <= 12; acm++)     
        pinMode(acm,OUTPUT);
    
    while (infinito == true)
        loopInfinito();
}
 
void loop(){}

// Imprime o número no display a partir dos segmentos do array.
void construirSegmentosDigitos(int numero)
{
      for (acmSegmentos=0; acmSegmentos < 7; acmSegmentos++) // Com 7 segmentos.
      {
          if (bitsNumeros[numero][acmSegmentos] == 1)
              digitalWrite(segmentos[acmSegmentos], HIGH);
          else
              digitalWrite(segmentos[acmSegmentos], LOW);
      }
}
// Laço de número até o valor máximo.
void loopInfinito(){
    /*desabilitarDigitos();
    habilitarDigito(1);
    construirSegmentosDigitos(0);
    delay(3);
    desabilitarDigitos();
    habilitarDigito(2);
    construirSegmentosDigitos(1);
    delay(3);
    desabilitarDigitos();
    habilitarDigito(3);
    construirSegmentosDigitos(2);
    delay(3);
    desabilitarDigitos();
    habilitarDigito(4);*/
    construirSegmentosDigitos(3);
    //delay(3);
}
