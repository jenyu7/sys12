#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  srand( time(NULL) );
  printf("Before Fork\n");
  int rand_num = 2; //5 + rand() % 20;
  int f = fork();
  if (!f) {
    printf("I am a child, my pid is: %d\n", getpid());
    sleep(rand_num);
    printf("I am done sleeping.\n");
  }
  else {
    wait(&rand_num);
    printf("I am a parent, my pid is: %d\n", getpid());
    printf("my child was asleep for: %d\n", rand_num);
  }
  return 0;
}
