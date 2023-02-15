#include <stdio.h>
#include <stdlib.h>
#include "Sensor.h"

SensorType SensorConfig[MAX_SENSOR_SUPPORTED] =
{
  {Temperature, 1},
  {SOC, 2}
};

int SendSensorReading(int maxSamples, int maxSensorsupported, void (*printIO)(int, int), FILE *fp)
{
     int lstIdx;
     for(lstIdx = 0; lstIdx < maxSensorsupported; lstIdx++){
         GetandPrintSensorReading(SensorConfig[lstIdx], maxSamples, printIO, fp);
     }
}

int GetandPrintSensorReading(SensorType sensorConfig, int maxSamples, void (*printIO)(int, int), FILE *fp)
{
    srand(sensorConfig.id);
    int smpCnt;
    for(smpCnt = 0; smpCnt < maxSamples; smpCnt ++){
          (*printIO)(sensorConfig.name, rand(), fp);
    }
}
