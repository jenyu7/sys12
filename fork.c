#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int child() {
  printf("I'm a child. (pid: %d)\n", getpid());
  srand(time(NULL) + getpid());
  int randint = rand() % 16 + 5;
  sleep(randint);
  printf("I'm done sleeping! (pid: %d)\n", getpid());
  return randint;
}

int main() {

  printf("I'm a parent. (pid: %d)\n", getpid());
  int f = fork();
  int status;

  if(f){
    int g = fork();
    if(g){
      int pid = wait(&status);
      printf("Child with pid %d slept for %d seconds\n", pid, WEXITSTATUS(status));
      printf("I (The Parent) am done. (pid: %d)\n", getpid());
      exit(0);
    }
    else {
      return child();
    }
  }
  else {
    return child();
  }

}
