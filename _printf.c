#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * _printf - print to standard output
 * @format: pointer to string
 *
 * Return: Always void.
*/
unsigned int _printf(char *format, ...)
{
	va_list ap;
	unsigned int len = 0, num;
	int i;
	char ch, *ptr;

	va_start(ap, format);
	while (*format)
	{
		len++;
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':	/* char */
					ch = va_arg(ap, int);
					write_char(ch);
					format++;
					break;
				case 'i':	/* int */
				case 'd':	/* int */
					i = va_arg(ap, int);
					write_sign(i);
					len += write_int(absolute_value(i)) - 1;
					format++;
					break;
				case 'u':
					num = va_arg(ap, int);
					len += write_int(num) - 1;
					format++;
					break;
				case 's':	/* char * */
					len--;
					ptr = va_arg(ap, char *);
					while (*ptr)
					{
						write_char(*ptr++);
						len++;
					}
					format++;
					break;
				case 'r':
					ch = *(format - 1);
					write(1, &ch, 1);
					ch = *format;
					write(1, &ch, 1);
					len++;
					format++;
					break;

				default:
					write(1, format, 1);
					format++;
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
