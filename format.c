#include "main.h"
/* This file contains some of the complementary function */

/**
 * get_req_funct - get the required function for the specified format specifier
 * @c: the character after the '%'symbol
 * Return: pointer to the matching function
 */
funct_pointer_t get_req_funct(char **c, flag_t *flags)
{
	int i;
	char *copy;
	associate_t asst_arr[] = {{'%', pc}, {'c', chr}, {'d', dp}, {'i', ip},
				{'s', str}, {'u', up}, {'b', pb}, {'o', po},
				{'x', px}, {'X', pX}, {'p', pp},
				{'\0', NULL}};
	i = 0;
	copy = *c;
	while (flags[i].f)/*check if the char is a flag*/
	{
		if (flags[i].f == copy[0])/*if the flag is found*/
		{
			flags[i].b = 1;/*indicate flag is present*/
			copy++;/*go to next char*/
			i = 0;/*start checking from beginning of flag array*/
		}
		else /*check the next char in the array*/
			i++;
	}
	
	i = 0; /*utilize same variable to index the functions array*/
	while (asst_arr[i].func_point)
	{
		if (asst_arr[i].c == copy[0])/*if the char after flag*/
		{
			*c = copy;/*making printf continue, after flags*/
			return (asst_arr[i].func_point);
		}
		i++;
	}
	return (NULL);
}

/**
 * chr - format complementary function for char
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int chr(va_list v, flag_t *f __attribute__((unused)))
{
	char c; /* a buffer to store the present variadic argument */

	c = va_arg(v, int);
	write(1, &c, sizeof(char));
	return (1);
}
/**
 * str - format complementary function for string
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int str(va_list v, flag_t *f __attribute__((unused)))
{
	char *s, *str; /* a buffer to store the present variadic argument */
	int count;

	s = str = va_arg(v, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (count = 0; *s; s++)
		count++;
	write(1, str, count * sizeof(char));
	return (count);
}

/**
 * pc - format complementary function for "%"
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int pc(va_list v __attribute__((unused)), flag_t *f __attribute__((unused)))
{
	char c; /* buffer to store '%' */

	c = '%';
	write(1, &c, sizeof(char));
	return (1);
}
