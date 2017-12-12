void setup() {
// Установка 13-го пина как выход
  //Serial.begin(9600);
  
  //задержка в минуту для инициализации датчика
  delay(60000);
}

//Основной цикл
void loop() {
 //Вызов функции которая определена ниже
  pir_sens();
}

//PIR Sensor
void pir_sens(){
  //Считываем пороговое значение с порта А0
  //обычно оно выше 500 если есть сигнал
  int a=analogRead(A0);
  if(a > 500)
  {
    //Сигнал с датчика движения
    //Serial.print(a, DEC);
    //Serial.println(": Есть движение !!!");
    buzer_inj(35);
    
    delay(500);
  }
  else
  {
    //Нет сигнала
    //Serial.print(a, DEC);
    //Serial.println(": Всё тихо...");
    //delay(300);
  }
  
  delay(200);
}

//Функция которая генерирует сигнал на пьезоэлемент определенной скважности
void buzer_inj(unsigned char delayms){
  pinMode(3, OUTPUT);
  delay(800);
  
    analogWrite(3, 20); // 20 - Это ширина импульса на выводе.
    //Изменяется от 0 до 255
    delay(delayms); // Ожидание
    analogWrite(3, 0); // Выключение иппульса ШИМ
    delay(delayms); // Ожидание
    pinMode(3, INPUT);
}

