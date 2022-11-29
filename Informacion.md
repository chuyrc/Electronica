![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.001.jpeg) ![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.002.png)

**TECNOLÓGICO NACIONAL DE MÉXICO - CAMPUS CHIHUAHUA II** 

**“PROYECTO ROBOT ESQUIVA OBJETOS”** 

**INGENIERÍA INFORMÁTICA                     SISTEMAS ELECTRÓNICOS PARA INFORMÁTICA TERCER SEMESTRE** 

**UNIDAD 4** 

**GRUPO A** 

**DOCENTE** 

**M.E. Royce Enríquez Rodríguez Castillo ALUMNO** 

**Jesús Roberto Leyva Domínguez   21550745** 

Chihuahua, Chih 26 de noviembre de 2022 

**Contenido** 

[**Materiales y costos ................................................................................................................... 3** ](#_page2_x69.00_y72.80)[Sensor ultrasónico HC-SR04 .................................................................................................. 3** ](#_page2_x69.00_y323.80)[Características ........................................................................................................................ 3 ](#_page2_x69.00_y356.80)[Medición ................................................................................................................................ 3 ](#_page2_x69.00_y479.80)[**CI L293D Puente H .................................................................................................................. 4** ](#_page3_x69.00_y72.80)[Diagrama del circuito integrado............................................................................................. 4 ](#_page3_x69.00_y95.80)[Descripción ............................................................................................................................ 4 ](#_page3_x69.00_y345.80)[**Alimentación del Arduino UNO ............................................................................................. 5** ](#_page4_x69.00_y124.80)[USB ........................................................................................................................................ 5 ](#_page4_x69.00_y203.80)[Jack de alimentación externa ................................................................................................. 5 ](#_page4_x69.00_y598.80)[Pin Vin .................................................................................................................................... 6 ](#_page5_x69.00_y374.80)[Pin 5v ..................................................................................................................................... 7 ](#_page6_x69.00_y72.80)[**Conexiones en protoboard ...................................................................................................... 7** ](#_page6_x69.00_y381.80)[Código Arduino ........................................................................................................................ 8** ](#_page7_x69.00_y221.80)[Variables ................................................................................................................................ 8 ](#_page7_x69.00_y254.80)[Void setup .............................................................................................................................. 8 ](#_page7_x69.00_y504.80)[Métodos.................................................................................................................................. 9 ](#_page7_x69.00_y708.80)[Void loop ............................................................................................................................. 11 ](#_page10_x69.00_y72.80)[**Referencias.............................................................................................................................. 12**](#_page11_x69.00_y72.80)

**Materiales y costos** 

Precios aproximados. 

3 

- Sensor ultrasónico HC-SR04 (sensor de distancia).    
- Circuito integrado L293D (Doble puente H).              
- 2 motorreductores.                                                       
- LED rojo.                                                                     
- Fuente de alimentación de 7v a 12v.  
- Jumpers/Cables. 
- Microcontrolador Arduino UNO u otro. 
- Protoboard/Placa de prototipos. 

$50 MXN 

$30 MXN 

$50 MXN c/u 

$2 MXN 

$100 MXN (Pila 9v) ~ 

$250 – 400 MXN $100 MXN 



No se incluyen las ruedas de los motores, la rueda loca (rueda estabilizadora) ni la base para el montaje. Depende como se quiera realizar el montaje. 

**Sensor ultrasónico HC-SR04** 

***Características*** 

- Cuenta con 4 pines (VCC, Trig, Echo, GND). 
- Se alimenta con 5v de corriente directa. 
- Maneja una corriente menor a 2mA. 
- Angulo de cobertura de 15°. 
- Su rango de medición es de 2 cm a 500 cm. 
- Tiene una resolución de 0.3 cm. 

***Medición*** 

Se debe de dar un pulso de 10 microsegundos al trigger (trig) y se obtiene el pulso de retorno en el pin Echo. Esa será la duración del trigger al echo. Para obtener la distancia, se deberá de dividir entre 58.2. Constante dada por el fabricante del sensor.  

Se debe de definir un rango de distancia, para que no tenga errores en la medición o en las instrucciones. 

Otra manera de medir la distancia, (duración del pulso  / 2) / 29 ). O utilizando la librería “Ultrasonic.h” 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.003.jpeg)

