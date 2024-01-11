#include <unistd.h>
#include <stdarg.h>

void	ft_putstring(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while(*string)
		*length += write(1, string++, 1);
}

void ft_putdigit(long long int digit, int base, int *length)
{
	char *hex = "0123456789abcdef";

	if (digit < 0)
	{
		digit *= -1;
		write(1, "-", 1);
	}
	if (digit >= base)
		ft_putdigit ((digit/base), base, length);
	*length += write(1, &hex[digit % base], 1);
}

int	ft_printf (char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start (args, format);
	while (*format)
	{
		if ((*format == '%' && *(format + 1) == 'd') || (*format == '%' && *(format + 1) == 'x') 
			|| (*format == '%' && *(format + 1) == 's'))
		{
			format++;
			if (*format == 'd')
				ft_putdigit((long long int)va_arg(args, long), 10, &length);
			else if (*format == 'x')
				ft_putdigit((long long int)va_arg(args, long), 16, &length);
			else if (*format == 's')
				ft_putstring((char *)va_arg(args, char*), &length);
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	return (va_end(args), length);
}

int	main()
{
	char	*str = "Oxford";

	ft_printf ("%d is better than %s University!! it teach hex such as: 1337 is %x in hex\n", 1337, str, 1337);
	return (0);
}