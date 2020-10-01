#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h> 


void partial_sums(int *a, int n);
void partial_prod(int *a, int n);


int main()
{
	int n;
	printf("Enter the size of the array(min 5) : ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the array elements : \n");
	for(int i = 0; i<n; i++)
		scanf("%d", a+i);
	pid_t val;
	val = fork();
	if(val == 0)
	{
		printf("Inside child process, calculating partial sums of the input array...\n");
		partial_sums(a, n);
		printf("Exiting the child process...\n");
	}
	else if(val != -1)
	{
		printf("Inside parent process, calculating partial products of the input arry...\n");
		partial_prod(a, n);
		printf("Exiting the parent process...\n");
	}
	return 0;
}

void partial_sums(int *a, int n)
{
	printf("Child process has called and entered the partial_sums() function...\n");
	int s = 0;
	for(int i = 0; i<n ; i++)
	{
		s = s + a[i];
		printf("%d ", s);
	}
	printf("\nTotal sum of the array(inside child process) = %d\n", s);
	printf("Child process has finished calculating partial sums, exiting the function...\n");
}

void partial_prod(int *a, int n)
{
	printf("Parent process has called and entered the partial_prod() function...\n");
	int p = 1;
	for(int i = 0; i<n ; i++)
	{
		p = p * a[i];
		printf("%d ", p);
	}
	printf("\nTotal product of the array(inside parent process) = %d\n", p);
	printf("Parent process has finished calculating partial products, exiting the function...\n");
}


