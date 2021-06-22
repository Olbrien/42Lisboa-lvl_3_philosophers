#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


void *summer(void *sum)
{
	int *num = (int *)sum;
	*num += 12;


	printf("-->%i\n", *num);
}

int main(int argc, char **argv)
{
	pthread_t tid;

	int	number;

	number = 2;

	pthread_create(&tid, NULL, summer, (void *)&number);


	pthread_join(tid, NULL);
	printf("--->%i\n", number);

	return (0);
}

// This program passes an int from main() to sum() and sum() to main() with pointers only.

