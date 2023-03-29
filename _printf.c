#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - print to standard output
 * @format: pointer to string
 *
 * Return: Always void.
*/
unsigned int _printf(char *format, ...)
{
	va_list ap;
	unsigned int len = 0;
	char ch;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*(format) == '%')
		{
			if (*(format + 1) == 'c')
			{
				ch = va_arg(ap, int);
				write(1, &ch, 1);
				format += 2;
			}
		}
		else
		{
			len++;
			write(1, format++, 1);
		}
	}
	va_end(ap);

	return (len);
}
