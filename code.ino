#include <LiquidCrystal.h>

// Definindo as constantes dos pinos
const int temperatureSensorPin = A0;
const int humiditySensorPin = A1;
const int LDRPin = A2;
const int GREEN_LED_PIN = 2;
const int YELLOW_LED_PIN = 3;
const int RED_LED_PIN = 4;
const int MOTOR = 10;
const int LCD_RS = 12;
const int LCD_EN = 11;
const int LCD_D4 = 8;
const int LCD_D5 = 7;
const int LCD_D6 = 6;
const int LCD_D7 = 5;
const int sensorUmidade = A5;
const int motor = 13;
//solo


// Inicialização do LCD
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(MOTOR, OUTPUT); //led
   pinMode(motor, OUTPUT);
  pinMode(A4, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  int temperature = readTemperature();
  int humidity = readHumidity();
  int lightLevel = readLightLevel();
  int umidadeSolo = analogRead(sensorUmidade);
  int valor= analogRead(4);
  float volt = float (valor)/ 1023*5.0;
  float pHValue = 2.63 * volt - 0.36;
  //int phValor = phPrint();
  // Exibição dos valores no monitor serial
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" °C / ");
  Serial.println();
	
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  Serial.print("Leitura luz: ");
  Serial.println(lightLevel);
  //Serial.print("\t");
  Serial.print("Solo: ");
  Serial.println(umidadeSolo);
  
  
  // Verificar a condição do ambiente
  if (lightLevel<=649 || temperature >= 35 || humidity > 70 ||temperature <=20 ||umidadeSolo <= 150 ||(pHValue >7 || pHValue <4)) {
    // Ambiente ruim - LED vermelho aceso
    // lightLevel >= 950 
    //(lightLevel >= 950 || temperature >= 35 || humidity > 70 ||temperature <=20 ||umidadeSolo <= 150) 
    //(pHValue >7 || pHValue <4) RUIM
	// (pHValue >=4 && pHValue <=6) MED
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    
    //delay(500);
    terraPrint();
    phPrint();
    umiPrint();
    luzPrint();
    tempPrint();
  } else if ((lightLevel >= 650 && lightLevel<=949)||(umidadeSolo >= 150 && umidadeSolo<=550)||(pHValue >=4 && pHValue <=6)) {
    // Ambiente mediano - LED amarelo aceso
    // lightLevel >= 650 && lightLevel<=949
    //  ((lightLevel >= 650 && lightLevel<=949)||(umidadeSolo >= 150 && umidadeSolo<=550)) 
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    
    terraPrint();
    phPrint();
    umiPrint();
    luzPrint();
    tempPrint();
    }else if (lightLevel >= 950 && (temperature >= 30 && temperature <= 35 || humidity<50) && umidadeSolo>=550){
    // Ambiente bom - LED verde aceso
    // lightLevel<=649
    //  (lightLevel<=649 && (temperature >= 30 && temperature <= 35 || humidity<50) && umidadeSolo>=550)
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    
    terraPrint();
    phPrint();
    umiPrint();
    luzPrint();
    tempPrint();
  }

  //delay(3000);  // ATUALIZA OS DADOS (5 - 1 ) seg
}
int readTemperature() {
  int rawValue = analogRead(temperatureSensorPin);
  double voltage = (rawValue / 1023.0) * 5000; // 5000 para obter milivolts
  double celsius = (voltage - 500) * 0.1; // 500 é o deslocamento
  return celsius;
}
int readHumidity() {
  int rawValue = analogRead(humiditySensorPin);
  int percentage = map(rawValue, 0, 1023, 0, 100);
  return percentage;
}
int readLightLevel() {
  int rawValue = analogRead(LDRPin);

  return rawValue;
}
int luzPrint(){
    
    int lightLevel = readLightLevel();
    if (lightLevel<=649 ){
        lcd.setCursor(0, 0);
        lcd.print("Ambiente:  ");
        lcd.setCursor(0, 1);
        lcd.print("Muito escuro    ");
        delay(2000);
        lcd.clear();
    }else if (lightLevel >= 650 && lightLevel<=949){
        lcd.setCursor(0, 0);
        lcd.print("Ambiente:  ");
        lcd.setCursor(0, 1);
        lcd.print("A meia Luz");
        delay(2000);
        lcd.clear();
    }else if (lightLevel >= 950){
        //lightLevel >= 950
        lcd.setCursor(0, 0);
        lcd.print("Ambiente    ");
        lcd.setCursor(0, 1);
        lcd.print("Ensolarado       ");
        delay(2000);
        lcd.clear();
    }
}
int tempPrint(){
    int temperature = readTemperature();
    
    if(temperature >= 35 || temperature <= 15){
        lcd.setCursor(0, 0);
        lcd.print("Temp. ALTA    ");
        lcd.setCursor(0, 1);
        lcd.print("Temp. = ");
        lcd.print(temperature);
        lcd.print(" C");
        delay(2000);
        lcd.clear();
    }else{
        lcd.setCursor(0, 0);
        lcd.print("Temp. OK    ");
        lcd.setCursor(0, 1);
        lcd.print("Temp. = ");
        lcd.print(temperature);
        lcd.print(" C");
        delay(2000);
        lcd.clear();
    }
}
int umiPrint(){
    int humidity = readHumidity();
    if (humidity>70){
        lcd.print("Umidade ALTA   ");
        lcd.setCursor(0, 1);
        lcd.print("Umid. = ");
        lcd.print(humidity);
        lcd.print(" %");
    }else{
        lcd.print("Umidade BAIXA   ");
        lcd.setCursor(0, 1);
        lcd.print("Umid. = ");
        lcd.print(humidity);
        lcd.print(" %");
        delay(2000);
        lcd.clear();
    }
}
int terraPrint(){
    int umidadeSolo = analogRead(sensorUmidade);
    if (umidadeSolo <= 150){
        digitalWrite(MOTOR, HIGH);
      	digitalWrite(motor, HIGH);
        lcd.print("Umi.TERRA: BAIXA");
        lcd.setCursor(0, 1);
        lcd.print("Umid. = ");
        lcd.print(umidadeSolo);
        lcd.print(" %");
        delay(2000);
        lcd.clear();
    }else if (umidadeSolo >= 150 && umidadeSolo<=550){
        digitalWrite(MOTOR, LOW);
      	digitalWrite(motor, LOW);
        lcd.print("UmiTERRA: MEDIA");
        lcd.setCursor(0, 1);
        lcd.print("Umid. = ");
        lcd.print(umidadeSolo);
        lcd.print(" %");
        delay(2000);
        lcd.clear();
    }else if (umidadeSolo>=550){
        digitalWrite(MOTOR, LOW);
      	digitalWrite(motor, LOW);
        lcd.print("Umi.TERRA: BOA");
        lcd.setCursor(0, 1);
        lcd.print("Umid. = ");
        lcd.print(umidadeSolo);
        lcd.print("   ");
        delay(2000);
        lcd.clear();
    }
}
int phPrint() {
    int valor= analogRead(4);
    float volt = float (valor)/ 1023*5.0;
    float pHValue = 2.63 * volt - 0.36;
    //(pHValue >7 || pHValue <4) RUIM
	// (pHValue >=4 && pHValue <=6) MED
	// 
    if (pHValue >7 || pHValue <4){
        lcd.print("Ph agua: RUIM");
        lcd.setCursor(0, 1);
        lcd.print("ph = ");
        lcd.print(pHValue);
        lcd.print("   ");
        delay(2000);
        lcd.clear();
    } else if (pHValue >=4 && pHValue <=6){
        lcd.print("Ph agua: MED");
        lcd.setCursor(0, 1);
        lcd.print("ph = ");
        lcd.print(pHValue);
        lcd.print("   ");
        delay(2000);
        lcd.clear();
    }else{
        lcd.print("Ph agua: BOM");
        lcd.setCursor(0, 1);
        lcd.print("ph = ");
        lcd.print(pHValue);
        lcd.print("   ");
        delay(2000);
        lcd.clear();
    }
}
