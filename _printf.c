#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Print formatted text to the standard output
 * @format: A pointer to a format string
 * @...: Variable number of arguments depending on the format string
 *
 * Return: The number of characters printed (excluding the null byte)
 *         or -1 if format is NULL or an invalid format specifier is used.
 */

int handle_format_specifier(const char **format, va_list args);
int handle_format_specifier(const char **format, va_list args);
int print_string(const char *str);
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += handle_format_specifier(&format, args);
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);
}

/**
 * handle_format_specifier - Handle format specifiers within _printf
 * @format: A pointer to a pointer to the current format specifier
 * @args: A va_list containing the variable arguments
 *
 * Return: The number of characters printed for the current format specifier.
 */
int handle_format_specifier(const char **format, va_list args)
{
	int count = 0;

	if (**format == 's')
	{
		char *str = va_arg(args, char *);

		count += print_string(str);
	}
	else if (**format == 'c')
	{
		char ch = (char)va_arg(args, int);

		_putchar(ch);
		count++;
	}
	else if (**format == '%')
	{
		_putchar('%');
		count++;
	}
	return (count);
}
/**
 * print_string - Print a string to the standard output
 * @str: A pointer to the string to be printed
 *
 * Return: The number of characters
 * printed (excluding the null byte) in the string.
 */
int print_string(const char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
