#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
#define TIMESIZE 10
#define MEMSIZE 100
// CYBR 401 - Operating Systems
// Homework Assignment #5
// Memory Management Modeling
struct Process{
  int procNum;
  int size;
  int time;
};

struct MemoryArea{
  int start;
  int end;
  struct Process proc;
};

struct Memory{
  int size;
  struct MemoryArea * free;
};

struct MemoryArea makeMemoryArea(int, int);
struct MemoryArea * makeBuffer(int);
struct Memory makeMemory(int);
void printMemory(struct Memory);
void printBuffer(struct MemoryArea *, int size);
struct Process makeProcess(int);
void printProcess(struct Process);
int run(struct Memory);
void aquire(struct Memory, struct Process);
void updateMemory(struct Memory);
void release(struct Memory, struct Process);
int isEmpty(struct Memory);
void freeMemory(struct Memory m);

int main() {
struct Memory m = makeMemory(MEMSIZE);
printMemory(m);
run(m);
freeMemory(m);
}

int run(struct Memory m) {
  int totalProcesses = 1;
  int empty = -1;
  srand(time(NULL));
  do {
    printf("\n*********************** ITERATION ***************************\n");
    updateMemory(m);
    if (totalProcesses < 15) {
      struct Process p = makeProcess(totalProcesses);
      printProcess(p);
      aquire(m, p);
      totalProcesses++;
    }
    printMemory(m);
    printf("\n********************** ITERATION END *************************\n\n");
    empty = isEmpty(m);
  } while (empty == 0);
  return 0;
}

struct Process makeProcess(int procNum) {
  int size;
  int t;
  struct Process p;
  t = 0;
  size = 0;
  while(size == 0){
    size = rand() % MAXSIZE;
  }
  while(t < 3){
    t = rand() % TIMESIZE;
  }
  p.procNum = procNum;
  p.size = size;
  p.time = t + 3;

  return p;
}

void printProcess(struct Process p) {
  printf("\nPROCESS:\n");
  printf("\tNum:\t%d", p.procNum);
  printf("\n\tSize:\t%d", p.size);
  printf("\n\tTime:\t%d\n", p.time);
}


int isEmpty(struct Memory m) {
  if(m.free[0].start == 1 && m.free[0].end == 100){
    m.free[0].proc.size = 0;
    return -1;
  }
  else{
    return 0;
  }

}

void aquire(struct Memory m, struct Process p) {
  int i;
  int start;
  int available;
  for(i = 0; i <= m.size;i++){
    if(m.free[i].start == -1){
      start = i - 1;
      i = m.size + 1;
    }
  }

  available = m.free[start].end - m.free[start].start;

  if(available > p.size){
    m.free[start].proc = p;
    m.free[start].end = m.free[start].start + p.size;
    m.free[start + 1].start = m.free[start].end + 1;
    m.free[start + 1].end = m.size;
  }
  else{
    printf("Not Enough Room! Releasing Memory.\n");
  }
}

void release(struct Memory m, struct Process p) {
  int i;
  int position;
  int endIndex;

  for(i = 0; i < m.size; i++){
    if(m.free[i].proc.procNum == p.procNum){
      position = i;
    }

    if(m.free[i + 1].end == -1){
      endIndex = i;
      i = m.size;
    }
  }

  for(i = position;i < endIndex;i++){
    if(i == endIndex - 1){
      m.free[i].start = m.free[i - 1].end + 1;
      m.free[i].end = m.size;
      m.free[i].proc.procNum = 0;
      m.free[i].proc.time = 0;
      m.free[i + 1].start = -1;
      m.free[i + 1].end = -1;
    }
    else{
      m.free[i].end = m.free[i].start + (m.free[i + 1].end - m.free[i + 1].start);
      m.free[i].proc = m.free[i + 1].proc;
      m.free[i + 1].start = m.free[i].end + 1;
    }

  }
}

void updateMemory(struct Memory m) {
  int i;
  for(i = 0;i <= m.size;i++){
    if(m.free[i].proc.procNum != 0 && m.free[i].proc.time <= 0){
        release(m, m.free[i].proc);
    }

    else if(m.free[i].proc.procNum != 0) {
      m.free[i].proc.time = m.free[i].proc.time - 1;
    }

  }
}

struct MemoryArea makeMemoryArea(int start, int end) {
  struct MemoryArea new;
  new.start = start;
  new.end = end;
  return new;
}

struct MemoryArea * makeBuffer(int size) {
  int i;
  struct MemoryArea * buffer;
  buffer = malloc(size * sizeof(struct MemoryArea));

  for(i = 0;i <= size;i++){
    if(i == 0){
      buffer[i].start = 0;
      buffer[i].end = size;
    }
    else{
      buffer[i].start = -1;
      buffer[i].end = -1;
    }
  }
  return buffer;
}

struct Memory makeMemory(int size) {
  struct Memory m;
  m.free = makeBuffer(size);
  m.size = size;

  return m;
}

void freeMemory(struct Memory m) {
    printf("************************ FREEING ***************************");
    free(m.free);
}

void printMemory(struct Memory mem) {
  printf("\nBUFFER:\n");
  printBuffer(mem.free, mem.size);
}

void printBuffer(struct MemoryArea * m, int size) {
  int i;
  for (i = 0; i <= size;i++){
    if(m[i].start != -1){
      printf("\n\tStart:\t%d\n", m[i].start);
      printf("\tEnd:\t%d\n", m[i].end);
      printf("\tSize:\t%d\n", m[i].proc.size);
      printf("\tProc:\t%d\n", m[i].proc.procNum);
      printf("\tTime:\t%d\n", m[i].proc.time);
    }
  }
}
