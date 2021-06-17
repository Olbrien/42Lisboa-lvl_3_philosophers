#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;


void *routine (void *args)
{
	sem_wait(&semaphore);
	sleep(1);
	printf("Hello from: %i\n", *(int *)args);
	sem_post(&semaphore);
	free (args);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Please insert the number of threads, and the semaphore value!\n");
		return (0);
	}

	int number = atoi(argv[1]);
	pthread_t tid[number];

	sem_init(&semaphore, 0, atoi(argv[2]));

	for(int i = 0; i < number; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		pthread_create(&tid[i], NULL, routine, a);
	}

	for(int i = 0; i < number; i++)
	{
		pthread_join(tid[i], NULL);
	}


	sem_destroy(&semaphore);


}
