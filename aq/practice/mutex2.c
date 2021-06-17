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
		pthread_create(&tid[i], NULL, count, NULL);

	for(int i = 0; i < number; i++)
		pthread_join(tid[i], NULL);

	pthread_mutex_destroy(&mutex);

	return (0);
}


// Now if you run ./a.out 5 | wc -l or any other value it will always give teh 100000