**CI L293D Puente H** 

***Diagrama del circuito integrado*** 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.004.jpeg)

***Descripción*** 

Este circuito tiene 16 pines. Y nos permite controlar el giro de dos motores, así como su velocidad. 

Pines 1 y 9. Son los habilitadores de los motores. Sin ellos no se alimentarán los motores, se podrían utilizar como los encendidos de los motores. Necesitan ser alimentados con 5v, sin embargo, se pueden mandar señales PWM, con lo cual nos permite controlar la velocidad de los motores. Si recibe un 0, los motores no funcionaran. 

Pines 2, y 7. Son las entradas del primer motor. Dependiendo de la combinación de ceros y unos será el giro del motor. Si se manda (0,0) o (1,1), el motor se detendrá, con (0,1) y (1,0) el giro será horario y anti horario (dependiendo de las conexiones). Si el pin 1 tiene un 0 sin importar la combinación de ceros y unos, no funcionara. Estos pines también aceptan PWM, así que es otra forma de controlar la velocidad de los motores. 

Pines 3 y 6. Son las salidas del motor 1, que corresponde a los pines 2 y 7, dependiendo de la combinación de ceros unos, como también de las conexiones, dependerán los giros del motor. Siempre y cuando el pin 1 este alimentado. 

Pines 10 y 15. Son prácticamente lo mismo que los pines 2 y 7 solo que funcionaran siempre y cuando que el pin 9 este alimentado con 5v. Son los pines que controlan el segundo motor. 

Pines 11 y 14. Son las salidas del motor 2, que corresponden a los pines 10 y 15. El motor funcionara siempre y cuando se alimenta el pin 9. 

Pines 4, 5, 13 y 12. Estos pines son los disipadores de los motores, estos deben estar conectados a tierra para que los motores tengan un correcto funcionamiento. 

Pin 16. Es donde se alimenta este circuito, en el cual debe de ser 5v. 

Pin 8. Esta es una alimentación externa para los motores, en dado caso que la alimentación por el pin 16 no proporcione la suficiente corriente para accionar los motores. Como es el caso del Arduino. Este pin soporta un máximo de 36v. 

**Alimentación del Arduino UNO** 

Para alimentar la placa de desarrollo Arduino UNO, se tienen 4 maneras de alimentarlo. \*\*OJO. Solo debes de alimentar el Arduino con UNA de las siguientes maneras \*\* ***USB*** 

Además de permitirnos enviar los códigos compilados al Arduino UNO, la entrada USB nos permite alimentar al Arduino, sin embargo, solo deben de ser alimentado con 5v, de lo contrario se podría dañar al microcontrolador.  

También tener en cuenta que no tienen un protector contra la polaridad inversa, teniendo que ser bastante precavido al momento de alimentarlo por esta manera. Aunque no suele ser un problema  por  los  entandares  de  los  conectores  USB.  Un  mal  no  solo  podría  dañar  el microcontrolador, sino, también los puertos USB. 

Se recomienda tan solo usar para enviar el programa compilado al Arduino y para pequeñas pruebas, más no como fuente de alimentación. 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.005.jpeg)

***Jack de alimentación externa*** 

Esta manera es la mejor forma de alimentar una Arduino en caso de poseer una. Debido que cuenta con protección contra polaridad inversa (en caso de alimentarlo de manera incorrecta el Arduino no funcionara, pero no se dañara), además de tener un regulador de voltaje, por lo que no se necesitaran 5v obligatoriamente. 

Por esta entrada podemos ingresar de 6v a 20v, sin embargo, lo más recomendable sería como mínimo **7v** para su correcto funcionamiento y como máximo **12v** para que no se sobrecaliente. 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.006.jpeg)

***Pin Vin*** 

