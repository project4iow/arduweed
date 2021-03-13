
// QUATRO RELES E UM HIGROMETRO

int pino_sinal_analogico = A6 ;
int rele_bomba = 4;
int rele_lampada = 5;
int porta_rele3 = 6;
int porta_rele4 = 7;

int valor_analogico;
int time_controller = 1;
int lampada_ligada = 0;
  
void setup()
{
  // SERIAL PARA PC
  Serial.begin(9600);
  
  // DEFINE PINO DE INPUT  DO HIGROMETRO
  pinMode(pino_sinal_analogico, INPUT);

  // DEFINE SAIDAS PARA RELE
  pinMode(rele_bomba, OUTPUT); 
  pinMode(rele_lampada, OUTPUT);
  pinMode(porta_rele3, OUTPUT); 
  pinMode(porta_rele4, OUTPUT);
}
   
void loop()
{
  // LEITURA DO HIGROMETRO
  valor_analogico = analogRead(pino_sinal_analogico);

  // DESLIGA TODOS OS RELES
  relay_off();

    // LOGICA TIMER LAMPADA
  Serial.println(time_controller);
  
  if (time_controller >= 720) {
    if (lampada_ligada == 0) {
      digitalWrite(rele_lampada, LOW);
      lampada_ligada = 1;
    }    
    else {
      digitalWrite(rele_lampada, HIGH);
      lampada_ligada = 0;
    }
  }   

  // UMIDADE BAIXA - RELE 1 LIGADO POR 1 SEGUNDOS, PARA BOMBA DAGUA
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Umidade Baixa");
    Serial.println(valor_analogico);
    digitalWrite(rele_bomba, LOW);
    delay(1000);
    digitalWrite(rele_bomba, HIGH);
  }

  // UMIDADE IDEAL - MOTOR DESLIGADO
  if (valor_analogico > 500 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada");
    Serial.println(valor_analogico);
  }

  // UMIDADE ALTA - MOTOR DESLIGADO
  if (valor_analogico < 500)
  {
    Serial.println(" Status: Umidade alta");
    Serial.println(valor_analogico);
  }

  delay(60000);
  time_controller = time_controller + 1;
  
}

void relay_off()
{
  digitalWrite(rele_bomba, HIGH);
  digitalWrite(rele_lampada, HIGH);
  digitalWrite(porta_rele3, HIGH);
  digitalWrite(porta_rele4, HIGH);
  }
