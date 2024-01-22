#include <stdio.h>
#include <stdlib.h>

int getUserInput();
float calcAvg(int);
void farewell();

int main(){
printf("\nWelcome to Lab 2!\n\n");
int userInput = getUserInput();
float avg = calcAvg(userInput);

printf("\nYou chose the value: %d\n", userInput);
printf("The mean is: %f\n", avg);
farewell();
}

int getUserInput(){
  int x;
  printf("Please Enter a number from 1 to 10: ");
  scanf("%d", &x);
  return x;
}

float calcAvg(int userInput){
  float total;
  for (int i = 0; i < userInput; i++){
    total += i;
  }

  float mean = total/userInput;
  return mean;
}

void farewell(){
  printf("Thank You");
}
