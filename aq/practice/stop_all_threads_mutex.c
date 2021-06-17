#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;


void *stop_all_threads (void *threads)
{
    while (1)
    {
        printf("Stopping in 5\n");
        sleep (1);
        printf("Stopping in 4\n");
        sleep (1);
        printf("Stopping in 3\n");
        sleep (1);
        printf("Stopping in 2\n");
        sleep (1);
        printf("Stopping in 1\n");
        sleep (1);
        pthread_mutex_unlock(&mutex);
        break ;

    }
    return (NULL);

}

void *count (void *counter)
{
    pthread_t tid;
    pthread_create(&tid, NULL, stop_all_threads, NULL);    
    while (1)
    {
        printf("Sleep 1!\n");
        sleep (1);
    }
    pthread_join(tid, NULL);
        return (NULL);

}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please insert a value!\n");
        return (0);
    }
	int number = atoi(argv[1]);
	pthread_t tid[number];
	pthread_mutex_init(&mutex, NULL);

    pthread_mutex_lock(&mutex);    

	for(int i = 1; i < number; i++)
		pthread_create(&tid[i], NULL, count, NULL);

	for(int i = 0; i < number; i++)
		pthread_join(tid[i], NULL);

	pthread_mutex_destroy(&mutex);

	return (0);
}