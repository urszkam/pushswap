/*
** The calloc() function allocates memory for an array of nmemb elements
** of size bytes each and returns a pointer to the allocated memory.
** The memory is set to zero. If nmemb or size is 0,
** then calloc() returns a unique pointer value
** that can later be successfully passed to free().
*/

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*dst;

	if (!nelem || !elsize)
		return (malloc(1));
	if (nelem > ((size_t)-1) / elsize)
		return (NULL);
	dst = (void *)malloc(elsize * nelem);
	if (!dst)
		return (NULL);
	ft_bzero(dst, nelem * elsize);
	return (dst);
}
