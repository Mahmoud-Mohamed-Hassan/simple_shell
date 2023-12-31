#include "shell.h"
/**
 * my_getenv - execute cmd
 *
 * @envVariable: char ptr parameter
 *
 * Return: envValueDuplicate
 */
char *my_getenv(char *envVariable)
{
	char *envDuplicate, *envKey, *envValue, *envValueDuplicate;
	int i;

	for (i = 0; environ[i]; i++)
	{
		envDuplicate = str_duplicate(environ[i]);
		envKey = strtok(envDuplicate, "=");

		if (str_compare2(envKey, envVariable) == 0)
		{
			envValue = strtok(NULL, "\n");
			envValueDuplicate = str_duplicate(envValue);
			free(envDuplicate);
			return (envValueDuplicate);
		}

		free(envDuplicate), envDuplicate = NULL;
	}
	return (NULL);
}
