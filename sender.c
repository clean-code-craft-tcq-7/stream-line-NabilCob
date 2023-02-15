#include <stdio.h>
#include <assert.h>
#include <regex.h>

#include "Sensor.h"
#include "PrintIO.h"

int main(){
  FILE *fp
  int maxSamples = 50;
  int maxSensorsupported = 2;
  fp = fopen("sensoroutput.txt", "w+");
  GetandPrintSensorReading(maxSamples, maxSensorsupported, printIO, fp);  

  regex_t compPattern;  
  const char* pattern = "[a-zA-Z]+=\d+\n";  
  if (regcomp(&compPattern, pattern, REG_EXTENDED) != 0) return 0; 
  char *string = (char*)calloc(50, sizeof(int));  
  while (!feof(fp)) {
     if( fgets (str, 50, fp)!=NULL ) {
         int status = regexec(&compPattern, string, 0, NULL, 0);
          if(strstr(str, "Temperature")!= NULL){
               TempCnt ++;
           }
          else if(strstr(str, "SOC")!= NULL){
               SocCnt ++;
          }
         assert(status == 0);
     }
  }

  assert(TempCnt == maxSamples);
  assert(SocCnt = maxSamples); 
  regfree(&re); 

  fclose(fp);
  return 0;
}
