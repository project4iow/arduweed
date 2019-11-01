// Portas
const int higrometro = A6;
const int led_vermelho = 2;
const int led_amarelo = 3;
const int led_verde = 4;
const int rele = 6;

// Variaveis programa
int intensidade = 0;

void setup()
{
  pinMode(higrometro, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(rele, OUTPUT);
}

void loop()
{
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
  digitalWrite(rele, HIGH);

  intensidade = analogRead(higrometro);
  //intensidade = map(intensidade, 1023, 0, 0, 100);

  if (intensidade > 0 && intensidade < 400) {
    digitalWrite(led_verde, HIGH);
  }
  
  if (intensidade > 400 && intensidade < 800) {
    digitalWrite(led_amarelo, HIGH);
  }
   
  if (intensidade > 800 && intensidade < 1024) {
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(rele, LOW);
  }
  delay(1000);

}
