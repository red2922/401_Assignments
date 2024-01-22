#include <stdio.h>
#include <stdlib.h>

int getUserInput();
void printLim(int);

int main(){
  int userInput;
  userInput = getUserInput();
  printLim(userInput);

  return 0;
}


int getUserInput(){
  int userInput;
  printf("Please Enter an Positive Integer: \n");
  scanf("%d", &userInput);
  printf("You entered: %d\n", userInput);
  return userInput;
}

void printLim(int num){
  int start;
  start = 0;

  while(start != num + 1){
    printf("%d\n", start);
    start ++;
}

}
