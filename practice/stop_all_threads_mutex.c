#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutex_t stop_all;


void	*loop (void *args)
{
	int count = 0;
	while (1)
	{
		printf("Stop in 5!!\n");
		sleep (1);
		printf("Stop in 4!!\n");
		sleep (1);
		printf("Stop in 3!!\n");
		sleep (1);
		printf("Stop in 2!!\n");
		sleep (1);
		printf("Stop in 1!!\n");
		sleep (1);
		printf("Now!!!!!\n");
		pthread_mutex_unlock(&stop_all);
		break ;
	}

}

void	*count (void *args)
{
	int count = 0;
	while (1)
	{
		printf("2 second bra\n");
		sleep (2);
	}

}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please insert a number of arguments.\n");
		return (0);
	}
	int number = atoi(argv[1]);
	pthread_t tid[number + 1];
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&stop_all, NULL);

	pthread_mutex_lock(&stop_all);

	pthread_create(&tid[0], NULL, loop, NULL);


	for(int i = 1; i < number; i++)
		pthread_create(&tid[i], NULL, count, NULL);
pthread_mutex_lock(&stop_all);
	for(int i = 0; i < number; i++)
		pthread_join(tid[i], NULL);

	pthread_mutex_destroy(&mutex);
}
