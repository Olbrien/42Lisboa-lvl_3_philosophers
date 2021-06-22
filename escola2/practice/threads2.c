#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct thread_datas
{
	long long		a;
	long long		b;
	long long		result;

}			thread_data;

void *sum(void *sum)
{
	long long i = 0;
	thread_data *d_data = (thread_data *)sum;

	d_data->result += d_data->a + d_data->b;

	while (i < d_data->result)
		i++;
}

int main(int argc, char **argv)
{
	pthread_t tid[argc];
	thread_data d_data;

	if (argc != 3)
	{
		printf("Insert two values please\n");
		return (0);
	}

	d_data.a=atoll(argv[1]);
	d_data.b=atoll(argv[2]);
	d_data.result=0;

	printf("\n%lli + %lli\n\n", d_data.a, d_data.b);

	for (size_t i = 0; i < argc; i++)
	{
		pthread_create(&tid[i], NULL, sum, (void *)&d_data);
		pthread_join(tid[i], NULL);
		printf("Sum -> %lli\n\n", d_data.result);
	}

	return (0);
}

// This program passes a struct from the main() to sum() and from sum() to main() with
// only pointers.

