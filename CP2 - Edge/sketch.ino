#include <DHT.h>
#include <LiquidCrystal.h>

// Aqui estamos "chamando" algumas bibliotecas que ajudam o nosso código a fazer certas coisas, como ler sensores e mostrar informações em um visor.

DHT dht(13, DHT22); // Estamos dizendo ao programa onde está conectado o sensor de temperatura e umidade.

int ledVerde = 7; // Estamos dizendo ao programa onde estão conectados os LEDs de cor verde, amarela e vermelha.
int ledAmarelo = 6;
int ledVermelho = 5;

int som = 12; // Aqui estamos dizendo onde está conectado o componente que faz o som.

int sensorLDR = A5; // Estamos dizendo onde está conectado o sensor de luz.
LiquidCrystal lcd (11, 10, 9, 8, 4, 3); // Estamos configurando o visor para mostrar informações.

long tempoAnterior = 0; // Esta variável é usada para contar o tempo.

void setup()
{
  // Aqui estamos configurando os pinos do Arduino para serem usados como entrada ou saída.
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(som, OUTPUT);
  pinMode(sensorLDR, INPUT);
  
  // Aqui estamos preparando o sensor de temperatura e umidade e o visor para funcionarem.
  dht.begin();
  lcd.begin(16,2); // O visor tem 16 "casinhas" de largura e 2 "andares" de altura.
  Serial.begin(9600); // Isto é usado para enviar mensagens para um computador, mas não estamos usando muito aqui.
}

void loop()
{
  // Aqui começa o que o programa vai fazer de novo e de novo.
  
  ldr(); // Primeiro, vamos verificar a luz usando o sensor LDR.
  delay(1000); // Vamos esperar um pouco para dar tempo de fazer as medições.
  
  Temperatura(); // Agora, vamos verificar a temperatura do ambiente.
  delay(1000); // Esperamos de novo um pouco.
  
  Humidade(); // Por fim, vamos verificar a umidade do ambiente.
}

void ldr(){
  int leitura = analogRead(sensorLDR); // Aqui estamos lendo o quanto de luz tem por perto.
  Serial.print("Leitura: ");
  Serial.println(leitura); // Isso só é útil se estivermos conectados a um computador para ver as mensagens.

  // Agora, dependendo de quanto de luz tem, vamos fazer algo diferente:
  
  if(analogRead(sensorLDR) > 600){ // Se for muita luz...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Luz ambiente ok!"); // ...dizemos que está tudo bem com a luz.
    noTone(som); // Paramos qualquer som que esteja tocando.
    digitalWrite(ledVerde, HIGH); // E acendemos o LED verde.
    digitalWrite(ledAmarelo, LOW); // E apagamos os outros LEDs.
    digitalWrite(ledVermelho, LOW);
  }  
  else if (analogRead(sensorLDR) > 120) { // Se a luz estiver na metade...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ambiente a meia");
    lcd.setCursor(0,1);
    lcd.print("luz!"); // ...dizemos que a luz está na metade.
    digitalWrite(ledAmarelo, HIGH); // Acendemos o LED amarelo.
    digitalWrite(ledVerde, LOW); // E apagamos os outros LEDs.
    digitalWrite(ledVermelho, LOW);
    tone(som, 261); // E fazemos um som de alerta.
    digitalWrite(som, HIGH); // E ligamos o componente que faz o som.
    
    if (millis() >= tempoAnterior + 3000){ // Esperamos um pouco...
      noTone(som); // ...e paramos o som.
      digitalWrite(som, LOW); // E desligamos o componente de som.
      delay(3000); // Esperamos mais um pouco.
    }
  }
  else{ // Se estiver escuro...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ambiente muito");
    lcd.setCursor(0,1);
    lcd.print("claro!"); // ...dizemos que está muito escuro.
    digitalWrite(ledVermelho, HIGH); // Acendemos o LED vermelho.
    digitalWrite(ledAmarelo, LOW); // E apagamos os outros LEDs.
    digitalWrite(ledVerde, LOW);
    tone(som, 261); // Fazemos um som de alerta.
    digitalWrite(som, HIGH); // E ligamos o componente de som.
  }
}

void Temperatura(){
  float tempSum = 0;
  float temperature = dht.readTemperature(); // Lemos a temperatura.

  if(millis() >= tempoAnterior + 1000){ // Esperamos um pouco.
    for (int i = 0; i < 5; i++) { // Fazemos isso 5 vezes...
      tempSum += temperature; // ...e somamos a temperatura.
      delay(1000); // Esperamos mais um pouco.
    }
  }
  float tempMedia = tempSum / 5; // Tiramos a média.
  float temperatura = dht.readTemperature(); // Lemos a temperatura de novo.
  Serial.print("Temperatura = ");
  Serial.println(temperatura); // Mais mensagens para o computador.

  if (tempMedia > 10 && tempMedia < 15){ // Se a temperatura estiver boa...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperatura OK"); // ...dizemos que está tudo ok.
    lcd.setCursor(0,1);
    lcd.print(tempMedia);
    delay(1000); // Esperamos um pouco.
  }
  else if (tempMedia > 15){ // Se estiver muito quente...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp. Alta!");
    lcd.setCursor(0,1);
    lcd.print("Temp. = ");
    lcd.print(tempMedia);
    lcd.print("°C"); // ...dizemos que está muito quente.
    tone(som, 261); // Fazemos um som de alerta.
    digitalWrite(som, HIGH); // E ligamos o componente de som.

    if (millis() >= tempoAnterior + 3000){ // Esperamos um pouco...
      noTone(som); // ...e paramos o som.
      digitalWrite(som, LOW); // E desligamos o componente de som.
      delay(3000); // Esperamos mais um pouco.
    }
  }
}

void Humidade(){
  float humiditySum = 0;
  float humidity = dht.readHumidity(); // Lemos a umidade.

  if(millis() >= tempoAnterior + 1000){ // Esperamos um pouco.
    for (int i = 0; i < 5; i++) { // Fazemos isso 5 vezes...
      humiditySum += humidity; // ...e somamos a umidade.
      delay(1000); // Esperamos mais um pouco.
    }
  }
  float humiMedia = humiditySum / 5; // Tiramos a média.
  float umidade = dht.readHumidity(); // Lemos a umidade de novo.
  Serial.print("Umidade = ");
  Serial.println(umidade); // Mais mensagens para o computador.

  if (humiMedia > 60 && humiMedia < 80){ // Se a umidade estiver boa...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade OK"); // ...dizemos que está tudo ok.
    lcd.setCursor(0,1);
    lcd.print(humiMedia);
    lcd.print("ºC");
    delay(5000); // Esperamos um pouco mais.
  }
  else { // Se a umidade estiver fora do normal...
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Umidade Abaixo do Normal");
    lcd.setCursor(0,1);
    lcd.print(humiMedia);
    tone(som, 261); // Fazemos um som de alerta.
    digitalWrite(som, HIGH); // E ligamos o componente de som.
    delay(3000); // Esperamos um pouco.
    noTone(som); // Paramos o som.
    digitalWrite(som, LOW); // E desligamos o componente de som.
    delay(3000); // Esperamos mais um pouco.
  }
}
