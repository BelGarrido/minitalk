// must be started first
// after its launch it has to print its PID
// must print the string after receiving the the string from client
// must display the string pretty quickly
// server must be able to receive several string from differents clients in a row without needing to restart
// communication must be done only using UNIX signals
// you only can use SIGUSR1 and SIGUSR2


#include <stdio.h>
#include <unistd.h>
#include "minitalk.h"

int main(void)
{
  pid_t pid;

  pid = getpid();
  //ft_printf("The process ID is %d\n", pid);
  printf("The process ID is %d\n", pid);

  return 0;
}