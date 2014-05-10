int m1a = 2, m1b = 1, m2a = 4, m2b = 5; //Pines de motores
int echoPin = 8,trigPin = 9; // Pines ultrasonido Ultrasonido
long duration, distance; //Variables de Distancia
int i=0,pul=7; \\
\\Inicialización de Pines
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  //pinMode(pul,INPUT);
}
\\Funcion Principal de Bucle Infinito
void loop(){
  if(i==0){
    parar(15);
    delay(6500);
    i++;
  }
  else{
    buscar();
  }
}
\\Funcion booleana del sensor ultrasonic
boolean sensorU() {
  //Código sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  Serial.println(distance);
  if(distance<=85){ 
    return true;
  }
  else 
  {
    return false;
  }
}
\\Funcion de Movimiento de un motor
void motor(int del){
  digitalWrite(m1b,HIGH);
  digitalWrite(m1a,LOW);  
  delay(del);
}
\\Funcion de Movimiento de dos motores
void motores(int del){
  digitalWrite(m1b,HIGH);
  digitalWrite(m1a,LOW);  
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);  
  delay(del);
}
\\Funcion para parar
void parar(int del){
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,HIGH);  
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,HIGH);  
  delay(del);
}
\\Busca al objetivo girando sobre si mismo
void buscar(){
  boolean U=sensorU();
  parar(15);
  while(U==true){
    motores(100);
    U=sensorU();  
  }  
  parar(10);
  while(U==false) 
  {
    parar(50);
    motor(50);
    U=sensorU(); 
    if(U==true){
      parar(250);
      break;
    }
  }

}



