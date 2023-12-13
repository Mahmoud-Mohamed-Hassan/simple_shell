#include "shell.h"
/**
 * my_cmd_execute - execute cmd
 *
 * @myCmd: char ptr parameter
 * @argv: char ptr parameter
 * @index: int  parameter
 *
 * Return: void
 */
int my_cmd_execute(char **myCmd, char **argv, int index)
{
	pid_t myChild;
	int status;
	char *fullCmd;

	fullCmd = my_getpath(myCmd[0]);
	if (fullCmd == NULL)
	{
		my_printerror(argv[0], myCmd[0], index);
		my_FreeArrOfString(myCmd);
		return (127);
	}

	myChild = fork();

	if (myChild == 0)
	{
		if (execve(fullCmd, myCmd, environ) == -1)
		{
			free(fullCmd), fullCmd = NULL;
			my_FreeArrOfString(myCmd);
		}
	}
	else
	{
		waitpid(myChild, &status, 0);
		my_FreeArrOfString(myCmd);
		free(fullCmd), fullCmd = NULL;
	}
	return (WEXITSTATUS(status));
}
