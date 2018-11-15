 // Biblioteca para manipulação de Autômatos
#include "Fsm.h"
// Biblioteca para lidar com sensores e motores
#include "funcionamentoParalelo.h"

// Define um valor inteiro para cada evento
#define a1 11
#define a2 21
#define a3 23
#define a4 31
#define a5 33
#define a6 41
#define b1 12
#define b2 22
#define b3 24
#define b4 32
#define b5 34
#define b6 42
#define bp 62
#define bg 64
#define ba 54
#define bv 52
#define chave 37

volatile int cor = 5;
volatile int tam; 

// Variavel que recebe a informacao de qual botao foi acionado no modo manual
char botao;

//Variavel que define a prioridade de execucao dos eventos:
//prioridade[0] é a prioridade de a1, prioridade[1] é a prioridade de a2, e assim sucessivamente...
//Quanto maior o valor correspondente ao evento, maior é a prioridade dele 
//Indica-se usar valores de 1 a 6 para definir-se a prioridade dos eventos
//Os valores das prioridades devem ser diferentes
int prioridade[] = {1,2,3,4,5,6};

//variavel temporária que guarda qual é o evento de maior prioridade enquanto compara com as outras posicoes do vetor prioridade
int maior = 0;

//Vetor em que é verificado quais eventos estão habilitados
int vetor_escolha[6];

// Desabilitações de cada um dos supervisores (são atualizadas a cada estado)
uint8_t des_sup1;
uint8_t des_sup2;
uint8_t des_sup3;
uint8_t des_sup4;
uint8_t des_sup5;
uint8_t des_sup6;
uint8_t des_sup7;
uint8_t des_sup;

// Funções a serem executadas nos respectivos Estados
void acao_estado1_G1()
{
  motor1Stop();
}
void acao_estado2_G1()
{
  motor1Forward();
}
void acao_estado1_G2()
{
  motor2Stop();
}
void acao_estado2_G2()
{
  motor2Forward();
}
void acao_estado3_G2()
{
  motor2Backward();
}
void acao_estado1_G3()
{
  motor3Stop();
  servoAbre();
}
void acao_estado2_G3()
{
  motor3Forward();
}
void acao_estado3_G3()
{
  motor3Backward();
}
void acao_estado4_G3()
{
  servoFecha();
  delay(200);
  motor3Forward();
}

void acao_estado1_G5()
{
}
void acao_estado1_G6()
{
}

