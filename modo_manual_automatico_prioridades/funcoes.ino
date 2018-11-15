// Funções para triggar todas as máquinas simultaneamente
void trigger_a1()
{
  G1.trigger(a1);
  G2.trigger(a1);
  G3.trigger(a1);
  G5.trigger(a1);
  G6.trigger(a1);
  S1.trigger(a1);
  S2.trigger(a1);
  S3.trigger(a1);
  S4.trigger(a1);
  S5.trigger(a1);
  S6.trigger(a1);
  bitWrite(des_sup7,0,1);
}
void trigger_a2()
{
  G1.trigger(a2);
  G2.trigger(a2);
  G3.trigger(a2);
  G5.trigger(a2);
  G6.trigger(a2);
  S1.trigger(a2);
  S2.trigger(a2);
  S3.trigger(a2);
  S4.trigger(a2);
  S5.trigger(a2);
  S6.trigger(a2);
  bitWrite(des_sup7,1,1);
  bitWrite(des_sup7,2,1);
  
}
void trigger_a3()
{
  G1.trigger(a3);
  G2.trigger(a3);
  G3.trigger(a3);
  G5.trigger(a3);
  G6.trigger(a3);
  S1.trigger(a3);
  S2.trigger(a3);
  S3.trigger(a3);
  S4.trigger(a3);
  S5.trigger(a3);
  S6.trigger(a3);
  bitWrite(des_sup7,2,1);
  bitWrite(des_sup7,1,1);
}
void trigger_a4()
{
  G1.trigger(a4);
  G2.trigger(a4);
  G3.trigger(a4);
  G5.trigger(a4);
  G6.trigger(a4);
  S1.trigger(a4);
  S2.trigger(a4);
  S3.trigger(a4);
  S4.trigger(a4);
  S5.trigger(a4);
  S6.trigger(a4);
  bitWrite(des_sup7,3,1);
  bitWrite(des_sup7,4,1);
  bitWrite(des_sup7,5,1);
}
void trigger_a5()
{  
  G1.trigger(a5);
  G2.trigger(a5);
  G3.trigger(a5);
  G5.trigger(a5);
  G6.trigger(a5);
  S1.trigger(a5);
  S2.trigger(a5);
  S3.trigger(a5);
  S4.trigger(a5);
  S5.trigger(a5);
  S6.trigger(a5);
  bitWrite(des_sup7,4,1);
  bitWrite(des_sup7,3,1);
  bitWrite(des_sup7,5,1);
}
void trigger_a6()
{  
  G1.trigger(a6);
  G2.trigger(a6);
  G3.trigger(a6);
  G5.trigger(a6);
  G6.trigger(a6);
  S1.trigger(a6);
  S2.trigger(a6);
  S3.trigger(a6);
  S4.trigger(a6);
  S5.trigger(a6);
  S6.trigger(a6);
  bitWrite(des_sup7,5,1);
  bitWrite(des_sup7,4,1);
  bitWrite(des_sup7,3,1);
}

void trigger_b1()
{
  G1.trigger(b1);
  G2.trigger(b1);
  G3.trigger(b1);
  G5.trigger(b1);
  G6.trigger(b1);
  S1.trigger(b1);
  S2.trigger(b1);
  S3.trigger(b1);
  S4.trigger(b1);
  S5.trigger(b1);
  S6.trigger(b1);
  bitWrite(des_sup7,0,0);
}

void trigger_b2()
{
  G1.trigger(b2);
  G2.trigger(b2);
  G3.trigger(b2);
  G5.trigger(b2);
  G6.trigger(b2);
  S1.trigger(b2);
  S2.trigger(b2);
  S3.trigger(b2);
  S4.trigger(b2);
  S5.trigger(b2);
  S6.trigger(b2);
  bitWrite(des_sup7,1,0);
  bitWrite(des_sup7,2,0);
}
void trigger_b3()
{
  G1.trigger(b3);
  G2.trigger(b3);
  G3.trigger(b3);
  G5.trigger(b3);
  G6.trigger(b3);
  S1.trigger(b3);
  S2.trigger(b3);
  S3.trigger(b3);
  S4.trigger(b3);
  S5.trigger(b3);
  S6.trigger(b3);
  bitWrite(des_sup7,1,0);
  bitWrite(des_sup7,2,0);
}

void trigger_b4()
{
  G1.trigger(b4);
  G2.trigger(b4);
  G3.trigger(b4);
  G5.trigger(b4);
  G6.trigger(b4);
  S1.trigger(b4);
  S2.trigger(b4);
  S3.trigger(b4);
  S4.trigger(b4);
  S5.trigger(b4);
  S6.trigger(b4);
  bitWrite(des_sup7,3,0);
  bitWrite(des_sup7,4,0);
  bitWrite(des_sup7,5,0);
}
void trigger_b5()
{
  G1.trigger(b5);
  G2.trigger(b5);
  G3.trigger(b5);
  G5.trigger(b5);
  G6.trigger(b5);
  S1.trigger(b5);
  S2.trigger(b5);
  S3.trigger(b5);
  S4.trigger(b5);
  S5.trigger(b5);
  S6.trigger(b5);
  bitWrite(des_sup7,4,0);
  bitWrite(des_sup7,3,0);
  bitWrite(des_sup7,5,0);
}

