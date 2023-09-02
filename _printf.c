#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
			if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str != '\0')
				{
					_putchar(*str);
					count++;
					str++;
				}
			}
			else if (*format == 'c')
			{
				char ch = (char)va_arg(args, int);

				_putchar(ch);
				count++;
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(args);

	return (count);

}
