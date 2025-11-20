#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on format specifiers
 * @format: list of types of arguments passed to the function
 *          c: char
 *          i: integer
 *          f: float
 *          s: char * (prints (nil) if string is NULL)
 *
 * Description: Prints values based on format string.
 *              Ignores any other format characters.
 *              Prints a new line at the end.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *sep = "";
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(args, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(args, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(args, double));
				sep = ", ";
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", sep, str);
				sep = ", ";
				break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
