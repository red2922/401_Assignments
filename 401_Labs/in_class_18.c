#include <stdio.h>
#include <stdlib.h>

//This code takes all environmental variables
//Then you go through each element and make substrings to look for PATH
//We compare and find PATH
//Then we parse it and put it into a 2D array
//Then we print PATH
//Then itereate through everything and free()

char ** getEnvList(char **);
char * substring(char *, int, int);
int compare(char *, char *);
char ** parse(char, char *);
void printArray(char **);
void free2D(char **);


int main(int argc, char * argv, char ** envp){
  char ** eList = getEnvList(envp);
  printArray(eList);
  free2D(eList);
}


char ** getEnvList(char ** envp){
  int i;
  int count;
  count = 0;
  char ** list;
  for(i = 0; envp[i] != NULL; i++){
    count++;
    char * subbie = substring(envp[i], 0, 3);
    int comp = compare(subbie, "PATH");
    if(comp == 1){
      printf("%s\n", envp[i]);
      list = parse(':', envp[i]);
    }
  }
  return list;
}

char * substring(char * inString, int start, int end){
  char * temp = malloc((end - start) * sizeof(char));
  temp[end-start] = '\0';
  int i;
  for (i = start; i <= end; i++){
    temp[i-start] = inString[i];
  }
  return temp;
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

char ** parse(char delim, char * string) {
  char ** envs = malloc(30 * sizeof(char *));
  envs[30] = NULL;
  int start, end, count;
  start = 5;
  end = 0;
  count = 0;

  while(string[end] != '\0'){
    if(string[end] != delim){
      end++;
    } else {
      char * temp = substring(string, start, (end - 1));
      printf("%s\n", temp);
      envs[count] = temp;
      start = end + 1;
      end++;
      count++;
    }
  }
  return envs;
}

void printArray(char ** input) {
   int i;
   for(i = 0; input[i] != NULL; i++){
     printf("%s\n", input[i]);
   }
}

void free2D(char ** input){
  int i;
  printf("\n**** FREE!! ****\n");
  for(i = 0; input[i] != NULL; i++){
    free(input[i]);
  }
  free(input);
}
