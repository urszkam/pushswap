#include "ft_printf.h"

static t_bool	has_flags_and_specifiers(const char **format)
{
	char	*specifier;

	specifier = "cspdiuxX%";
	while (**format == '#' || **format == ' ' || **format == '+')
		(*format)++;
	while (*specifier && *specifier != **format)
		specifier++;
	return (*specifier == **format);
}

static t_bool	validate_format(const char *format)
{
	while (*format)
	{
		if (*format == '%')
			if (!*(++format)
				|| !has_flags_and_specifiers(&format))
				return (false);
		format++;
	}
	return (true);
}

static int	extract_flags(const char **format)
{
	int	flags;

	flags = 0;
	while (**format == '#' || **format == ' ' || **format == '+')
	{
		if (**format == ' ')
			flags |= 1;
		else if (**format == '+')
			flags |= (1 << 1);
		else if (**format == '#')
			flags |= (1 << 2);
		(*format)++;
	}
	return (flags);
}

static int	convert(const char specifier, int flags, va_list *args)
{
	if (specifier == 'c')
		return (put_c((unsigned char)va_arg(*args, int)));
	else if (specifier == 's')
		return (put_s(va_arg(*args, char *)));
	else if (specifier == 'u')
		return (put_n(va_arg(*args, unsigned int), flags, specifier));
	else if (specifier == 'x' || specifier == 'X')
		return (put_x(va_arg(*args, unsigned int), flags, specifier));
	else if (specifier == 'p')
		return (put_p(va_arg(*args, void *), flags));
	else if (specifier == 'd' || specifier == 'i')
		return (put_n(va_arg(*args, int), flags, specifier));
	else
		return (put_c(specifier));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		flags;

	if (!validate_format(format))
		return (-1);
	va_start(args, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = extract_flags(&format);
			counter += convert(*format, flags, &args);
		}
		else
			counter += put_c(*format);
		format++;
	}
	va_end(args);
	return (counter);
}
