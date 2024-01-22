#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<sys/wait.h>

#define SIZE 200
#define ASIZE 200

char ** parse(char d, char * word);
char * newString(char *, int, int);
int getLength(char *);

int compare(char *, char * );
void pointerPrint(char ** argv);
char * checkString(char ** parsedInput, char ** path, char * input);
void exec(char * pathToFile, char ** parsedInput);
void exec2(char * pathToFile1, char * pathToFile2, char ** parsedInput1, char ** parsedInput2);
int pipePresent(char * input);

char ** getPathArray(char **);
int getArrayLength(char **);
void freeArray(char **);

int main(int argc, char ** argv, char ** envp){
  int i;
  int count;
  int pipe;
  count = 0;
  pipe = 0;
  char * checkedString;
  char * checkedString2;
  char ** list;
  char ** parsedInput;
  char ** firstHalf;
  char ** secondHalf;


  checkedString = malloc(SIZE * sizeof(char));
  checkedString[SIZE] = '\0';
  checkedString2 = malloc(SIZE * sizeof(char));
  checkedString2[SIZE] = '\0';
  list = malloc(ASIZE * sizeof(char *));
  list[ASIZE] = NULL;
  parsedInput = malloc(ASIZE * sizeof(char *));
  parsedInput[ASIZE] = NULL;
  firstHalf = malloc(ASIZE * sizeof(char *));
  firstHalf[ASIZE] = NULL;
  secondHalf = malloc(ASIZE * sizeof(char *));
  secondHalf[ASIZE] = NULL;

  list = getPathArray(envp);
  pointerPrint(list);

  char * input = malloc(200);
  input[200] = '\0';

  for(;;){
      pipe = 0;
      list = getPathArray(envp);
      printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
      printf("SUPER BASH $");
      scanf("%[^\n]%*c", input);
      pipe = pipePresent(input);

      if(pipe == 1){
        parsedInput = parse('|', input);
        firstHalf = parse(' ', parsedInput[0]);
        secondHalf = parse(' ', parsedInput[1]);
        checkedString = checkString(firstHalf, list, parsedInput[0]);
        checkedString2 = checkString(secondHalf, list, parsedInput[1]);
        exec2(checkedString, checkedString2, firstHalf, secondHalf);
      }

      else{
        parsedInput = parse(' ', input);
        pointerPrint(parsedInput);
        checkedString = checkString(parsedInput, list, input);
        exec(checkedString, parsedInput);
    }
  }

  free(input);
  free(checkedString);
  freeArray(list);
  freeArray(parsedInput);
  freeArray(firstHalf);
  freeArray(firstHalf);

  return 0;
}

int pipePresent(char * input){
  int pipe;
  int i;
  pipe = 0;
  i = 0;

  while(input[i] != '\0'){
    if(input[i] == '|'){
      pipe = 1;
    }
  i++;
  }
  return pipe;
}

char ** parse(char d, char * word){
  int og_length;
  int i;
  int start;
  int end;
  int count;
  char ** local;
  local = malloc(ASIZE * sizeof(char *));
  local[ASIZE] = NULL;
  start = 0;
  count = 0;
  og_length = getLength(word);
  for(i = 0; i < og_length + 1; i++){
    if(word[i] == d){
      end = i;
      local[count] = newString(word, start, end);
      start = i + 1;
      count ++;
    }
    else if(word[i] == '\0'){
      end = i;
      local[count] = newString(word, start, end);
    }
  }
  return local;
}

char * newString(char * original, int start, int end){
  char * new;
  int i;
  new = malloc(SIZE * sizeof(char));
  new[SIZE] = '\0';
  for (i = start; i < end; i++){
    new[i - start] = original[i];
  }
  return new;
}

int getLength(char * word){
  int count;
  count = 0;
  while (word[count] != '\0'){
    count ++;
  }
  return count;
}

int getArrayLength(char ** a_ray){
  int count;
  count = 0;
  while (a_ray[count] != NULL){
    count ++;
  }
  return count;
}

void pointerPrint(char ** path){
  int i;
  i = 0;
  printf("Address %p\n", path);
    while(path[i] != NULL){
      printf("Base[%d] Address %p Pointer Value %p String=%s\n", i, path[i], &path[i] ,path[i]);
      i++;
    }
}

char ** getPathArray(char ** envp){
  int i;
  int count;
  count = 0;
  char ** list;

  for(i = 0; envp[i] != NULL; i++){
    count++;
    char * subbie = newString(envp[i], 0, 3);
    int comp = compare(subbie, "PATH");
    if(comp == 1){
      list = parse(':', envp[i]);
    }
  }
  return list;
}

int compare(char * input1, char * input2){
  int i;
  int good;
  good = 1;
  for(i = 0; input1[i] != '\0'; i++ ){
    if(input1[i] != input2[i]) {
      good = 0;
    }
  }
  return good;
}

char * checkString(char ** parsedInput, char ** path, char * input){
  int i;
  i = 0;
  int found;
  int size;
  char * local;
  char * slash;
  found = 0;
  slash = "/";

  while (found == 0){
    if(i > 0){
      local = strcat(path[i],slash);
    }
    local = strcat(path[i], parsedInput[0]);
    printf("Checking %s\n", local);

    if (access(local, F_OK) != -1){
      printf("FOUND!\nString = '%s'\n", input);
      size = getArrayLength(parsedInput);
      size = size + 1;
      printf("Number of pointers = %d\n", size);
      pointerPrint(parsedInput);
      found = 1;
    }
    else{
      local = NULL;
    }
    i++;
    }
  return local;
}

void exec(char * pathToFile, char ** parsedInput){
  int state;
  if (fork() == 0){
    execv(pathToFile, parsedInput);
  }else {
    wait(&state);
  }
}

void exec2(char * pathToFile1, char * pathToFile2, char ** parsedInput1, char ** parsedInput2){
  int state;

  int thePipe[2];
  pipe(thePipe);
  pid_t id = fork();
  pid_t id2 = fork();

  if (id == 0){
    close(thePipe[0]);
    dup2(thePipe[1], STDIN_FILENO);
    close(thePipe[1]);
    execv(pathToFile1, parsedInput1);
    exit(EXIT_FAILURE);
    }

  if (id2 = 0){
    dup2(thePipe[0], STDIN_FILENO);
    close(thePipe[0]);
    execv(pathToFile2, parsedInput2);
    exit(EXIT_FAILURE);
  }

  else{
    close(thePipe[0]);
    wait(&state);
    wait(&id);
    wait(&id2);
  }
}


void freeArray(char ** a_ray){
  printf("\n*****FREEING*****\n");
  int i;
  for(i = 0; a_ray[i] !=  NULL; i++){
    free(a_ray[i]);
  }
  free(a_ray);
}