void acao_estado1_S1()
{
  //desabilita a4
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,1);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 1");
}
void acao_estado2_S1()
{
  // desabilita a4
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,1);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 2");
}
void acao_estado3_S1()
{
  // desabilita a4
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,1);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 3");
}
void acao_estado4_S1()
{
  // todos estado habilitados
  bitWrite(des_sup1,0,0);
  bitWrite(des_sup1,1,0);
  bitWrite(des_sup1,2,0);
  bitWrite(des_sup1,3,0);
  bitWrite(des_sup1,4,0);
  bitWrite(des_sup1,5,0);
  Serial.println("S1 : ESTADO 4");
}
void acao_estado1_S2()
{
  //desabilita a3
  bitWrite(des_sup2,0,0);
  bitWrite(des_sup2,1,0);
  bitWrite(des_sup2,2,1);
  bitWrite(des_sup2,3,0);
  bitWrite(des_sup2,4,0);
  bitWrite(des_sup2,5,0);
  Serial.println("S2 : ESTADO 1");
}
void acao_estado2_S2()
{
  //desabilita a3
  bitWrite(des_sup2,0,0);
  bitWrite(des_sup2,1,0);
  bitWrite(des_sup2,2,1);
  bitWrite(des_sup2,3,0);
  bitWrite(des_sup2,4,0);
  bitWrite(des_sup2,5,0);
  Serial.println("S2 : ESTADO 2");
}
void acao_estado3_S2()
{
  //desabilita a3
  bitWrite(des_sup2,0,0);
  bitWrite(des_sup2,1,1);
  bitWrite(des_sup2,2,0);
  bitWrite(des_sup2,3,0);
  bitWrite(des_sup2,4,0);
  bitWrite(des_sup2,5,0);
  Serial.println("S2 : ESTADO 3");
}
void acao_estado1_S3()
{
  //desabilita a6
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,1);
  Serial.println("S3 : ESTADO 1");
}
void acao_estado2_S3()
{
  //desabilita a6
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,1);
  Serial.println("S3 : ESTADO 2");
}
void acao_estado3_S3()
{
  //desabilita a6
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,1);
  Serial.println("S3 : ESTADO 3");
}
void acao_estado4_S3()
{
  //todos eventos habilitados
  bitWrite(des_sup3,0,0);
  bitWrite(des_sup3,1,0);
  bitWrite(des_sup3,2,0);
  bitWrite(des_sup3,3,0);
  bitWrite(des_sup3,4,0);
  bitWrite(des_sup3,5,0);
  Serial.println("S3 : ESTADO 4");
}
void acao_estado1_S4()
{
  // a4, a5 e a6 desabilitados
  bitWrite(des_sup4,0,0);
  bitWrite(des_sup4,1,0);
  bitWrite(des_sup4,2,0);
  bitWrite(des_sup4,3,1);
  bitWrite(des_sup4,4,1);
  bitWrite(des_sup4,5,1);
  Serial.println("S4 : ESTADO 1");
}
void acao_estado2_S4()
{
  // a2 desabilitado
  bitWrite(des_sup4,0,0);
  bitWrite(des_sup4,1,1);
  bitWrite(des_sup4,2,0);
  bitWrite(des_sup4,3,0);
  bitWrite(des_sup4,4,0);
  bitWrite(des_sup4,5,0);
  Serial.println("S4 : ESTADO 2");
}
void acao_estado1_S5()
{
  // a5 desabilitado
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,1);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 1");
}
void acao_estado2_S5()
{
  // a5 desabilitado
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,1);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 2");
}
void acao_estado3_S5()
{
  // a5 desabilitado
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,1);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 3");
}
void acao_estado4_S5()
{
  // todos eventos habilitados
  bitWrite(des_sup5,0,0);
  bitWrite(des_sup5,1,0);
  bitWrite(des_sup5,2,0);
  bitWrite(des_sup5,3,0);
  bitWrite(des_sup5,4,0);
  bitWrite(des_sup5,5,0);
  Serial.println("S5 : ESTADO 4");
}
void acao_estado1_S6()
{
  // a2 e a3 desabilitados
  bitWrite(des_sup6,0,0);
  bitWrite(des_sup6,1,1);
  bitWrite(des_sup6,2,1);
  bitWrite(des_sup6,3,0);
  bitWrite(des_sup6,4,0);
  bitWrite(des_sup6,5,0);
  Serial.println("S6 : ESTADO 1");
}
void acao_estado2_S6()
{
  // a1 desabilitado
  bitWrite(des_sup6,0,1);
  bitWrite(des_sup6,1,0);
  bitWrite(des_sup6,2,0);
  bitWrite(des_sup6,3,0);
  bitWrite(des_sup6,4,0);
  bitWrite(des_sup6,5,0);
  Serial.println("S6 : ESTADO 2");
}


// Declara-se abaixo os estados e as FSM das Plantas

// G1 - Esteira 1
static State ESTADO1_G1(acao_estado1_G1, NULL, NULL);
static State ESTADO2_G1(acao_estado2_G1, NULL, NULL);
static Fsm G1(&ESTADO1_G1);

// G2 - Esteira 2
static State ESTADO1_G2(acao_estado1_G2, NULL, NULL);
static State ESTADO2_G2(acao_estado2_G2, NULL, NULL);
static State ESTADO3_G2(acao_estado3_G2, NULL, NULL);
static Fsm G2(&ESTADO1_G2);

// G3 - Esteira 3
static State ESTADO1_G3(acao_estado1_G3, NULL, NULL);
static State ESTADO2_G3(acao_estado2_G3, NULL, NULL);
static State ESTADO3_G3(acao_estado3_G3, NULL, NULL);
static State ESTADO4_G3(acao_estado4_G3, NULL, NULL);
static Fsm G3(&ESTADO1_G3);

// G5 - Sensor de cor
static State ESTADO1_G5(acao_estado1_G5, NULL, NULL);
static Fsm G5(&ESTADO1_G5);

// G6 - Sensor de tamanho
static State ESTADO1_G6(acao_estado1_G6, NULL, NULL);
static Fsm G6(&ESTADO1_G6);

// Declara-se abaixo os estados e as FSM dos Supervisores Modulares Locais Reduzidos

