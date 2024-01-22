#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

char * getUserString(char *);
void printUserInput(char *);

int main(){
  char * prompt;
  char * userName;
  prompt = "Enter First Name: ";
  userName = getUserString(prompt);

  printUserInput(userName);

  free(userName);
  return 0;
}


char * getUserString(char * prompt){
  char * userInput = malloc(MAX_SIZE * sizeof(char));
  userInput[10] = '\0';
  printf("%s", prompt);
  scanf("%9s", userInput);
  printf("You entered: %s\n", userInput);
  return userInput;
}

void printUserInput(char * name){
  printf("Hello, %s", name);

}
