#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>          //for execlp()
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
  char input[MAX_INPUT_LENGTH];

  while (1) {
    printf("Shell> ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strlen(input) - 1] = '\0';              //remove newline character after fgets

    pid_t pid = fork();                           //fork new process of process ID type

    if (pid == 0) {                               //child process - each has its own unique process ID (PID)
      execlp(input, input, NULL);                 //executes commands
      perror("error exec");                       //if execlp fails, print
      exit(EXIT_FAILURE);                         //exit child process
    }
    else if (pid > 0) {                           //parent process
      wait(NULL);                                 //wait child process to finish
    }
    else {
      perror("fork");                             //fork fail
    }
  }

  return 0;
}


/*
  After fork call, two process run concurrently: parent and child processes
  Fork returns different values in parent and child processes. Return type of fork is pid_t (process ID type)
  Child process, return value is 0
  Parent process, return value is > 0
*/

// printf("-- Child Process (PID: %d)\n", getpid());

// printf("-- Parent Process (Child PID: %d, Parent PID: %d)\n", pid, getpid());
