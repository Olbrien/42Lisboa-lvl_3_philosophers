![GitHub Logo](/extras/images/Success.png)

###### <i>Recent Update on 16/09/2021.</i>
• Finished the project.

###### <i>Old Update on 16/06/2021.</i>
• Stopped the project to focus on Junior Lifeguard (Staff) Projects.

###### <i>Old Update on 13/06/2021.</i>
• Started the project.

## Subject:

You can find the subject of this project [here.](https://github.com/Olbrien/42Lisboa-lvl_3_philosophers/blob/main/extras/lvl_3_philosophers.pdf)

![GitHub Logo](/extras/images/pic1.png)

## How to run:

First download the repository.

Go to the folder 'philo' or 'philo_bonus' and do a "make".\
You will get an executable file called 'philo" or 'philo_bonus'.

## Cases to run:

Accordingly to what you get, you can run the program with the following arguments:

- First Argument: Number of Philosophers
- Second Argument: Time to Die in Milliseconds
- Third Argument: Time to Eat in Milliseconds
- Fourth Argument: Time to Sleep in Milliseconds
- Fifth Argument: Times each Philosopher has to eat (optional)

`./philo 1 800 200 200` - Philosopher should not eat and die.\
`./philo 5 800 200 200` - No Philosopher should die.\
`./philo 5 800 200 200 7` - No Philosopher should die and it should stop after they have all eaten at least 7 times.\
`./philo 4 410 200 200` - No Philosopher should die.\
`./philo 4 310 200 100` - One Philosopher should die.

## Research:

<pre>
------------------------------------------------------------------------------------
Difference between Threads and Fork():

	A fork gives us a brand new process which is a copy of the current process with the same code
	segment. It looks exactly like the parent process with different process id having it's own
	memory.	Parent process creates a separate address space for the child with same code segments
	but	executes independently of each other. Because the system issues a new memory space and
	environment	for the child process, it is knows as heavy-weight process.

	While threads can execute in parallel with same context. Also, memory and other resources
	are shared between the threads causing less overhead. A thread process is considered a
	sibling while a forked process is considered a child. Also, threads are known as light-weight
	processes as they don't have any overhead as compared to processes


Threads:

	To gcc a thread you have to do for example:

		"gcc -pthread main.c"


	To set a pthread it's, for example:

		"pthread_t newthread"

	To create a thread it's, for example:

		"pthread_create(&newthread, NULL, my_turn_function, NULL);"

	To wait for the thread to finish before exiting:

		"pthread_join(newthread, NULL);"

	(I have examples on Threads on a folder.)


Detached:

	Using deatched is a different approach to use pthread_join().

	You can detach a process imediatelly after using it.
	Not having to wait to run all the processes first, and then detach it.

	Instead of doing this:

		{
			for(int i = 0; i < 100; i++)
				pthread_create(&tid[i], NULL, count, NULL);

			for(int i = 0; i < 100; i++)
				pthread_join(tid[i], NULL);
		}

		This creates 100 processes, and then in the end it closes it.

	Detach does this:

		{
			for(int i = 0; i < 100; i++)
			{
				pthread_create(&tid[i], NULL, count, NULL);
				pthread_detach(tid[i]);
			}
		}

		This creates 1 process and after using it, it closes.

------------------------------------------------------------------------------------

Difference between Mutex and Semaphores:

	Mutex only allows one thread into a controlled section, forcing other threads which
	are trying to access to that section to wait until it has exited.
	Mutex only allows one thread to access resources.

	Semaphore is a signal mechanism. It allows a number of threads to access a resource.

Mutex:

	Imagine a room of people. There is one microphone. The person holding the microphone can
	speak. When the person finishes speaking, it passes the microphone to another person,
	and now that person can speak. And so on.

	The microphone is Mutex, the people are Threads.


	Mutex solves several threads changing the same variable at the same time. Mutex makes sure
	it changes it one thread at a time and not all at the same time.

	Script:

		int a = 0;
		phtread_mutex_t mutex;
		phtread_mutex_init(&mutex, NULL);

		while (1)
		{
			pthread_mutex_lock(&mutex);
			a++;
			pthread_mutex_unlock(&mutex);
		}
		phtread_mutex_destroy(&mutex);


-------------------------------------------------------------------------------------------------

memset:

	Sets the first num bytes of the block of memory pointed by ptr to the specified value.

		#include <stdio.h>
		#include <string.h>
		#include <stdlib.h>

		int	main()
		{
			char *str;

			str = malloc(sizeof(char) * 12);
			memset(str, 'X', 12);

			free(str);
			return (0);
		}

		Output:
			XXXXXXXXXXXX


Usleep:

	The function sleep() is in seconds, the usleep() is in microseconds.

	{
		usleep(5000000);
		printf("%s\n", "5000000 microseconds");

		sleep(5);
		printf("%s\n", "5 seconds");
	}

		Both are 5 seconds.


	Seconds (s), miliseconds (ms), microseconds (us), nanoseconds (ns)

		1 second
		1 milisecond = 1/1000 of a second
		1 microsecond = 1 / (1000x1000) second
		1 nanosecond = 1 / (1000x1000x1000) second


Gettimeofday:

	The gettimeofday() function gets the system’s clock time. The current time is
	expressed in elapsed seconds and microseconds since 00:00:00, January 1, 1970
	(Unix Epoch).

	And stores it in a timeval structure.

	It is useful this function because you can create two gettimeofday(), and subtract
	both results and see how much a part of a program took to execute.
------------------------------------------------------------------------------------
</pre>
