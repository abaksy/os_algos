#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h> 

void child_fibonacci(int n);


int main(int argc, char *argv[])
{
	char *num = argv[1];
	int n = atoi(num);
	printf("You have entered %d\n", n);
	pid_t val;
	val = fork();
	if(val==0)
	{
		printf("Entered child process, calculating first %d fibonacci numbers...\n", n);
		child_fibonacci(n);
		printf("Exiting child process...\n");
	}
	else
		printf("Parent process has not called the required function, it is exiting at this point!\n");
	return 0;
}

void child_fibonacci(int n)
{
	printf("Child process has entered the function, calculating fibonacci numbers...\n");
	int f1=-1, f2=1, f3;
	for(int i = 1; i<=n ; i++)
	{
		f3 = f1+f2;
		printf("%d ",f3);
		f1 = f2;
		f2 = f3;
	}
	printf("\nFinished executing inside child process' function, exiting...\n");
}
