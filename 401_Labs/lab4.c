#include <stdio.h>
#include <stdlib.h>

#define WELCOME "\nWelcome to the Process Manager\n"
#define END "\nEnding Process Manager\n\n"
#define SIZE 10

void printWelcome();
struct process MakeProcess();
int getID();
char * getName();
void printProcess(struct process);
void printEnd();
void freeProc(struct process);

struct process {
  int id;
  char * name;
};

int main(){
  printWelcome();

  struct process p1;
  p1 = MakeProcess();
  printProcess(p1);
  freeProc(p1);

  printEnd();
  return 0;
}




void printWelcome()
{
  printf("%s", WELCOME);
}

void printEnd()
{
  printf("%s", END);
}

int getID()
{
  int num;
  printf("%s", "Enter ID: ");
  scanf("%d", &num);

  return num;
}

char * getName()
{
  char * temp = malloc(SIZE * sizeof(char));
  temp[SIZE] = '\0';
  printf("%s", "Enter Name: ");
  scanf("%s", temp);

  return temp;
}

struct process MakeProcess()
{
  printf("%s", "\n****** GET INPUT ******\n\n");
  struct process p1;
  p1.id = getID();
  p1.name = getName();

  return p1;
}

void printProcess(struct process p1)
{
  printf("%s", "\n****** PRINT OUT ******\n\n");
  printf("Process ID: %d\n", p1.id);
  printf("Process Name: %s\n", p1.name);

}

void freeProc(struct process p1)
{
  free(p1.name);
}
