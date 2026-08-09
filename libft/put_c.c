#include "ft_printf.h"

int	put_c(int c)
{
	return (write(1, &c, 1));
}
