#include "shell.h"

void sig_handler(int signo)
{
  if (signo == SIGQUIT)
    exit (99);
}
