#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int main()
{
	pthread_t 			*t_id;
	pthread_mutex_t 	*forks;

	t_id = malloc(sizeof(pthread_t) * 5);
	forks = malloc(sizeof(pthread_mutex_t) * 5);

	free(t_id);
	free(forks);


}