void trigger_b6()
{
  G1.trigger(b6);
  G2.trigger(b6);
  G3.trigger(b6);
  G5.trigger(b6);
  G6.trigger(b6);
  S1.trigger(b6);
  S2.trigger(b6);
  S3.trigger(b6);
  S4.trigger(b6);
  S5.trigger(b6);
  S6.trigger(b6);
  bitWrite(des_sup7,5,0);
  bitWrite(des_sup7,4,0);
  bitWrite(des_sup7,3,0);

}

void trigger_bv()
{
  G1.trigger(bv);
  G2.trigger(bv);
  G3.trigger(bv);
  G5.trigger(bv);
  G6.trigger(bv);
  S1.trigger(bv);
  S2.trigger(bv);
  S3.trigger(bv);
  S4.trigger(bv);
  S5.trigger(bv);
  S6.trigger(bv);

}

void trigger_ba()
{
  G1.trigger(ba);
  G2.trigger(ba);
  G3.trigger(ba);
  G5.trigger(ba);
  G6.trigger(ba);
  S1.trigger(ba);
  S2.trigger(ba);
  S3.trigger(ba);
  S4.trigger(ba);
  S5.trigger(ba);
  S6.trigger(ba);

}

void trigger_bp()
{
  G1.trigger(bp);
  G2.trigger(bp);
  G3.trigger(bp);
  G5.trigger(bp);
  G6.trigger(bp);
  S1.trigger(bp);
  S2.trigger(bp);
  S3.trigger(bp);
  S4.trigger(bp);
  S5.trigger(bp);
  S6.trigger(bp);

}

void trigger_bg()
{
  G1.trigger(bg);
  G2.trigger(bg);
  G3.trigger(bg);
  G5.trigger(bg);
  G6.trigger(bg);
  S1.trigger(bg);
  S2.trigger(bg);
  S3.trigger(bg);
  S4.trigger(bg);
  S5.trigger(bg);
  S6.trigger(bg);
}


void escolha_manual()
{
  
  des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;
  
  //Verifica se algum botão da IHM foi acionado e se o evento controlável está habilitado
  if (Serial3.available() > 0) {
    // lê o dado recebido:
    botao = Serial3.read();

    if (botao == 'e')
    {   
        if (bitRead(des_sup,0) == 0)  
        {
            if (estado(sensor9) == 1)
                  {trigger_a1();   des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;}
        }          
    }
    if (botao == 'm')
    {
        if (bitRead(des_sup,1) == 0)
        {trigger_a2();  des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;}
    }
    if (botao == 's')
    {
        if (bitRead(des_sup,2) == 0)
        {trigger_a3();  des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;}
    }
    if (botao == '0')
    {
        if (bitRead(des_sup,3) == 0)
        {trigger_a4();  des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;}
    }
    if (botao == '1')
    {
        if (bitRead(des_sup,4) == 0)
        {trigger_a5();  des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;}
    }
    if (botao == 'f')
    {
        if (bitRead(des_sup,5) == 0)
        {trigger_a6();  des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;}
    }
  }
}

void escolha_automatica()
{
    //Desabilitaçao geral que são atualizadas a todo momento
    des_sup = (des_sup1 | des_sup2 | des_sup3 | des_sup4 | des_sup5 | des_sup6 | des_sup7) ;
        
    //Cria o vetor (vetor_escolha) com os eventos habilitados
    for (int i = 0; i < 6; i++)
    {
      if (bitRead(des_sup,i) == 0)
      {
          vetor_escolha[i] = prioridade[i];
      }
      else
      {
          vetor_escolha[i] = 0;
      }
    
    }
    
    //Verifica qual dos eventos habilitados tem prioridade
    for ( int i = 0; i < 6; i ++)
    {
         if (vetor_escolha[i] > maior)
         {
            maior = vetor_escolha[i];
         }
    }
    
    if ( maior == prioridade[0] )
    {
        trigger_a1();
    }
    if ( maior == prioridade[1] )
    {
      trigger_a2();  
    }
    if ( maior == prioridade[2] )
    {
      trigger_a3(); 
    }
    if ( maior == prioridade[3] )
    {
      trigger_a4(); 
    }
    if ( maior == prioridade[4] )
    {
      trigger_a5();
    }
    if ( maior == prioridade[5] )
    {
      trigger_a6();
    }

}

// Verifica qual cor está sendo lida pelo sensor
void guardaCor()
{
  if (detectaCor() == 10)
  //cor = vermelho;
    {trigger_bv();}
  else
    //cor = azul;
    {trigger_ba();}
}

// liga a esteira 2
void esteira1_to_esteira2()
{
  //fim de curso da esteira 1
  if (estado(sensor5) == 0)
    {trigger_bp();}            //tam = pequeno
  if (estado(sensor5) == 1)
    {trigger_bg();}            //tam = grande 
    
  trigger_b1(); 
}

// desliga a esteira 2
void esteira2_to_esteira3()
  // fim de curso da esteira 2 andando para FRENTE
  {trigger_b2();}

void esteira2_end()
// fim de curso da esteira 2 andando para TRAS
// objeto grande e azul
   {trigger_b3();}

void desligaEsteira3Frente()
// fim de curso da esteira 3 andando para FRENTE
// objeto pequeno e vermelho armazenado
   {trigger_b4();}

void desligaEsteira3Tras()
// fim de curso da esteira 3 andando para TRAS
// objeto pequeno e azul armazenado
   {trigger_b5();}

void esteira3_end()
// objeto armazenado pelo Servo Motor
// objeto grande e vermelho
   {trigger_b6();}

