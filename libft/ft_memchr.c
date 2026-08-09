/* The memchr() function scans the initial n bytes of the memory area
** pointed to by s for the first instance of c.  Both c and the bytes
** of the memory area pointed to by s are interpreted as unsigned char. 
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
