/*
    PROYECTO "ROBOT ESQUIVA OBJETOS"

Materiales:
    Sensor ultrasonico HC-SR04
    CI L293D (puente H)
    2 Motorreductores
    Switch
    LED Rojo
    Pila de 9v
    Jumpers/Cables
    Placa arduino UNO

GitHub:
https://github.com/chuyrc/Electronica.git

(Proyecto de codigo abierto)
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

int vel = 125;  //Velocidad de los motores

void setup() {
    pinMode(estadoSwitch,INPUT_PULLUP);  //Resistencia pull up
    pinMode(pinEcho, INPUT);
    pinMode(pinTrigger, OUTPUT);
    pinMode(izqA,OUTPUT);
    pinMode(izqB,OUTPUT);
    pinMode(derA,OUTPUT);
    pinMode(derB,OUTPUT);
    pinMode(13, OUTPUT);  //LED indicador de distancia
}

void loop() {
    if(digitalRead(estadoSwitch) == 1) {
        avanzar();

        if(comprobarDistancia()) {
            detener();
            delay(100);
            girar();

            if(comprobarDistancia()) {
                detener();
                delay(100);
                girar();
                girar();
            }
        }
    }else {
        detener();
    }
    delay(150);
}

//  Devuelve la distancia con el sensor ultrasonico
long calcularDistancia() {
    digitalWrite(pinTrigger,LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigger,HIGH);
    delayMicroseconds(10);

    long x = pulseIn(pinEcho,HIGH);
    long y = (x / 2) / 29;

    return y;
}

//  Nos indica cuando tiene que girar
bool comprobarDistancia() {
    long distancia = calcularDistancia();

    if(distancia <= 2 && distancia >= 1) {
        digitalWrite(13,1);
        return true;
    }
    digitalWrite(13,0);

    return false;
}

//  Métodos para los motores
void avanzar() {
    analogWrite(enableA,vel);
    analogWrite(enableA,vel);
    digitalWrite(derA,1);
    digitalWrite(izqA,0);
    digitalWrite(derB,1);
    digitalWrite(izqB,0);
}

void girar() {
    analogWrite(enableA,vel);
    analogWrite(enableA,vel);
    digitalWrite(derA,1);
    digitalWrite(izqA,0);
    digitalWrite(derB,0);
    digitalWrite(izqB,1);
    delay(300);   //Se debe de calibrar para un correcto giro
    detener();
}

void detener() {
    analogWrite(enableA,0);
    analogWrite(enableA,0);
    digitalWrite(derA,0);
    digitalWrite(izqA,0);
    digitalWrite(derB,0);
    digitalWrite(izqB,0);
}