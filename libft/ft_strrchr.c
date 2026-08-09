#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = ft_strlen(s);
	while (idx > 0 && s[idx] != c)
		idx--;
	if (s[idx] == c)
		return ((char *)s + idx);
	return (0);
}
