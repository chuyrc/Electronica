/*
    PROYECTO "ROBOT ESQUIVA OBJETOS"
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
  las variables "enableA" y "enableB" estén conectadas
  a salidas digitales con PWM.**

(Proyecto de código abierto)
------------------------------------------------------
*/

//  Declaración de variables
#define pinEcho 12
#define pinTrigger 11
#define enableA 10
#define enableB 9
#define izqA 8
#define derA 7
#define izqB 6
#define derB 5
#define estadoSwitch 4

int vel = 100;  //Velocidad de los motores

void setup() {
    pinMode(estadoSwitch,INPUT_PULLUP);  //Resistencia pull up activa
    pinMode(pinEcho,INPUT);
    pinMode(pinTrigger,OUTPUT);
    pinMode(izqA,OUTPUT);
    pinMode(izqB,OUTPUT);
    pinMode(derA,OUTPUT);
    pinMode(derB,OUTPUT);
    pinMode(13,OUTPUT);  //LED indicador de distancia
}

void loop() {
    //if(digitalRead(estadoSwitch) == 1) {
        if(comprobarDistanciaA(8)) {
            detener();
            retroceder();
            girar();

            if(comprobarDistanciaA(10)) {
                detener();
                delay(400);
                girar();
                delay(400);
                girar();
            }
        }
        avanzar();

    //}else {
      //  detener();
    //}
    delay(200);
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
    analogWrite(enableA,vel);
    analogWrite(enableB,vel);
    digitalWrite(derA,1);
    digitalWrite(izqA,0);
    digitalWrite(derB,1);
    digitalWrite(izqB,0);
}

void retroceder() {
    analogWrite(enableA,vel);
    analogWrite(enableB,vel);
    digitalWrite(derA,0);
    digitalWrite(izqA,1);
    digitalWrite(derB,0);
    digitalWrite(izqB,1);
    delay(444);
    analogWrite(enableA,0);
    analogWrite(enableB,0);
    delay(500);
}

void girar() {
    analogWrite(enableA,vel);
    analogWrite(enableB,vel);
    digitalWrite(derA,1);
    digitalWrite(izqA,0);
    digitalWrite(derB,0);
    digitalWrite(izqB,1);
    delay(480);   //Se debe de calibrar para un correcto giro
    detener();
}

void detener() {
    analogWrite(enableA,0);
    analogWrite(enableB,0);
    digitalWrite(derA,0);
    digitalWrite(izqA,0);
    digitalWrite(derB,0);
    digitalWrite(izqB,0);
    delay(1500);
}