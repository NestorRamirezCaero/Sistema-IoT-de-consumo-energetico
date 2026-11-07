#include <Wire.h>
#include <Adafruit_INA219.h>

// Crear la instancia del sensor INA219
Adafruit_INA219 ina219;

void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
      delay(1); // Esperar a que se abra el monitor serie
  }
    
  Serial.println("Iniciando prueba de lectura del INA219...");

  // Inicializar la comunicación I2C en los pines por defecto del ESP32 (SDA=21, SCL=22)
  if (!ina219.begin()) {
    Serial.println("¡Error! No se pudo encontrar el chip INA219. Verifica las conexiones.");
    while (1) { delay(10); }
  }

  // CONFIGURACIÓN DE RANGO:
  // Por defecto el INA219 mide hasta 32V y 3.2A. 
  // Para mayor precisión con corrientes bajas (como tu motor de 100mA y LEDs), podemos optimizarlo:
  ina219.setCalibration_32V_1A();
  
  Serial.println("INA219 detectado correctamente. Midiendo...");
}

void loop(void) {
  float voltaje_shunt = 0;
  float voltaje_bus = 0;
  float voltaje_total = 0;
  float corriente_mA = 0;
  float potencia_mW = 0;

  // Leer los valores del sensor
  voltaje_shunt = ina219.getShuntVoltage_mV();
  voltaje_bus = ina219.getBusVoltage_V();
  corriente_mA = ina219.getCurrent_mA();
  potencia_mW = ina219.getPower_mW();
  
  // El voltaje real en la carga es la suma del voltaje del bus y la pequeña caída en la resistencia shunt
  voltaje_total = voltaje_bus + (voltaje_shunt / 1000);
  
  // Imprimir los resultados en el Monitor Serie
  Serial.print("Voltaje en Carga: "); Serial.print(voltaje_total); Serial.println(" V");
  Serial.print("Corriente Actual: "); Serial.print(corriente_mA);   Serial.println(" mA");
  Serial.print("Potencia Activa:  "); Serial.print(potencia_mW);   Serial.println(" mW");
  Serial.println("----------------------------------------");
  
  delay(2000); // Esperar 2 segundos antes de la siguiente lectura
}