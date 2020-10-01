#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	printf("We are in exec2.c.\n");
	printf("PID of exec2.c = %d\n", getpid());
	return 0;
}
