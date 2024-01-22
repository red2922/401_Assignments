#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define ASIZE 50

char ** parse(char *, char *);
int getLength(char *);
char * newString(char *, int, int);
void freeArray(char **);

int main(int argc, char * argv[]){
  char * delim;
  char * saved;
  int i;
  char ** global_array;
  i = 0;

  if (argc == 3){
    printf("You entered the correct number of inputs\n");
  }else{
    printf("You did not enter the correct number of inputs. Please enter the the correct arguments and run again");
    abort();
  }

  delim = argv[1];
  saved = argv[2];

  printf("\nYour delimiter is: %s\n", delim);
  printf("\nThe string you entered is: %s\n", saved);

  global_array = parse(delim, saved);

  while (global_array[i] != NULL){
    printf("%s Length %d\n", global_array[i], getLength(global_array[i]));
    i++;
  }
  freeArray(global_array);

  return 0;
}

char ** parse(char * d, char * s){
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
  og_length = getLength(s);

  for(i = 0; i < og_length + 1; i++){
    if(s[i] == d[0]){
      end = i;
      local[count] = newString(s, start, end);
      start = i + 1;
      count ++;
    }
    else if(s[i] == '\0'){
      end = i;
      local[count] = newString(s, start, end);
    }
  }
  return local;
}

int getLength(char * word){
  int count;
  count = 0;
  while (word[count] != '\0'){
    count ++;
  }
  return count;
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

void freeArray(char ** a_ray){
  printf("\n*****FREEING*****\n");
  int i;
  for(i = 0; a_ray[i] !=  NULL; i++){
    free(a_ray[i]);
  }
  free(a_ray);
}
