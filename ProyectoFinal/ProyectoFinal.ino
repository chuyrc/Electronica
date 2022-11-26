/*
    PROYECTO "ROBOT ESQUIVA OBJETOS BLUETOOTH"
------------------------------------------------------
Materiales:
    Sensor ultrasónico HC-SR04.
    CI L293D (puente H).
    2 Motorreductores.
    Switch.
    LED Rojo.
    Fuente de alimentación de 7v a 12v.
    Jumpers/Cables.
    Microcontrolador Arduino UNO o similares.
    ProtoBoard/Placa de prototipos.
------------------------------------------------------
GitHub:
https://github.com/chuyrc/Electronica.git

Video explicativo:
------------------------------------------------------
  **Si se desea utilizar otros pines de entrada y salida
  u otro microcontrolador de arduino se debe asegurar que
  la variable "habilitador" esté conectada a una salida
  digital con PWM.**

(Proyecto de código abierto)
------------------------------------------------------
*/

//  Declaración de variables
#define pinEcho 12
#define pinTrigger 11
#define habilitador 10
#define izqA 9
#define derA 8
#define izqB 7
#define derB 6

char estado = 'f'; //Inicio del programa en carro automático
int vel = 100;  //Velocidad de los motores

void setup() {
    Serial.begin(9600);
    pinMode(pinEcho,INPUT);
    pinMode(pinTrigger,OUTPUT);
    pinMode(izqA,OUTPUT);
    pinMode(izqB,OUTPUT);
    pinMode(derA,OUTPUT);
    pinMode(derB,OUTPUT);
    pinMode(13,OUTPUT);  //LED indicador de distancia
}

void loop() {

    if(Serial.available() >= 0)
        estado = Serial.read();
    
    if(estado == 'a')
        avanzar();

    if(estado == 'b')
        girar(0,1);  //giro izquierda

    if(estado == 'c')
        detener();

    if(estado == 'd')
        girar(1,0);  //giro derecha

    if(estado == 'e')
        retroceder();

    if(estado == 'f') {
        if(comprobarDistanciaA(11)) {
            detener();
            delay(1000);
            retroceder();
            delay(444);
            detener();
            delay(300);
            girar();

            if(comprobarDistanciaA(13)) {
                detener();
                delay(400);
                girar();
                delay(400);
                girar();
            }
        }
        avanzar();
        delay(200);
    }
}

//  Devuelve la distancia con el sensor ultrasónico
long calcularDistancia() {
    digitalWrite(pinTrigger,LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigger,HIGH);
    delayMicroseconds(10);

    long x = pulseIn(pinEcho,HIGH);
    long y = (x / 2) / 29;

    return y;
}

//  Decidimos a qué distancia debe detenerse y girar
bool comprobarDistanciaA(long x) {
    long distancia = calcularDistancia();

    if(distancia <= x && distancia >= 1) {
        digitalWrite(13,1);
        delay(100);
        digitalWrite(13,0);
        delay(100);
        digitalWrite(13,1);
        delay(100);
        digitalWrite(13,0);

        return true;
    }

    return false;
}

//  Métodos para los motores
void avanzar() {
    analogWrite(habilitador,vel);
    digitalWrite(derA,1);
    digitalWrite(izqA,0);
    digitalWrite(derB,1);
    digitalWrite(izqB,0);
}

void retroceder() {
    analogWrite(habilitador,vel);
    digitalWrite(derA,0);
    digitalWrite(izqA,1);
    digitalWrite(derB,0);
    digitalWrite(izqB,1);
}

void girar() {
    analogWrite(habilitador,vel);
    digitalWrite(derA,1);
    digitalWrite(izqA,0);
    digitalWrite(derB,0);
    digitalWrite(izqB,1);
    delay(480);   //Se debe de calibrar para un correcto giro
    detener();
}

//  Sobrecarga del método girar
void girar(int x,int y) {  //(1,0) = derecha | (0,1) = izquierda
    analogWrite(habilitador,vel);
    digitalWrite(derA,x);
    digitalWrite(izqA,y);
    digitalWrite(derB,y);
    digitalWrite(izqB,x);
}

void detener() {
    analogWrite(habilitador,0);
}