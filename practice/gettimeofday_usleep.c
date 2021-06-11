#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void microseconds(long long int value)
{
	struct timeval begin;
	struct timeval end;

	double diff;

	gettimeofday(&begin, NULL);
	usleep(value);
	gettimeofday(&end, NULL);

	printf("%lliμs\n", value);
}

void miliseconds(long long int value)
{
	struct timeval begin;
	struct timeval end;

	double diff;

	gettimeofday(&begin, NULL);
	usleep(value);
	gettimeofday(&end, NULL);

	diff = (end.tv_sec - begin.tv_sec) * 1000.0 + (end.tv_usec - begin.tv_usec) / 1000.0;
	printf("%.fms\n", diff);
}

void seconds(long long int value)
{
	struct timeval begin;
	struct timeval end;

	double diff;

	gettimeofday(&begin, NULL);
	usleep(value);
	gettimeofday(&end, NULL);

	diff = (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec) / (1000.0 * 1000.0);
	printf("%.3fs\n", diff);
}



int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please insert one number in Macroseconds!\n");
		return (0);
	}

	microseconds(atoll(argv[1]));
	miliseconds(atoll(argv[1]));
	seconds(atoll(argv[1]));
}

// μs = microseconds
// ms = miliseconds
// s  = seconds

// This program converts microseconds (from usleep()) to miliseconds and seconds.
// This program is to be run on Philosophers to see how long thread has done an action.

// To run this program you can type "time ./a.out 1000000" and you'll see it takes 1second.
// Enter different values to see what it does.
