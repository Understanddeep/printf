#include "main.h"
/*This file also contain some of the complimentary functions */

/**
 * pp - prints pointers (address of other variable, functions etc
 * @v: pointer on the stack, pointing to the memory containing an address
 * Return: the length of the digits printed
 */
int pp(va_list v, flag_t *f __attribute__((unused)))
{
	unsigned long addr, addr_cp;/*store, manipulate each digit of address*/
	short len, len_cp;/*to get the length, and indent through buffer */
	char *buff;/* to store each individual bit separately */

/*using / and % trick, along with 16, to get the length of the value*/
/*while converting, the value store in hexa-decimal, the same trick*/
/*taught, in primary schools { divide by 16, and keep remainder}*/

	addr = addr_cp = va_arg(v, unsigned long);
	if (!addr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	for (len = 2; addr_cp > 0; len++)/*getting the length of buffer req*/
		addr_cp /= 16;
	/*I added, to more bytes, to compensate for the "0x"that always*/
	/* appear in front of an address*/
	len_cp = len;
	buff = malloc(sizeof(char) * len);/*getting buff, & handling err*/
	if (!buff)
		return (0);
	--len_cp; /*preventing segfault (accessing illegal memory*/
	/*now storing the resulting hex in the buffer, digit by digit*/
	buff[0] = '0';
	buff[1] = 'x';
	while (addr)
	{
		if (addr % 16 > 9)
			buff[len_cp--] = (addr % 16) + 87; /* 97=a(10),102=f */
		else
			buff[len_cp--] = (addr % 16) + 48;/*conv to ascii pos*/
		addr /= 16;
	}
	/*writing buffer content to stdout*/
	write(1, buff, len);
	free(buff);/*freeing manually allocated memory*/
	return (len);/*the number of byte written to stdout*/
}

/**
 * de_init - de-initializes flags presence after use
 * @flags: pointer to array of flag struct
 */
void de_init(flag_t *flags)
{
	while (flags->f)
	{
		flags->b = 0;
		flags++;
	}
}
