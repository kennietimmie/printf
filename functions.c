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

/**
 * write_sign - write a negative sign to standard out
 * @num: int
 *
 * Return: void
 */
void write_sign(int num)
{
        if (num < 0)
        {
                char c = '-';

                write(1, &c, 1);
        }
}
