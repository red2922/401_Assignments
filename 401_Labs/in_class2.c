#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

#define NAME "Enter Name: "

struct Student{
  int stuNum;
  char * fName;
  char * lName;
};

struct rect {
  float width;
  float length;
}

int printWelcome(char *);
char * getInput(char *);
int addStudents(int, struct student *);
int printStudents(struct student *);

int main(){
  printWelcome("Jake");
  char * name = getInput("Enter name: ");
  printf("%s\n", name);
  struct student class[20];
  class[0].stuNum = 1;
  printf("%d\n", class[0].stuNum);


  return 0;
}

int printWelcome(char * name){
  printf("Hello there, %s\n", name);
  return 0;
}

char * getInput(char * prompt){
  printf("%s", prompt);
  char * name;
  name = malloc(SIZE * sizeof(char));
  name[SIZE] = '\0';
  scanf("%19s", name);


  return name;
}

int addStudents(int num, struct student class[SIZE]){
  int i;
  class = SIZE;

  for(i = 0; i < num; i++){
    class[i].stuNum = -1;
    class[i].fName = "None";
    class[i].lName = "None";

    printf("%d %s %s", class[1].stuNum, class[1].fName, class[1].lName);


  }


}



int printStudents(int num, struct student class[SIZE]){
  int i;
  for(i = 0; i < num; i++){
      printf("***** NEW STUDENT %d *****", i + 1)
      printf("Student Number: %d\n", class[i].stuNum)



  }



}
