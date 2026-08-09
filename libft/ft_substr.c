
/*
** Allocates (with malloc(3)) and returns a substring from the string 's'.
** The substring begins at index 'start' and is of maximum size 'len'.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	tot_len;
	char	*sub;

	if (!s)
		return (NULL);
	tot_len = ft_strlen(s);
	if (start >= tot_len || len == 0)
		return (ft_strdup(""));
	if (len > tot_len - start)
		len = tot_len - start;
	i = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