// S1 - Supervisor modular reduzido 1
static State ESTADO1_S1(acao_estado1_S1, NULL, NULL);
static State ESTADO2_S1(acao_estado2_S1, NULL, NULL);
static State ESTADO3_S1(acao_estado3_S1, NULL, NULL);
static State ESTADO4_S1(acao_estado4_S1, NULL, NULL);
static Fsm S1(&ESTADO1_S1);

// S2 - Supervisor modular reduzido 2
static State ESTADO1_S2(acao_estado1_S2, NULL, NULL);
static State ESTADO2_S2(acao_estado2_S2, NULL, NULL);
static State ESTADO3_S2(acao_estado3_S2, NULL, NULL);
static Fsm S2(&ESTADO1_S2);

// S3 - Supervisor modular reduzido 3
static State ESTADO1_S3(acao_estado1_S3, NULL, NULL);
static State ESTADO2_S3(acao_estado2_S3, NULL, NULL);
static State ESTADO3_S3(acao_estado3_S3, NULL, NULL);
static State ESTADO4_S3(acao_estado4_S3, NULL, NULL);
static Fsm S3(&ESTADO1_S3);

// S4 - Supervisor modular reduzido 4
static State ESTADO1_S4(acao_estado1_S4, NULL, NULL);
static State ESTADO2_S4(acao_estado2_S4, NULL, NULL);
static Fsm S4(&ESTADO1_S4);

// S5 - Supervisor modular reduzido 5
static State ESTADO1_S5(acao_estado1_S5, NULL, NULL);
static State ESTADO2_S5(acao_estado2_S5, NULL, NULL);
static State ESTADO3_S5(acao_estado3_S5, NULL, NULL);
static State ESTADO4_S5(acao_estado4_S5, NULL, NULL);
static Fsm S5(&ESTADO1_S5);

// S6 - Supervisor modular reduzido 6
static State ESTADO1_S6(acao_estado1_S6, NULL, NULL);
static State ESTADO2_S6(acao_estado2_S6, NULL, NULL);
static Fsm S6(&ESTADO1_S6);

