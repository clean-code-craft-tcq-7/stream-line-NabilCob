#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <regex.h>
#include <string.h>

#include "Sensor.h"
#include "PrintIO.h"

int main(){
  FILE *fp;
  int maxSamples = 50;
  int maxSensorsupported = 2;
  int tempCnt = 0;
  int socCnt = 0;
  int retStatus = 0;
  fp = fopen("sensoroutput.txt", "w+");
  if(fp == NULL){
     printf("\nfile opening failed");
     return 0;
  }
  retStatus = SendSensorReading(maxSamples, maxSensorsupported, FormatOutput, fp);  
  
  assert(retStatus == maxSamples); 
  regex_t compPattern;  
  const char* pattern = "[a-zA-Z]+=\d+\n";  
  if (regcomp(&compPattern, pattern, REG_EXTENDED) != 0) return 0; 
  char *string = (char*)calloc(50, sizeof(int));  
  while (!feof(fp)) {
     if( fgets (string, 50, fp)!=NULL ) {
          int status = regexec(&compPattern, string, 0, NULL, 0);
          assert(status == 0); 
          if(strstr(string, "Temperature")!= NULL){
               tempCnt ++;
           }
          else if(strstr(string, "SOC")!= NULL){
               socCnt ++;
          }
          else{
              //Do nothing
          }         
     }
  }

  assert(tempCnt == maxSamples);
  assert(socCnt = maxSamples); 
  regfree(&compPattern); 

  fclose(fp);
  return 0;
}
