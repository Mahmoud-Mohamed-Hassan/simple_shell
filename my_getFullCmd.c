#include "shell.h"
/**
 * my_getFullCmd - print the full cmd path
 *
 * @FullCmd: char pointer parameter
 * @myCmd: char pointer parameter
 * @cmdDir: char pointer  parameter
 *
 * Return: void
 */
void my_getFullCmd(char *FullCmd, char *myCmd, char *cmdDir)
{

	str_copy(FullCmd, cmdDir);
	str_cat(FullCmd, "/");
	str_cat(FullCmd, myCmd);
}
