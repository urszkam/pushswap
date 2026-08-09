#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	put_c(int c);
int	put_p(void *ptr, int flags);
int	put_x(unsigned int n, int flags, char specifier);
int	put_n(long nb, int flags, char specifier);
int	put_s(char *s);

typedef enum e_bool
{
	false,
	true
}	t_bool;

#endif
