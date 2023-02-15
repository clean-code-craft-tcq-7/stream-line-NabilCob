#include <stdio.h>

#include "Sensor.h"
#include "PrintIO.h"

LangString LangConfig[] =
{
  {"Temperature"},
  {"SOC"}
};

void FormatOutput(int id, int value, FILE * fp){
    printf("%s=%d", LangConfig[id].string, value);
    fprintf("%s=%d", LangConfig[id].string, value);
}
