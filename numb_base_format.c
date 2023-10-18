#include "main.h"

/**
 * nsc - number system (base) converter and formater
 * @v: the pointer to the present argument of the variadic arguments
 * @X: determine wether the hexadecimal system should for %x or %X
 * if the number base is not hexa, 0 should be put in it place.
 * @base: the base to which the number is to be printed
 * Return: the number of byte "formatted to stdout"
 */
int nsc(va_list v, int  base, int X)
{
	unsigned long i, i2;
	char *s; /* pointer to buffer */
	int buff_size, buff_size_copy; /* size of buffer to store string */

	i2 = i = va_arg(v, unsigned long);
	for (buff_size = 0; i > 0; buff_size++)
		i = i / base; /* get the the buffer required size */
	s = malloc(sizeof(char) * buff_size);
	if (s == NULL)
		return (0);
	buff_size_copy = buff_size; /* backing up size */
	s[buff_size--] = '\0'; /* buff_size amaze me alot since, due sz space*/
	while (buff_size >= 0)  /*converting the unsigned int to bin in buff*/
	{
		if (i2 % base > 9)
			s[buff_size--] = (i2 % base) + X; /* hexa > 9 to alpha */
		else
			s[buff_size--] = (i2 % base) + '0';
		i2 = i2 / base;
	}
	write(1, s, buff_size_copy); /* writing to stdout */
	free(s); /* free buffer */
	return (buff_size_copy);
}
/**
 * pb - custom conversion specifier; formating numbers to to binary
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int pb(va_list v, flag_t *f __attribute__((unused)))
{
	return (nsc(v, 2, 0));
}
/**
 * po - custom conversion specifier; formating numbers to to octal
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int po(va_list v, flag_t *f __attribute__((unused)))
{
	return (nsc(v, 8, 0));
}
/**
 * px - custom conversion specifier; formating numbers to hexadecimal base
 * where a-f are in small case.
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int px(va_list v, flag_t *f __attribute__((unused)))
{
	return (nsc(v, 16, 87));
}
/**
 * pX - custom conversion specifier; formating numbers to hexadecimal base
 * where A-F  are in capital case.
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int pX(va_list v, flag_t *f __attribute__((unused)))
{
	return (nsc(v, 16, 55));
}
