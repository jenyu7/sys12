/********
 * Adeebur Rahman and Jen Yu
 * Work #12: Please Fork Responsibly
 * Systems Pd 10
 * 2017-11-16
 ********/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

//sleeping child
int child() {
  printf("I'm a child. (pid: %d)\n", getpid());
  srand(time(NULL));
  int randint = rand() % 16 + 5;
  sleep(randint);
  printf("I'm done sleeping! (pid: %d)\n", getpid());
  return randint;
}

int main() {

  printf("I'm a parent. (pid: %d)\n", getpid());
  //Fork for 1st child
  int f = fork();
  int status;

  //f != 0 only if process has a child (parent process)
  if(f){
    //Fork for 2nd child
    int g = fork();
    //For parent process
    if(g){
      int pid = wait(&status);
      printf("Child with pid %d slept for %d seconds\n", pid, WEXITSTATUS(status));
      printf("I (The Parent) am done. (pid: %d)\n", getpid());
      exit(0);
    }
    //for child process #2
    else {
      return child();
    }
  }
  //for child process #1
  else {
    return child();
  }

}
