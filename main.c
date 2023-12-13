#include "shell.h"

/**
 * main - shell entry point
 * @ac: arg c
 * @argv: arg v
 *
 * Return: status value
 */

int main(int ac, char **argv)
{
	char *myLine = NULL;
	int myStatus = 0, index = 0;
	char **myCmd = NULL;
	(void)ac;

	while (1)
	{
		myLine = my_cmd_read();
		if (myLine == NULL)
		{
			if (isatty(STDIN_FILENO))
				mahmoud_print("\n");
			return (myStatus);
		}
		index++;
		myCmd = my_tokenizer(myLine);
		if (!myCmd)
			continue;
		if (my_builtin_check(myCmd[0]))
		{
			my_builtin_handle(myCmd, argv, &myStatus, index);
		}
		else
			myStatus = my_cmd_execute(myCmd, argv, index);
	}
}
