#ifndef SENSOR_H_
#define SENSOR_H_

typedef enum{
  Temperature,
  SOC,
}sensorName;

typedef struct{
  sensorName name;
  int id;
}SensorType;

SensorType SensorConfig[MAX_SENSOR_SUPPORTED];
int SendSensorReading(int maxSamples, int maxSensorsupported, void (*printIO)(int, int), FILE *fp);
int GetandPrintSensorReading(SensorType sensorConfig, int maxSamples, void (*printIO)(int, int), FILE *fp);

#endif
