#include <stdio.h>
#include <assert.h>

#include "Sensor.h"
#include "PrintIO.h"
#include "test/TestSender.h"

int main(){
  
  //Inputs
  FILE *fp;
  int maxSamples = 50;
  int maxSensorsupported = 2;
  int retStatus = 0;
  fp = fopen("sensoroutput.txt", "w+");
  if(fp == NULL){
     printf("\nfile opening failed");
     return 0;
  }
  retStatus = SendSensorReading(maxSamples, maxSensorsupported, FormatOutput, fp);  
  assert(retStatus == maxSamples); 
  
  //Test Sender Format
  rewind(fp);
  TestSenderFormat(maxSamples,fp);
  fclose(fp);
  return 0;
}
