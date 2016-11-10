#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

void sighandeler( int sig ) {
  if( sig == SIGINT ) {
    printf("Program terminated due to SIGINT\n");
    int fd = open("log.txt", O_APPEND | O_CREAT, 0644);
    write(fd, "Exited due to SIGINT error\n", 25);
    close(fd);
    exit(1);
  }
  if( sig = SIGUSR1 ) {
    printf("SIGUSR1 error.\nParent PID: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandeler);
  signal(SIGUSR1, sighandeler);
  
  while(1) {
    printf("PID: %d\n", getpid());
    kill(getpid(), SIGUSR1);
    sleep(1);
  }

  return 0;
}
