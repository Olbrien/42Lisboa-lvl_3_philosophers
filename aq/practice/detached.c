#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT_TO 100000

long long co = 0;
pthread_mutex_t mutex;

void *count(void *counter)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);

		if (co >= COUNT_TO)
		{
			pthread_mutex_unlock(&mutex);
			break ;
		}
		printf("%lli\n", co);
		co++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char **argv)
{
	int number = atoi(argv[1]);
	pthread_t tid[number];
	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < number; i++)
	{
		pthread_create(&tid[i], NULL, count, NULL);
		pthread_detach(tid[i]);
	}
	pthread_exit(0);

	pthread_mutex_destroy(&mutex);
}

// With detach you don't need to do pthread_join() to wait for the thread to finish.
// You can do this way or the other way on detached2.c
