#ifndef PRINT_IO_H
#define PRINT_IO_H

typedef struct{
  char string[25];
}LangString;

void FormatOutput(int id, int value, FILE * fp);
#endif
