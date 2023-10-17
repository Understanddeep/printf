#include "preenteff.h"

/**
 * _preenteff - function name
 * @layout: variable to char
 * Return: EXIT_SUCCESS
 */
int _printf(const char *layout, ...)
{
	short int locator, len;
	char mem[BUFFSIZE];

	locator = len = 0;

	while (layout[locator] != 0)
	{
		if (layout[locator] == '%')
		{
			locator += 2;
			continue;
		}
		else
		{
			mem[len] = layout[locator];
			len++;
			locator++;
		}
	}
	write(STDOUT_FILENO, mem, len);
	return (0);
}



