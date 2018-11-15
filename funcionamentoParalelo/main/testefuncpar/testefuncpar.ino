#include <funcionamentoParalelo.h>
void setup() {
  // put your setup code here, to run once:
inicializacao();
attachInterrupt(digitalPinToInterrupt(sensor2), esteira1, FALLING);
attachInterrupt(digitalPinToInterrupt(sensor8), esteira2, FALLING);
attachInterrupt(digitalPinToInterrupt(sensor6), esteira3, FALLING);
attachInterrupt(digitalPinToInterrupt(sensor7), desligaEsteira2Tras, FALLING);
attachInterrupt(digitalPinToInterrupt(sensor3), desligaEsteira3Frente, FALLING);
attachInterrupt(digitalPinToInterrupt(sensor4), desligaEsteira3Tras, FALLING);
attachInterrupt(digitalPinToInterrupt(sensor1), desligaEsteira3Frente, FALLING);
motor1Stop();
motor2Stop();
motor3Stop();

}

void loop() {
  // put your main code here, to run repeatedly:
guardaCor();
//imprimeCor();
imprimeEstado(sensor4);
}
