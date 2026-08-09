#include "ft_printf.h"

int	put_s(char *s)
{
	int	len;

	if (!s)
		return (put_s("(null)"));
	len = 0;
	while (*s)
		len += put_c(*(s++));
	return (len);
}
