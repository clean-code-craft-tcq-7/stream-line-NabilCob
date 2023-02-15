#include <stdio.h>
#include <stdlib.h>
#include "Sensor.h"

SensorType SensorConfig[MAX_SENSOR_SUPPORTED] =
{
  {Temperature, 1},
  {SOC, 2}
};

int SendSensorReading(int maxSamples, int maxSensorsupported, int bitconvert,
                      void (*printIO)(int, int, FILE*), FILE *fp)
{
     int lstIdx;
     int retVal = 0;
     for(lstIdx = 0; lstIdx < maxSensorsupported; lstIdx++){
         retVal = GetandPrintSensorReading(SensorConfig[lstIdx], maxSamples, bitconvert,
                                           printIO, fp);
     }
     return retVal; 
}

int GetandPrintSensorReading(SensorType sensorConfig, int maxSamples, int bitconvert,
                             void (*printIO)(int, int, FILE*), FILE *fp)
{
    int smpCnt;
    int value;
    srand(sensorConfig.id);
    for(smpCnt = 0; smpCnt < maxSamples; smpCnt ++){
          if(bitconvert > 0){
              value = rand()%(1<< bitconvert);
              (*printIO)(sensorConfig.name, value, fp);
          }
    }
    return smpCnt;
}
