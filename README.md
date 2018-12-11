Leia

Este documento descreve o modo de utilização dos códigos desenvolvidos no Projeto Final de Curso do aluno Filipe Augusto Azevedo Caixeta, intitulado "Desenvolvimento de uma planta didática para ensino de controle de sistemas a eventos discretos".

CÓDIGOS:

1) FSM
        Biblioteca para implementação de máquina de estados finitos em Arduino, utilizada no trabalho para declaração dos autômatos.

2) motorbib
        Biblioteca para Arduino desenvolvida nesse trabalho para controle dos motores.
        Principais funções:
                - void motorXForward()     
                - void motorXBackward()    
                - void motorXStop()
                - void servoAbre()
                - void servoFecha()
                em que X é o número do motor 

3) funcionamentoParalelo
        Biblioteca para Arduino desenvolvida nesse trabalho para inicialização de sensores e motores
        Principais funções:
                - void inicialização()

4) sensordedistancia
        Biblioteca desenvolvida para Arduino nesse trabalho para os sensores de presença
        Principais funções:
                - void inicializaInfra()
                - void imprimeEstado()
                - int estado()

5) sensordecor
        Biblioteca desenvolvida para Arduino nesse trabalho para o sensor de cor
        Principais funções:
                - void inicializaSensor()
                - int detectaCor()
                - void imprimeCor()
                - void color()

6) modo_manual_automatico
        Biblioteca desenvolvida para Arduino nesse trabalho para funcionamento do controle supervisório, com modos de operação manual e automático
        Principais funções:
                - void trigger();
                - void escolha_manual()
                - void escolha_automatica()

7) modo_manual_automatico_prioridades
        Biblioteca desenvolvida para Arduino nesse trabalho para funcionamento do controle supervisório, com modos de operação manual e automático, em que no modo automático pode-se definir uma ordem de prioridades para execução dos eventos controláveis habilitados.
 
8) Program.cs
        Código C# densenvolvido no software UltraDES para a modelagem inicial das plantas e especificações e síntese dos supervisores monolítico e modulares locais.

9) sintese_supervisores
        Código desenvolvido no softaware TCT, com auxílio da interface do Matlab, para síntese dos supervisores modulares reduzidos.
