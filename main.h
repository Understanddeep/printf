#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


/**
 * struct flag - associates a flag (char) to a boolean, true/false
 * @f: the character that represents the flag.
 * @b: the switch that indicates the presence of the flag
 */
typedef struct flag
{
	char f;
	short b;
}flag_t;	/* a type to declare this struct at any instant*/

typedef int (*funct_pointer_t)(va_list, flag_t *);/* a type to dclr the fnctn pointer */

/**
 * struct life - associates a char to matching formating function
 * @c: the char for format specification
 * @func_point: pointer to the matching formating function
 */
typedef struct life
{
	char c;
	funct_pointer_t func_point;
} associate_t;	/* a type to declare this field at any time */



/* formatting functions and function to get them */
funct_pointer_t get_req_funct(char **, flag_t *);
int _printf(const char *format, ...);
int nsc(va_list, int, int);
void ips(unsigned int);
int chr(va_list, flag_t *);
int dp(va_list, flag_t *);
int ip(va_list, flag_t *);
int pc(va_list, flag_t *);
int pb(va_list, flag_t *);
int po(va_list, flag_t *);
int px(va_list, flag_t *);
int pX(va_list, flag_t *);
int str(va_list, flag_t *);
int sb(va_list, flag_t *);
int up(va_list, flag_t *);
int pp(va_list, flag_t *);
int pr(va_list, flag_t *);
int pR(va_list, flag_t *);
void de_init(flag_t *); /*unflags flags, so they don't conflict for the next conversion specifier.*/
/* formatting functions end here! */

#endif /* MAIN_H */
