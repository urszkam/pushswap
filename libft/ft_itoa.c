#include "libft.h"

static size_t	calc_str_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*s;

	len = calc_str_len(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	nb = n;
	if (nb < 0)
		nb = -nb;
	if (!nb)
		s[0] = '0';
	s[len] = 0;
	while (len--)
	{
		s[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
