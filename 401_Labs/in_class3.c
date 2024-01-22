//Parsing Command Line INPUT
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void parse(char *, char *);
char * copySubstring(char *, int, int);

int main(int argc, char * argv[]){
  if(argc == 3){
    printf("Good Number of input\n");
    char * arg1 = argv [1];
    char * arg2 = argv [2];
    printf("%s - %s\n", arg1, arg2);
    parse(arg1, arg2);

  } else{
    printf("Please enter only two args.");
  }

}

void parse(char * delim, char * toParse){
  printf("The delimiter is: %s\n", delim);
  printf("The string to parse is %s\n", toParse);
  int i = 0;
  int upper = 0;
  int lower = 0;
  while(toParse[i] != '\0'){
    printf("%c ", toParse[i]);
    if(toParse[i] == ':'){
      upper = i;
      printf("Lower: %d -- Upper: %d\n", lower, upper);
      lower = i + 1;
    }
    i++;
  }



  char * getBack = copySubstring(toParse, 3, 7);
  printf("The copied string: %s\n", getBack);
}

char * copySubstring(char * copyFrom, int start, int stop){
  char * copyTo;
  copyTo = malloc(SIZE * sizeof(char));
  copyTo[SIZE] = '\0';
  int i;
  for (i = start; i < stop; i++){
    copyTo[i - start] = copyFrom[i];
  }
  return copyTo;

}
