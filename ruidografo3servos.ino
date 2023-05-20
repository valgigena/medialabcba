

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>


Servo servo;
Servo servo2;
Servo servo3;

Adafruit_MPU6050 srituhobby;

void setup(void) {
  Serial.begin(115200);
  servo.attach(3);
  servo2.attach(5);
   servo3.attach(6);
  Wire.begin();
  srituhobby.begin();
  servo.write(0);
  servo2.write(0);
  servo3.write(0);

  srituhobby.setAccelerometerRange(MPU6050_RANGE_8_G);//2_G,4_G,8_G,16_G
  srituhobby.setGyroRange(MPU6050_RANGE_500_DEG);//250,500,1000,2000
  srituhobby.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  srituhobby.getEvent(&a, &g, &temp);

  int value = a.acceleration.y;
  int value2 = a.acceleration.z;
  int value3 = a.acceleration.x;

  value = map(value,  -10, 10, 180, 0); 
  value2 = map(value,  -10, 10, 180, 0);
  value3 = map(value,  -10, 10, 180, 0);
  
  servo.write(value);  
  servo2.write(value2);  
  servo3.write(value2);  
  Serial.println(value);
  //delay(10);

}
