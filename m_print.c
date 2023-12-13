#include "shell.h"
/**
 * mahmoud_print - prints
 *
 * @myText: int parameter
 *
 * Return: void
 */
void mahmoud_print(const char *myText)
{
	write(STDOUT_FILENO, myText, strlen(myText));
}
