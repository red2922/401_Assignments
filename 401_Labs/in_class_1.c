#include <stdio.h>
#include <stdlib.h>

void printHello();
int loopNumber(int, int);


int main(){


  printHello();
  int ret;
  ret = loopNumber(10,30);
  printf("\n%p\n", &ret);

  //Always add return zero. Its like an error code
  //Always recompile after each line
  return 0;

}

void printHello(){
  printf("Hello\n");
}

int loopNumber(int loopNum, int mult){
  int i;
  int accum = 0;
  for(i = 0; i < loopNum; i++){
    accum += i;
  }
  return accum;

}

// %d\n puts itself onto the stack and then the i onto it.
// %d\n means string