Esta está ubicada en la sección de POWER del Arduino, esta es similar a la alimentación por el Jack, ya que se puede alimentar con 7v a 12v, sin embargo, esta no cuenta con protección contra la polaridad inversa, así que se tiene que ser cuidadoso ya que podría dañar el regulador y con ello el microcontrolador. 

Hay que tener claro que se puede usar como entrada de alimentación, así como una salida de 5v. 

El positivo de la fuente externa debe conectarse en el pin Vin, mientras que el negativo en cualquier GND del Arduino. 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.007.jpeg)

***Pin 5v*** 

Este es similar al Pin V y al USB. Al Pin V ya que puede ser utilizado para alimentar el 

in  in 

Arduino o como salida de 5v. Y al USB ya que solo se le pueden enviar 5v regulados como entrada. 

Esta es la peor forma de alimentar al Arduino, se recomienda usar cualquiera de las tres anteriores antes que esta, ya que no tiene un regulador de voltaje y tampoco protección contra polaridad inversa. Se recomienda solo utilizar este pin como una salida de 5v. 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.008.jpeg)

**Conexiones en protoboard** 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.009.png)

- Pin 13. Se conectará un led a tierra. 
- Pin 12. Estará conectado al echo del HC-SR04. 
- Pin 11. Se conectará al trigger (trig) del HC-SR04. 
- Pin 10. En el pin 9 y 1 del L293D. 
- Pin 9. En el pin 2 del L293D. 
- Pin 8. En el pin 7 del L293D. 
- Pin 7. En el pin 15 del L293D. 
- Pin 6. En el pin 10 del L293D. 
- Pin 5v. Se conectará en el bus positivo del protoboard. 
- Pin GND. Se conectará en el bus negativo del protoboard. 
- La terminal negativa de la fuente de alimentación externa se conectará a GND. 
- La terminal positiva de la fuente de alimentación externa se conectará en el pin 8 del L293D y en el Pin Vin del Arduino. 

**Código Arduino** 

***Variables*** 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.010.jpeg)

***Void setup*** 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.011.jpeg)

***Métodos*** 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.012.jpeg)

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.013.jpeg)

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.014.png) ![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.015.png)

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.016.jpeg)

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.017.png)

***Void loop*** 

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.018.jpeg)

![](Aspose.Words.2e26c1b8-fb29-4a3a-8b64-b7c0ed1157c5.019.jpeg)

GitHub: [https://github.com/chuyrc/Electronica.git ](https://github.com/chuyrc/Electronica.git)Video explicativo: [https://youtu.be/H5f-hhY32ss ](https://youtu.be/H5f-hhY32ss)

**Referencias** 

Bitwise Ar. (2017, 8 marzo). *Arduino desde cero en Español - Capítulo 5 - HC-SR04 Sensor Ultrasónico (y uso del Monitor Serial)* [Vídeo]. YouTube.[ https://youtu.be/mlw3APOUt8U ](https://youtu.be/mlw3APOUt8U)

El profe García (2014, agosto 27). ✅ *Sensor de Distancia (proximidad) hasta 5 metros /  HC-SR04 y ARDUINO* [Vídeo]. YouTube.[ https://youtu.be/IF1eN0WK3bU ](https://youtu.be/IF1eN0WK3bU)

Geek Factory. (2017, 28 septiembre). *Alimentar el Arduino: La guía definitiva.* [https://www.geekfactory.mx/tutoriales-arduino/alimentar-el-arduino-la-guia-definitiva/ ](https://www.geekfactory.mx/tutoriales-arduino/alimentar-el-arduino-la-guia-definitiva/)

Novatech [Novatech]. (2022, 18 junio). 🔥*L293D con ARDUINO - Control de giro y velocidad motores DC - Puente H* [Vídeo]. YouTube. [ https://youtu.be/ggvDc-1RV0g ](https://youtu.be/ggvDc-1RV0g)

TecnoReBot. (2021, 7 diciembre). 01\_A Como alimentar al arduino uno con pilas o baterías [Vídeo]. YouTube.[ https://youtu.be/2q657wVgJgQ ](https://youtu.be/2q657wVgJgQ)
13 
