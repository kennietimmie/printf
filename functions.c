#include <unistd.h>
/**
 * write_char - write a character to standard out
 * @c: char
 *
 * Return: void
 */
void write_char(char c)
{
	write(1, &c, 1);
}
