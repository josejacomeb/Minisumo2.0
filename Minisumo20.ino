int m1a = 8, m1b = 9, m2a = 12, m2b = 11;//motores /*m1a,m1b motor 1, m2a, m2n pines motor 2*/
int echoPin = 6,trigPin = 7; // Ultrasonido
long duration, distance;
int i = 0;
int slinea1 = 2, slinea2 = 3; /*Sensores de Linea*/
int negro = 4000; /*Valor a calibrar sensores*/
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(slinea1,INPUT);
  pinMode(slinea2,INPUT);
}

void loop(){
if(i==0){
  delay(5000);
  i = 1;
}
if(ultrasonico()){
    parar(40); /*Cambiar tiempo de busqueda < 500*/
    motores(1500,1); /*Cambiar de 1000 < t < 5000*/
    parar(150); /*Cambiar de 150 < t < 2500*/ 
    linea();
  }
  else{
    buscar(); /*Metodo de Busqueda mover un motor*/
    parar(50);  /*No mucho tiempo*/
  }
}

void buscar(){
  motor(125);  /*Cambiar para la busqueda*/
}

boolean ultrasonico(){
   //Código sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  if(distance<20){ /*Cambiar si no detecta*/
    return true;
  }
  else 
  {
    return false;
  }    
}

void motor(int del){
  digitalWrite(m1b,LOW);
  digitalWrite(m1a, HIGH);  
  delay(del);
}

void parar(int del){
  digitalWrite(m1a,LOW);
  digitalWrite(m1b,LOW);  
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,LOW);  
  delay(del);
}


void motores(int del,int sentido){
  if (sentido == 1){
    digitalWrite(m1b,LOW);
    digitalWrite(m1a,HIGH);  
    digitalWrite(m2a,HIGH);
    digitalWrite(m2b,LOW);  
    delay(del);
  }
  else{
    digitalWrite(m1b,HIGH);
    digitalWrite(m1a,LOW);  
    digitalWrite(m2a,LOW);
    digitalWrite(m2b,HIGH);  
    delay(del);
  }  
}
void linea(){
  boolean slinea = digitalRead(slinea1);
  if (slinea==HIGH){
    motores(500,2);
    parar(50);
  }
  slinea = digitalRead(slinea2);
   if (slinea==HIGH){
    motores(500,2);
    parar(50);
  }
}


