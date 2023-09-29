#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
* infinite_while - creates an infinite loop
*
* Return: 0 (always)
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}


/**
* main - entry point
*
* Return: 0 (success)
*/
int main(void)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			printf("Zombie process created, PID: %d\n", getpid());
			exit(0);
		}
		else if (child_pid < 0)
		{
			perror("Fork failed\n");
			exit(1);
		}
	}

	infinite_while();

	return (0);
}
