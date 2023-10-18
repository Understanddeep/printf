#include "main.h"

/* remember to remove the original printf, you used for testing flags[]*/
/**
 * _printf - format and prints to the stdout
 * @format: the format specifiers
 * Return: the number of byte printed
 */
int _printf(const char *format, ...)
{
	int byte_count;
	char *copy;
	va_list v;
	flag_t flags[] = {{'-', 0}, {'0', 0}, {'+', 0}, {' ', 0}, {'#', 0},
			{'\0', 0}};
/*	short i;*/
	funct_pointer_t match_func;

	match_func = NULL;
	va_start(v, format);
	copy = (char *) format;
	if (format == NULL)
		return (0);
	for (byte_count = 0; *copy; copy++)
	{
		if (*copy == '%')
		{
			++copy;
			match_func = get_req_funct(&(copy), flags);
			if (match_func) /* if format specifier function exist*/
				byte_count += match_func(v, flags);
			else /* what do if format specifier doesn't exist */
			{
				write(1, copy, 1);
				byte_count++;
			}
		}
		else
		{
			write(1, copy, 1);
			byte_count++;
		}
	}
	/* testing my flags
	i = 0;
	while (i <= 5)
	{
		printf("%c is %d\n", flags[i].f, flags[i].b);
		i++;
	}
	de_init(flags);
	i = 0;
	while (i <= 5)
	{
		printf("%c is %d\n", flags[i].f, flags[i].b);
		i++;
	}
	 flag test ends here */
	va_end(v);
	return (byte_count);
}
