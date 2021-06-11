#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT_TO 100000

long long co = 0;

void *count(void *counter)
{
	while(1)
	{
		if (co >= COUNT_TO)
			break ;
		printf("%lli\n", co);
		co++;
	}
}

int main(int argc, char **argv)
{
	int number = atoi(argv[1]);
	pthread_t tid[number];

	for(int i = 0; i < number; i++)
		pthread_create(&tid[i], NULL, count, NULL);

	for(int i = 0; i < number; i++)
		pthread_join(tid[i], NULL);

	return (0);
}


// This program doesn't have mutex so you can see the outcome.
// Compile it and do ./a.out 2 | wc -l or other multiple threads and do it several times.
// You'll see that the count won't be 100000.
