#include <stdio.h>
#include <stdlib.h>

//void loopPrint(int); Function Prototyping
// void == return nothing
// int in () means it takes an int parameter
//functions should be created after main

int getUserInput();
float calcAvg(int);
void fareWell();

int main(){
int userInput;
float avg;

printf("\nWelcome to Lab 2!!!\n");

userInput = getUserInput();
avg = calcAvg(userInput);


printf("The mean is %f\n", avg);

fareWell();

return 0;

}


//Code gets user input and returns it
int getUserInput(){
int userInput;

printf("Enter an number from 1 to 10: \n");
scanf("%d",&userInput);

printf("You chose the value: %d\n", userInput);
return userInput;

}

//Code calculates average and returns it
float calcAvg(int num){
int i;
float sum = 0.0;
float avg = 0.0;

for(i = 0; i < num; i++){
sum = sum + i;
}

avg = sum/num;
return avg;

}

void fareWell(){
printf("\nFarewell!!! Thank you for using this program. See you in Lab 3!!\n ");
}
