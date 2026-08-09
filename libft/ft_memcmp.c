/* The memcmp() function compares the first n bytes (each interpreted
** as unsigned char) of the memory areas s1 and s2.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	ptrs1 = s1;
	ptrs2 = s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && ptrs1[i] == ptrs2[i])
		i++;
	return (ptrs1[i] - ptrs2[i]);
}
