#include <stdio.h>

#include "Sensor.h"
#include "PrintIO.h"

LangString LangConfig[] =
{
  {"Temperature"},
  {"SOC"}
};

void FormatOutput(int id, int value, FILE * fp){
    printf("%s=%d\n", LangConfig[id].string, value);
    fprintf(fp, "%s=%d\n", LangConfig[id].string, value);
}
