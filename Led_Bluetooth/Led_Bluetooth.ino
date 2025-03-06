//BTO5
#include <SoftwareSerial.h> //библиотека последовательной связи
SoftwareSerial HM10(10, 11); // RX = 2, TX = 3
char appData;  
String inData = "";
void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); // onboard LED
  digitalWrite(4, LOW); // выключаем светодиод
  digitalWrite(5, LOW);
}
void loop()
{
  HM10.listen();  // слушаем HM10 port
  while (HM10.available() > 0) {   // если HM10 что то передает, то считываем данные
    appData = HM10.read();
    inData = String(appData);  // сохраняем данные в строковой переменной
    Serial.write(appData);
  }
 
  if (Serial.available()) {           // считываем информацию если пользователь что-нибудь вводит
    delay(10);
    HM10.write(Serial.read());
  }
  if ( inData == "F") {
    Serial.println("FORWARD");
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
}