#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
 printf("%p",4["hola"]);
  char prog[1024];
  for(;;)
	{
		printf("yes, master...");
		fgets(prog, sizeof(prog), stdin);
		prog[strlen(prog)-1] = 0; /** Quitamos el \n */
		if(strcmp(prog,"fin")==0)
			return 0;
		if(fork() == 0)
		{
			execl(prog,prog,NULL);
			exit(-1);
		}
		else wait(NULL);
	}
  return 0;
}

