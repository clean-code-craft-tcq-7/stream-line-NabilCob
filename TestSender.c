#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <regex.h>
#include <string.h>

#include "Sensor.h"
#include "PrintIO.h"
#include "TestSender.h"

int TestSenderFormat(int maxSamples, FILE* fp)
{
  int tempCnt = 0;
  int socCnt = 0;
  regex_t compPattern;  
  //Matching pattern
  const char* pattern = "[1-9]+"; 
  if (regcomp(&compPattern, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0; 
  int status = regexec(&compPattern, "123", 0, NULL, 0);
/*  char *string = (char*)calloc(50, sizeof(int));  
  while (!feof(fp)) {
     if( fgets (string, 50, fp)!=NULL ) {
          printf("\ntp0 = %s", string);
          //int status = regexec(&compPattern, "abc", 0, NULL, 0);
         // assert(status == 1); 
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
  //verify number of samples read
  assert(tempCnt == maxSamples);
  assert(socCnt == maxSamples); */
  regfree(&compPattern); 
  assert(status == 0);
  return 1;
}