void setup() {

    Serial.begin(9600);      //Porta de transmissao de informações do Nano
    Serial3.begin(9600);     //Porta de leitura de informações do Due

    pinMode(chave,INPUT);     //Definindo pino digital "chave" como de entrada. 


    // Função de transição de G1
    G1.add_transition(&ESTADO1_G1, &ESTADO2_G1,
                         a1, NULL);
    G1.add_transition(&ESTADO2_G1, &ESTADO1_G1,
                         b1, NULL);
    
    // Função de transição de G2
    G2.add_transition(&ESTADO1_G2, &ESTADO2_G2,
                         a2, NULL);
    G2.add_transition(&ESTADO1_G2, &ESTADO3_G2,
                         a3, NULL);
    G2.add_transition(&ESTADO2_G2, &ESTADO1_G2,
                         b2, NULL);
    G2.add_transition(&ESTADO3_G2, &ESTADO1_G2,
                         b3, NULL);
    
    // Função de transição de G3
    G3.add_transition(&ESTADO1_G3, &ESTADO2_G3,
                         a4, NULL);
    G3.add_transition(&ESTADO1_G3, &ESTADO3_G3,
                         a5, NULL);
    G3.add_transition(&ESTADO1_G3, &ESTADO4_G3,
                         a6, NULL);                     
    G3.add_transition(&ESTADO2_G3, &ESTADO1_G3,
                         b4, NULL);
    G3.add_transition(&ESTADO3_G3, &ESTADO1_G3,
                         b5, NULL);
    G3.add_transition(&ESTADO4_G3, &ESTADO1_G3,
                         b6, NULL);
    
    // Função de transição de G5                    
    G5.add_transition(&ESTADO1_G5, &ESTADO1_G5,
                         bv, NULL);
    G5.add_transition(&ESTADO1_G2, &ESTADO1_G2,
                         ba, NULL);
    
    // Função de transição de G6
    G6.add_transition(&ESTADO1_G6, &ESTADO1_G6,
                         bp, NULL);
    G6.add_transition(&ESTADO1_G6, &ESTADO1_G6,
                         bg, NULL);
                         
    // Função de transição de S1
    S1.add_transition(&ESTADO1_S1, &ESTADO2_S1,
                         bv, NULL);
    S1.add_transition(&ESTADO2_S1, &ESTADO3_S1,
                         bp, NULL);
    S1.add_transition(&ESTADO3_S1, &ESTADO4_S1,
                         b2, NULL);                     
    S1.add_transition(&ESTADO4_S1, &ESTADO1_S1,
                         a4, NULL);
    S1.add_transition(&ESTADO2_S1, &ESTADO1_S1,
                         bg, NULL);
    
    // Função de transição de S2
    S2.add_transition(&ESTADO1_S2, &ESTADO2_S2,
                         ba, NULL);
    S2.add_transition(&ESTADO2_S2, &ESTADO3_S2,
                         bg, NULL);
    S2.add_transition(&ESTADO3_S2, &ESTADO1_S2,
                         a3, NULL);
    S2.add_transition(&ESTADO2_S2, &ESTADO1_S2,
                         bp, NULL);                     
    
    // Função de transição de S3
    S3.add_transition(&ESTADO1_S3, &ESTADO2_S3,
                         bv, NULL);
    S3.add_transition(&ESTADO2_S3, &ESTADO3_S3,
                         bg, NULL);
    S3.add_transition(&ESTADO3_S3, &ESTADO4_S3,
                         b2, NULL);                     
    S3.add_transition(&ESTADO4_S3, &ESTADO1_S3,
                         a6, NULL);                     
    S3.add_transition(&ESTADO2_S3, &ESTADO1_S3,
                         bp, NULL);
                         
    // Função de transição de S4
    S4.add_transition(&ESTADO1_S4, &ESTADO2_S4,
                         b2, NULL);
    S4.add_transition(&ESTADO2_S4, &ESTADO1_S4,
                         a5, NULL);
    S4.add_transition(&ESTADO2_S4, &ESTADO1_S4,
                         a4, NULL);
    S4.add_transition(&ESTADO2_S4, &ESTADO1_S4,
                         a6, NULL);
    
    // Função de transição de S5
    S5.add_transition(&ESTADO1_S5, &ESTADO2_S5,
                         ba, NULL);
    S5.add_transition(&ESTADO2_S5, &ESTADO3_S5,
                         bp, NULL);
    S5.add_transition(&ESTADO3_S5, &ESTADO4_S5,
                         b2, NULL);                     
    S5.add_transition(&ESTADO4_S5, &ESTADO1_S5,
                         a5, NULL);
    S5.add_transition(&ESTADO2_S5, &ESTADO1_S5,
                         bg, NULL);                     
    
    // Função de transição de S6
    S6.add_transition(&ESTADO1_S6, &ESTADO2_S6,
                         b1, NULL);                     
    S6.add_transition(&ESTADO2_S6, &ESTADO1_S6,
                         a3, NULL);                     
    S6.add_transition(&ESTADO2_S6, &ESTADO1_S6,
                         a2, NULL);
               
    
    // Inicialização dos Sensores e Motores
    inicializacao();
   
    // Interrupções que invocam funções ao acionar os sensores
    attachInterrupt(digitalPinToInterrupt(sensor2), guardaCor, RISING);
    attachInterrupt(digitalPinToInterrupt(sensor8), esteira1_to_esteira2, FALLING);
    attachInterrupt(digitalPinToInterrupt(sensor6), esteira2_to_esteira3, FALLING);
    attachInterrupt(digitalPinToInterrupt(sensor7), esteira2_end, FALLING);
    attachInterrupt(digitalPinToInterrupt(sensor3), desligaEsteira3Frente, FALLING);
    attachInterrupt(digitalPinToInterrupt(sensor4), desligaEsteira3Tras, FALLING);
    attachInterrupt(digitalPinToInterrupt(sensor1), esteira3_end, FALLING);
  
    // Desliga todos os motores
    motor1Stop();
    motor2Stop();
    motor3Stop();
    
    // Inicia o funcionamento dos automatos das plantas, iniciando no estado 1
    G1.run_machine();
    G2.run_machine();
    G3.run_machine();
    G5.run_machine();
    G6.run_machine();
    
    // Inicia o funcionamento dos automatos dos supervisores modulares, iniciando no estado 1
    S1.run_machine();
    S2.run_machine();
    S3.run_machine();
    S4.run_machine();
    S5.run_machine();
    S6.run_machine();

}

void loop() {

    if (digitalRead(chave) == HIGH) 
      {escolha_manual();}
    else
       {escolha_automatica();}

} 
