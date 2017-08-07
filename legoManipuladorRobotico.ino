
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <LiquidCrystal.h>  
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  5
#define btnUP     4
#define btnDOWN   3
#define btnLEFT   2
#define btnSELECT 1
#define btnNONE   0

// read the buttons
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  

 // For V1.0 comment the other threshold and use the one below:
/*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
*/


 return btnNONE;  // when all others fail, return this...
}

//Criando o objeto motor shield com o endereco defaut I2C
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

//Selecionando a porta que o motor ira rodar
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);
 
void setup(){

  //Display com 16 colunas e 2 linhas
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Mandela TP1");

  //Cria com a frequencia defaut = 1.6KHz
  AFMS.begin();
}
 
 
void loop() 
{

//TELA INICIAL
 lcd.setCursor(0,1);
 lcd.print("Iniciar (SELECT)");           
 while(lcd_key != 1){
  lcd_key = read_LCD_buttons();  // read the buttons
 }

//COMEÇO DA TAREFA
 lcd.setCursor(0,1);
 lcd.print("EXECUTANDO...   ");
 
//LETRA U
//Traço vertical da esquerda `´
  myMotor2->run(FORWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal da base ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical da direita ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);

//ESPAÇO ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(330);
  myMotor->run(RELEASE);
  delay(2000);

//LETRA F
//Traço vertical da esquerda `´
  myMotor2->run(FORWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço vertical parcial baixo da esquerda ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(5000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal do meio ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço horizontal do meio <-
  myMotor->run(BACKWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical parcial alto da esquerda ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(3000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal de cima ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);

//ESPAÇO ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(330);
  myMotor->run(RELEASE);
  delay(2000);

//LETRA M
//Traço vertical da esquerda `´
  myMotor2->run(FORWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço vertical da esquerda ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal parcial de cima ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(1000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical do centro `´
  myMotor2->run(FORWARD);
  myMotor2->setSpeed(127);
  delay(6400);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço vertical do centro ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(6400);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal parcial de cima ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(1000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical da direita `´
  myMotor2->run(FORWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);

//ESPAÇO ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(330);
  myMotor->run(RELEASE);
  delay(2000);

//LETRA G
//Traço horizontal da base ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical da direita ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(3760);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal do meio <-
  myMotor->run(BACKWARD);
  myMotor->setSpeed(127);
  delay(1500);
  myMotor->run(RELEASE);
  delay(2000);
//Traço horizontal do meio ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(1500);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical da direita `´
  myMotor2->run(FORWARD);
  myMotor2->setSpeed(127);
  delay(3760);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal da base <-
  myMotor->run(BACKWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);
//Traço vertical da esquerda ^
  myMotor2->run(BACKWARD);
  myMotor2->setSpeed(127);
  delay(8000);
  myMotor2->run(RELEASE);
  delay(2000);
//Traço horizontal de cima ->
  myMotor->run(FORWARD);
  myMotor->setSpeed(127);
  delay(2000);
  myMotor->run(RELEASE);
  delay(2000);
  
  lcd_key = 0;

} 
