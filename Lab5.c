int startButton = PE_0; // Boton de inicio de carrera conectado al pin PE0
int P1Button = PB_7;    // Boton jugador 1
int P2Button = PB_6;    // Boton jugador 2
int redPin = PF_1;
int greenPin = PF_3;    //Pines luz RGB
int bluePin = PF_2;
int cont1 =0, cont2 =0, act =0;
int P1led1 = PB_5;      //Pines luces de juegos
int P1led2 = PB_0;
int P1led3 = PB_1;
int P1led4 = PE_4;
int P2led1 = PE_5;
int P2led2 = PB_4;
int P2led3 = PA_5;
int P2led4 = PA_6;

void setup(){
  // Configurar los pines como entrada o salida
  pinMode (startButton, INPUT_PULLUP);  //Botones como pullups
  pinMode (P1Button, INPUT_PULLUP);
  pinMode (P2Button, INPUT_PULLUP);
  pinMode (redPin, OUTPUT);             //Leds como salidas
  pinMode (greenPin, OUTPUT);   
  pinMode (bluePin, OUTPUT);
  pinMode (P1led1, OUTPUT);
  pinMode (P1led2, OUTPUT);
  pinMode (P1led3, OUTPUT);
  pinMode (P1led4, OUTPUT);
  pinMode (P2led1, OUTPUT);
  pinMode (P2led2, OUTPUT);
  pinMode (P2led3, OUTPUT);
  pinMode (P2led4, OUTPUT);
}

void loop() {
  digitalWrite(P1led1, LOW);  //Empieza en cero todo
  digitalWrite(P1led2, LOW);
  digitalWrite(P1led3, LOW);
  digitalWrite(P1led4, LOW);
  digitalWrite(P2led1, LOW);
  digitalWrite(P2led2, LOW);
  digitalWrite(P2led3, LOW);
  digitalWrite(P2led4, LOW);
  if (digitalRead(startButton) == LOW){           //Cuando lee el boton empieza el semáforo
    //Iniciar la secuencia del semaforo de salida
    cont1 = 0;                    //Contadores en 0
    cont2 = 0;
    digitalWrite(redPin, HIGH);   // LED rojo encendido
    delay(1000);                  // Esperar 1 segundo
    digitalWrite(redPin, LOW);    // LED rojo apagado
    digitalWrite(bluePin, HIGH);   // LED azul encendido
    delay(1000);                  // Esperar 1 segundo
    digitalWrite(bluePin, LOW);    // LED azul apagado
    digitalWrite(greenPin, HIGH);   // LED verde encendido
    act = 1;                        //activa variable de inicio de juego
    delay(1000);                  // Esperar 1 segundo
    digitalWrite(greenPin, LOW);    // LED verde apagado
    }

    while(act == 1){                        //Mientras act sea uno los jugadores pueden empezar
      if(digitalRead(P1Button) == LOW){     //Funciones contador para prender leds
        cont2 = cont2 +1;
        while(digitalRead(P1Button) == LOW){}
      }
      if(digitalRead(P2Button) == LOW){
        cont1 = cont1 +1;
        while(digitalRead(P2Button) == LOW){}
      }
      if(cont1 == 1){                       //Funciones para prender leds del jugador 1 dependiendo del contador
        digitalWrite(P1led1, HIGH);   
      }else if(cont1 == 2){
        digitalWrite(P1led1, LOW);
        digitalWrite(P1led2, HIGH);   
      }else if(cont1 == 3){
        digitalWrite(P1led2, LOW);
        digitalWrite(P1led3, HIGH);   
      }
      if(cont2 == 1){                       //Funciones para prender leds del jugador 2 dependiendo del contador
        digitalWrite(P2led1, HIGH);   
      }else if(cont2 == 2){
        digitalWrite(P2led1, LOW);
        digitalWrite(P2led2, HIGH);   
      }else if(cont2 == 3){
        digitalWrite(P2led2, LOW);
        digitalWrite(P2led3, HIGH);   
      }      
      if(cont1 >= 4){                         //Funciones para indicar el jugador 1 fue el ganador de la carrera
        digitalWrite(redPin, HIGH);
        digitalWrite(P1led1, HIGH);
        digitalWrite(P1led2, HIGH); 
        digitalWrite(P1led3, HIGH);
        digitalWrite(P1led4, HIGH); 
        digitalWrite(P2led1, LOW);
        digitalWrite(P2led2, LOW);
        digitalWrite(P2led3, LOW);
        digitalWrite(P2led4, LOW);
        delay(500);
        act = 0; //act cambia a 0 para detener la carrera
      }
      if(cont2 >= 4){                         //Funciones para indicar el jugador 2 fue el ganador de la carrera
        digitalWrite(greenPin, HIGH);
        digitalWrite(P2led1, HIGH);
        digitalWrite(P2led2, HIGH); 
        digitalWrite(P2led3, HIGH);
        digitalWrite(P2led4, HIGH); 
        digitalWrite(P1led1, LOW);
        digitalWrite(P1led2, LOW);
        digitalWrite(P1led3, LOW);
        digitalWrite(P1led4, LOW);          
        delay(500);
        act = 0;  //act cambia a 0 para detener la carrera
      }
    }
  }
