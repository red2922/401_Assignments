#include <stdio.h>
#include <stdlib.h>

#define WELCOME "\nWelcome to the Assignment 1! This program will add users to our database!\n"
#define START "\n****** PROGRAM START ******\n"
#define PRINT "\n****** BEGIN PRINTOUT ******\n"
#define FREE "\n****** BEGIN FREE ******\n"
#define USERNU "\n\tEnter user number: "
#define USERNA "\tEnter Username: "
#define USERFN "\tEnter First Name: "
#define USERLN "\tEnter Last Name: "

#define SIZE 20

void printWelcome();
int getNumUsers();
int clearStdin();
int addUsers(int, struct user[SIZE]);
char * addString(char *);
int addInt(int *, char *);
int printUsers(struct user[SIZE]);
void freeMemory(struct user[SIZE]);

struct user{
  int userNum;
  char * userName;
  char * userFirst;
  char * userLast;
};

int main(){
  int num;
  struct user users[SIZE];
  users[SIZE].userNum = 0;
  printWelcome();
  num = getNumUsers();
  addUsers(num, users);
  printUsers(users);
  freeMemory(users);

  return 0;
}

void printWelcome(){
  printf("%s", WELCOME);
  printf("%s", START);
}

int getNumUsers(){
  int num;
  char term;
  printf("\nPlease enter a number of users you would like to add: ");
  for ( ;; ){
    if(scanf("%d%c", &num, &term) != 2 || term != '\n'){
      printf("Please enter an integer! Try again: ");
      clearStdin();
    }

    else{
      break;
    }
  }
  return num;
}

int clearStdin(){
  int c = 0;
  while (('\n' != (c=fgetc(stdin))) && (c != EOF)) {
    if (c == EOF) break;
  }
  return 0;
}

int addInt(int * num, char * prompt){
  printf("%s", prompt);
  scanf("%d", num);
}

char * addString(char * prompt){
  char * str = malloc(SIZE * sizeof(char));
  str[20] = '\0';
  printf("%s", prompt);
  scanf("%19s", str);
  return str;
}

int addUsers(int loopNum, struct user users[SIZE]){
  int i;
  for(i = 0; i < loopNum; i++){
    printf("\n****** New User %d ******\n",i + 1);
    addInt(&users[i].userNum, USERNU);
    users[i].userName = addString(USERNA);
    users[i].userFirst = addString(USERFN);
    users[i].userLast = addString(USERLN);
  }
  users[loopNum].userNum = 0;
  return 0;
}

int printUsers(struct user users[SIZE]){// This is broken
  int num;
  int count;
  num = -1;
  count = 0;
  printf("%s", PRINT);
  while(num != 0 && count < SIZE){
    num = users[count].userNum;
    if (num != 0){
      printf("\n****** User Number %d Summary ******\n",count + 1);
      printf("\n\tUser number: %d\n", users[count].userNum);
      printf("\tUsername: %s\n", users[count].userName);
      printf("\tUser First: %s\n", users[count].userFirst);
      printf("\tUser Last: %s\n", users[count].userLast);
    }
    count ++;
  }
return 0;
}

void freeMemory(struct user users[SIZE]){
  int num;
  int count;
  num = -1;
  count = 0;
  printf("%s", FREE);

  while(num != 0 && count < SIZE){
    num = users[count].userNum;
    if(num != 0){
      free(users[count].userName);
      free(users[count].userFirst);
      free(users[count].userLast);
    }
    count ++;
  }



}
