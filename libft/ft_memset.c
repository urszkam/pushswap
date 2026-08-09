/*
** The memset() function shall copy c (converted to an unsigned char)
** into each of the first n bytes of the object pointed to by s.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}
