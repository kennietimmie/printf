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

/**
 * write_int - write a integer to standard out
 * @num: unsigned int - integer
 *
 * Return: int - number of characters in integer (num).
 */
int write_int(unsigned int num)
{
        int div, mod;
	int characterLength = 0;
        if (num <= 9){
                char ch;
                mod = num % 10;
                ch = mod + '0';

                write(1, &ch, 1);
		characterLength++;
                return (characterLength);

        }
        div = num / 10;
        mod = num % 10;
        characterLength += write_int(div);
        characterLength += write_int(mod);
	
	return (characterLength);
}

/*
 * absolute_value - returns the absolute value.
 * @num: int - integer
 *
 * Return: int - absolute value.
 */
int absolute_value(int num)
{
	if (num < 0)
		return (num * -1);

	return (num);
}
