#include <stdio.h>

//Prototyping a function(Says to C that printTen
//is incoming and to look for it
void printTen();

int main(){
  printf("Hello World!\n");
  //Calling printTen Function
  printTen();
}

//printTen being created/Initialized
void printTen(){
  //tells C that you want to print an int %d\n
  printf("%d\n", 10);
}
