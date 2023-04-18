#define TIPODISPLAY 1 //1 anodo, 2 catodo


#if TIPODISPLAY == 1
//Display Anodo Común
  const byte numbersDisplay[10] = {0b1000000,     //0
                            0b1111001,          //1
                            0b0100100,          //2
                            0b0110000,          //3
                            0b0011001,          //4
                            0b0010010,          //5
                            0b0000010,          //6
                            0b1111000,          //7
                            0b0000000,          //8
                            0b0010000};         //9

#elif TIPODISPLAY == 2
  const byte numbersDisplay[10] = {0b0111111,     //0
                            0b0000110,          //1
                            0b1011011,          //2
                            0b1001111,          //3
                            0b1100110,          //4
                            0b1101101,          //5
                            0b1111101,          //6
                            0b0000111,          //7
                            0b1111111,          //8
                            0b1101111};         //9  
#else 

  #define TIPODISPLAY  1
  
#endif
//Declaracion de pines botones//
const int t1up = 2;
const int t1down = 3;
const int t2up = 4;
const int t2down = 5;
const int reset = 6;

//Declaracion de pines 7 segments//
const int a = 7;
const int b = 8;
const int c = 9;
const int d = 10;
const int e = 11;
const int f = 12;
const int g = 13;

//Declaracion de pines de control 7 segments//
const int ctlr1 = 14;
const int ctlr2 = 15;
const int ctlr3 = 16;
const int ctlr4 = 17;

//Declaracion de pines de leds

const int LT1 = 18;
const int LT2 = 19;

//Declaracion de numeros en 7 segmentos


//Variables dinamicas
int team1 = 0;
int team2 = 0;
int pt1 = 0;
int pt2 = 0;
//punteros variables dinamicas 
int * pteam1 = &team1;
int * pteam2 = &team2;
int * ppt1 = &pt1;
int * ppt2 = &pt2;

void setup() {
    //Declaracion pines de salida
    for(int i = 7;i<20;i++){
      pinMode( i , OUTPUT);
    }

    //Declaracion pines de entrada
    for(int i = 2;i<7;i++){
      pinMode( i , INPUT);
    }
    
}

void loop() {


  cifras(*pteam1,*pteam2);
  contarPuntos(pteam1, pteam2, ppt1, ppt2);
  


}

void cifras (int pt1, int pt2){
  int unidades1 = 0, decenas1 = 0;
  int unidades2 = 0, decenas2 = 0;
  if (pt1 < 10){
    decenas1 = 0;
    unidades1 = pt1;
  }else{
    decenas1 = pt1 /10;
    unidades1 = pt1 % 10 ;
  }
  if (pt2 < 10){
    decenas2 = 0;
    unidades2 = pt2;
  }else{
    decenas2 = pt2 /10;
    unidades2 = pt2 % 10 ;
  }
  
  mostrarNumero(unidades1,unidades2,decenas1,decenas2);

}


void mostrarNumero (int u1, int u2, int d1, int d2){
  int valores [4] = {d1,u1,d2,u2};
  int l=0;
  for (int i= 14; i < 18;i++){
    if(TIPODISPLAY == 1){
    digitalWrite(i, HIGH);
    int j = 0;
      for(int k=7; k< 14; k++){
      digitalWrite(k, bitRead(numbersDisplay[valores[l]],j));
      j++;
      }
    l++;
    delay(1);
    digitalWrite(i,LOW);
    }else {
      digitalWrite(i, LOW);
    int j = 0;
      for(int k=7; k< 14; k++){
      digitalWrite(k, bitRead(numbersDisplay[valores[l]],j));
      j++;
      }
    l++;
    delay(1);
    digitalWrite(i,HIGH);
    }
  }
}
void contarPuntos(int *pteam1, int *pteam2, int *ppt1, int *ppt2){
  //Code for point counting of team 1
  if (*ppt1 == 0 && validarBoton(t1up) == 1){
    * ppt1 = 1;
    * ppt2 = 0;
  }else if( *ppt1 == 1 && validarBoton(t1up) == 1){
    *pteam1 = *pteam1 + 1;
    
  } 
  else if (validarBoton(t1down)==1) {
    *pteam1 = *pteam1 - 1;
  }

//Contar puntos team 2
 if (*ppt2==0 && validarBoton(t2up)==1){
    *ppt2 = 1;
    *ppt1 = 0;
  }else if(*ppt2==1 && validarBoton(t2up) == 1 ){
    *pteam2 = *pteam2 + 1;

  }else if(validarBoton(t2down)==1){
    *pteam2 = *pteam2 - 1;
  
  }

  if (validarBoton(reset) == 1){
    *ppt1 = 0;
    *ppt2 = 0;
    *pteam1 = 0;
    *pteam2 = 0;
    }
  if (*ppt1 == 1){
    digitalWrite(LT1,HIGH);
    }else{
    digitalWrite(LT2,HIGH);
    }
  }

int validarBoton(int pin){
  if(digitalRead(pin)==HIGH){
    delay(30);
    if(digitalRead(pin)==HIGH){
      do{

      }while(digitalRead(pin)==HIGH);
      return 1;

    }else{

      return 0;

    }

  }
}



