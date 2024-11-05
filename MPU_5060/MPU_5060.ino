#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  } else {
    Serial.println("MPU6050 connected!");
  }
}

void loop() {
  // Retrieve raw acceleration and gyro values
  Vector accel = mpu.getAcceleration();
  Vector gyro = mpu.getRotation();

  // Print Accelerometer values (in g-force)
  Serial.print("Accel X: "); Serial.print(accel.XAxis);
  Serial.print(" | Y: "); Serial.print(accel.YAxis);
  Serial.print(" | Z: "); Serial.println(accel.ZAxis);

  // Print Gyroscope values (in degrees per second)
  Serial.print("Gyro X: "); Serial.print(gyro.XAxis);
  Serial.print(" | Y: "); Serial.print(gyro.YAxis);
  Serial.print(" | Z: "); Serial.println(gyro.ZAxis);

  delay(500);  // Wait half a second between readings
}

