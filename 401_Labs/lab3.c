#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 20

char * getUserInput(char *, char *);
void printUserInput(char *, char *, char *);
void printWelcome(char *);
//char * printUserInput(char *, char*, char *);
//char * printWelcome(char *);

int main(){

//Define Strings
  char * welcomePrompt = "Welcome to C Lab3! :D";
  char * firstNamePrompt = "Please enter your first name: ";
  char * lastNamePrompt = "Please enter you last name: ";
  char * outputFormat = "\n%s %s, welcome to CYBR 401!\n\n";
  char * inputFormat = "%19s";

//General Code
  printWelcome(welcomePrompt);

  char * firstName = getUserInput(firstNamePrompt, inputFormat);
  char * lastName = getUserInput(lastNamePrompt, inputFormat);

  printUserInput(firstName, lastName, outputFormat);

  free(firstName);
  free(lastName);

  return 0;
}

//Get User Input
char * getUserInput(char * prompt, char * format ){
  char * userInput = malloc(STR_SIZE * sizeof(char));
  userInput[20] = '\0';

  printf("%s", prompt);
  scanf(format, userInput);
  return userInput;
}

//Print Welcome
void printWelcome(char * welcome){
  printf("\n%s\n\n", welcome);

}

//print user input
void printUserInput(char * fName, char * lName, char * format){
  printf(format,fName,lName);

}
