#ifndef SENSOR_H_
#define SENSOR_H_

typedef enum{
  Temperature,
  SOC,
  MAX_SENSOR_SUPPORTED,
}sensorName;

typedef struct{
  sensorName name;
  int id;
}SensorType;

extern SensorType SensorConfig[MAX_SENSOR_SUPPORTED];
int SendSensorReading(int maxSamples, int maxSensorsupported, int bitconvert,
                      void (*printIO)(int, int, FILE*), FILE *fp);
int GetandPrintSensorReading(SensorType sensorConfig, int maxSamples, int bitconvert,
                             void (*printIO)(int, int, FILE*), FILE *fp);

#endif
