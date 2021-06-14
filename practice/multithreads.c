#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int	times = 0;
pthread_mutex_t mutex[2];

typedef struct s_teste
{
	int	i;

}	t_teste;

void	*sleeping(void *arg)
{

	t_teste *d_data = (t_teste *)arg;

	printf("-->%i\n",d_data->i);

	pthread_mutex_lock(&mutex[1]);
	printf("AQUI\n");
	sleep(2);
	pthread_mutex_unlock(&mutex[1]);

	printf("nao vens aqui primeiro?\n");


}

int main()
{
	int max = 3;
	pthread_t tid[3];
	int i = 0;

	t_teste	*da;

	da = malloc(sizeof(t_teste) * 3);
	da[0].i = 0;
	da[1].i = 1;
	da[2].i = 2;

	pthread_mutex_init(&mutex[0], NULL);
	pthread_mutex_init(&mutex[1], NULL);
	pthread_mutex_init(&mutex[2], NULL);
	while (i < max)
	{
		pthread_create(&tid[i], NULL, sleeping, &da[i]);
		i++;
	}
	i = 0;
	while (i < max)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex[0]);
	pthread_mutex_destroy(&mutex[1]);
	pthread_mutex_destroy(&mutex[2]);
}


// This is to run multiple threads and see their reactions.
// If it waits for one thread to finish, or goes immediately to the second one and third etc...
