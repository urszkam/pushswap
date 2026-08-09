
/*
** The memcpy() function copies n bytes from memory area src to
** memory area dest. The memory areas must not overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!dest && !src)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (n--)
		*(dest_ptr++) = *(src_ptr++);
	return (dest);
}