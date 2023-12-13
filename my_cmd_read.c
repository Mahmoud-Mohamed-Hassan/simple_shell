#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * my_cmd_read - read cmd
 *
 * Return: myBuffer
 */
char *my_cmd_read(void)
{
	char *myBuffer = NULL;
	size_t bufferLength = 0;
	ssize_t result;

	if (isatty(STDIN_FILENO))
		mahmoud_print("$mahmoud_ ");
	result = getline(&myBuffer, &bufferLength, stdin);

	if (result == -1)
	{
		free(myBuffer);
		return (NULL);
	}
	return (myBuffer);
}
