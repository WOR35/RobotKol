#include <Servo.h>


// C++ code
//

Servo servo_0;//servo motorları tanımlıyoruz.
Servo servo_1;
Servo servo_2;
Servo servo_3;

void setup()
{
  pinMode(A0, INPUT);//A0 analog pinini Giriş olarak ayarlıyor.
  pinMode(A1, INPUT);///A1 analog pinini Giriş olarak ayarlıyor.
  pinMode(A2, INPUT);///A2 analog pinini Giriş olarak ayarlıyor.
  pinMode(A3, INPUT);///A3 analog pinini Giriş olarak ayarlıyor.
  
  servo_0.attach(4);//servo motorları pinlere atıyoruz hangi pinde oldugunu.
  servo_1.attach(5);// Kütüphaneyi kullanarak oluşturduğumuz
  servo_2.attach(6);// nesneye hangi pini kullanarak motorumuzu.
  servo_3.attach(7);// kullanacağımızı belirtmek için kullanılır.
   
}
void loop()
{
  
  int sag_sol = analogRead(A0);     //potansiyometrelerin bağlı   
  int ileri_geri = analogRead(A1);  //olduğu analog pinler
  int asagi_yukari = analogRead(A2);//okunup değişkenlere 
  int kiskac = analogRead(A3);      //kaydediliyor.
  Serial.println(sag_sol);
            
//yukarıda atadığımız değişkenlere map ile değer veriyor ne kadar
  int sag_sol_aci = map(sag_sol, 0, 1023, 0,179);//döneceğiyle ilgili.
  int ileri_geri_aci = map(ileri_geri, 1023, 0, 20,150);
  int asagi_yukari_aci = map(asagi_yukari, 0, 1023, 50,150);
  int kiskac_aci = map(kiskac, 0, 1023, 10,90);
//map ile girmiş olduğumuz değerler servo motorlara aktarıyoruz.
  servo_0.write (sag_sol_aci);
  servo_1.write (ileri_geri_aci);
  servo_2.write (asagi_yukari_aci);
  servo_3.write (kiskac_aci);
}
