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
	while (*format)
	{
		len++;
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
					ch = va_arg(ap, int);
					write(1, &ch, 1);
					format++;
					break;
				default:
					write(1, format, 1);
				}
		}
		else
		{
			write(1, format++, 1);
		}

	}
	va_end(ap);

	return (len);
}
