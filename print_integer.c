#include "main.h"
/**
 * print_integer - Print an integer to the standard output
 * @num: The integer to be printed
 *
 * Return: The number of characters printed.
 */
int print_positive_integer(int num);
int count_digits(int num);
int print_integer(int num)
{
    int count = 0;
    

    if (num < 0)
    {
        _putchar('-');
        count++;
        num *= -1;
    }

    if (num == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        count += print_positive_integer(num);
    }

    return (count);
}

/**
 * print_positive_integer - Print a positive integer to the standard output
 * @num: The positive integer to be printed
 *
 * Return: The number of characters printed.
 */
int print_positive_integer(int num)
{
    int count = 0;
    int i;
    int num_digits = count_digits(num);

    char *digits = malloc(num_digits * sizeof(char));
    if (digits == NULL)
    {
        return (-1);
    }

    for (i = num_digits - 1; i >= 0; i--)
    {
        digits[i] = (num % 10) + '0';
        num /= 10;
    }

    for (i= 0; i < num_digits; i++)
    {
        _putchar(digits[i]);
        count++;
    }

    free(digits);

    return (count);
}

/**
 * count_digits - Count the number of digits in an integer
 * @num: The integer to count digits for
 *
 * Return: The number of digits in the integer.
 */
int count_digits(int num)
{
    int count = 0;

    while (num != 0)
    {
        count++;
        num /= 10;
    }

    return count;
}
