#include <stdio.h>
#include <stdlib.h>
#include "Sensor.h"

SensorType SensorConfig[MAX_SENSOR_SUPPORTED] =
{
  {Temperature, 1},
  {SOC, 2}
};

int SendSensorReading(int maxSamples, int maxSensorsupported, void (*printIO)(int, int, FILE*), FILE *fp)
{
     int lstIdx;
     int retVal = 0;
     for(lstIdx = 0; lstIdx < maxSensorsupported; lstIdx++){
         retVal = GetandPrintSensorReading(SensorConfig[lstIdx], maxSamples, printIO, fp);
     }
     return retVal; 
}

int GetandPrintSensorReading(SensorType sensorConfig, int maxSamples, void (*printIO)(int, int, FILE*), FILE *fp)
{
    srand(sensorConfig.id);
    int smpCnt;
    for(smpCnt = 0; smpCnt < maxSamples; smpCnt ++){
          (*printIO)(sensorConfig.name, rand()%1024, fp);
    }
    return smpCnt;
}
