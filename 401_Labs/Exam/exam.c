#include <stdio.h>
#include <stdlib.h>


void countNum(int);

int main(){
  int input;
  printf("Please enter a number: ");
  scanf("%d", &input);
  countNum(input);
  return 0;
}


void countNum(int input){
  int i;
  for (i = 0;i <= input;i++){
    printf("%d\n", i);
  }

}
