#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


void *hello(void *sum)
{
	char *hello = "hello from the other side!";

	printf("%s\n", hello);

	pthread_exit(hello);


}

int main(int argc, char **argv)
{
	pthread_t tid;

	char *string;

	pthread_create(&tid, NULL, hello, NULL);


	pthread_join(tid, (void *)&string);
	printf("%s\n", string);

	return (0);
}

// This program returns a value from hello() to main, using pthread_exit and pthread_join.

