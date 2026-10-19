#include <Wire.h>

//endereço I2C
#define I2C_SLAVE_ADDR 0x08

void setup() {
  //inicia a biblioteca wire no I2C no endereco
  Wire.begin(I2C_SLAVE_ADDR);
  
  //função de retorno funciona ao receber dados
  Wire.onReceive(receberDados);
  
  //pino do led da placa como saida
  pinMode(LED_BUILTIN, OUTPUT);
  
  //LED começa desligado
  digitalWrite(LED_BUILTIN, LOW);
  
  // comunicação serial
  Serial.begin(9600);
}

void loop() {
}

//ligado automaticamente quando a raspberry manda bytes
//quantidade armazena o número de bytes do barramento
void receberDados(int quantidade) {
  while (Wire.available()) {
    // leitura do byte 
    int comando = Wire.read();
    
    Serial.print("Comando recebido: ");
    Serial.println(comando);
    
    //a ideia é que quando for 1, o led liga e quando for 0 desliga
    if (comando == 1) {
      digitalWrite(LED_BUILTIN, HIGH);} 
      
    else if (comando == 0) {
      digitalWrite(LED_BUILTIN, LOW);}
  }
}
