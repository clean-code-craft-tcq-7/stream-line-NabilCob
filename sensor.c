
#include "sensor.h"

SensorType SensorConfig[MAX_SENSOR_SUPPORTED] =
{
  {Tempeature, 1},
  {SOC, 2}
};

int SendSensorReading(int maxSamples, int maxSensorsupported, void (*printIO)(int, int), FILE *fp)
{
     int lstIdx;
     for(lstIdx = 0; lstIdx < maxSensorsupported; lstIdx++){
         GetandPrintSensorReading(SensorConfig, maxSamples, printIO, fp);
     }
}

int GetandPrintSensorReading(SensorType sensorConfig, int maxSamples, void (*printIO)(int, int), FILE *fp)
{
    srand(sensorConfig.idx);
    int smpCnt;
    for(smpCnt = 0; smpCnt < maxSamples; smpCnt ++){
          (*printIO)(sensorConfig.idx, rand(), fp);
    }
}
