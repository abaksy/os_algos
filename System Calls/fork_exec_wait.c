#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main()
{	
	pid_t forkstatus;
	forkstatus = fork();
	if(forkstatus == 0)
	{
		printf("Child is running, proccessing.\n");
		char com[50];
		char *args[50];
		printf("Enter the command or file name you wish to execute(child process is requesting : ");
		scanf("%[^\n]s", com);
		char *tok = strtok(com, " ");
		args[0] = tok;
		int i = 1;
		while(tok!=NULL)
		{
			tok = strtok(NULL, " ");
			args[i++] = tok;
		}
		args[i] = NULL;		
		execvp(args[0], args);
		sleep(5);
		printf("Child is done, exiting.\n");
	}
	else if(forkstatus!=-1)
	{
		printf("Parent is waiting...\n");
		wait(NULL);
		printf("Parent has terminated the child process and is exiting...\n");
	}
	else
		perror("Error while calling the fork function!\n");
	return 0;
}
