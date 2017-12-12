void setup() {
// Установка 13-го пина как выход
pinMode(3, OUTPUT);
delay(1000);
buzer_inj(35);
pinMode(3, INPUT);
}

//Основной цикл
void loop() {
 //Вызов функции которая определена ниже
}

//Функция которая генерирует сигнал на пьезоэлемент определенной скважности
void buzer_inj(unsigned char delayms){

  for (int i=0; i <= 255; i=i+10){
    analogWrite(3, i); // 20 - Это ширина импульса на выводе.
    //Изменяется от 0 до 255
    delay(delayms); // Ожидание
    analogWrite(3, 0); // Выключение иппульса ШИМ
    delay(delayms); // Ожидание
  }
}

