#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void *my_turn(void *arg)
{
	int i = 0;

	for(int a = 0; a < 2; a++)
	{
		printf("(%i) My turn!\n", i);
		i++;
		sleep (1);
	}
	return (NULL);
}

void *your_turn(void *arg)
{
	int i = 0;

	for(int a = 0; a < 5; a++)
	{
		printf("(%i) Your turn!\n", i);
		i++;
		sleep (1);
	}
	return (NULL);
}

int	main()
{
	pthread_t newthread;
	pthread_t newthread2;

	pthread_create(&newthread, NULL, my_turn, NULL);
	pthread_create(&newthread2, NULL, your_turn, NULL);

	pthread_join(newthread, NULL);
	pthread_join(newthread2, NULL);

	return (0);
}

// Simple pthreads.
