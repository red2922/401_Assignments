#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

char * getUserInput(char *, char *);


int main(){
  char * format;
  char * prompt;
  char * ui;
  format = "%19s";
  prompt = "Please enter your first name: ";
  ui = getUserInput(format, prompt);
  printf("%s", ui);
}


char * getUserInput(char * format, char * prompt){
  char * ui = malloc(SIZE * sizeof(char));
  ui[20] = "\0";
  printf("%s", prompt);
  scanf(format, ui);
  return ui;
}
