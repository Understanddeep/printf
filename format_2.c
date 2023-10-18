#include "main.h"

/**
 * ips - convert an integer to it character and help print to stdout
 * this is a support function for the main (%i and %d) format specifier fnctns
 * @i: a positive integer
 */
void ips(unsigned int i)
{
	char c;

	if (i < 10)
		c = i + '0';
	else
	{
		c = (i % 10) + '0';
		ips(i / 10);
	}
	write(1, &c, 1);
}

/**
 * dp - function for decimal integer format specifier
 * @v: variable storing the varags/ variable arguement
 * Return: the size of an integer
 */
int dp(va_list v, flag_t *f __attribute__((unused)))
{
	long int i;
	int size;

	i = va_arg(v, long int);
	if (i < 0)
	{
		i = -i;
		write(1, "-", 1);
	}
	ips(i);
	for (size = 1; i >= 10; size++)
		i = i / 10;
	return (size);
}

/**
 * ip - function for all  integers (of all type) format specifier
 * @v: variable storing the varags/ variable arguement
 * Return: the size of an integer
 */
int ip(va_list v, flag_t *f __attribute__((unused)))
{
	int size;
	long int i;

	i = va_arg(v, long int);
	if (i < 0)
	{
		i = -i;
		write(1, "-", 1);
	}
	ips(i);
	for (size = 1; i >= 10; size++)
		i = i / 10;
	return (size);
}
/**
 * up - function for unsigned format specifier
 * @v: variable storing the varags/ variable arguement
 * Return: the size of an integer
 */
int up(va_list v, flag_t *f __attribute__((unused)))
{
	int size;
	unsigned int i;

	i = va_arg(v, unsigned int);
	ips(i);
	for (size = 1; i >= 10; size++)
		i = i / 10;
	return (size);
}
