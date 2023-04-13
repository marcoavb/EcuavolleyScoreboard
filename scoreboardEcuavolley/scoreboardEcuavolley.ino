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

const byte numbersDisplayAnode[10] = {0b1000000,     //0
                            0b1111001,          //1
                            0b0100100,          //2
                            0b0110000,          //3
                            0b0011001,          //4
                            0b0010010,          //5
                            0b0000010,          //6
                            0b1111000,          //7
                            0b0000000,          //8
                            0b0010000};         //9

//Variables dinamicas
int team1 = 0;
int team2 = 0;
int pt1 = 0;
int pt2 = 0;


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
  


}
//version MIa





