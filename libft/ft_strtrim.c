/*
** Allocates (with malloc(3)) and returns a copy of s1 with the characters
** specified in 'set' removed from the beginning and the end of the string
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	end = 0;
	while (len > end && ft_strchr(set, s1[len - end - 1]))
		end++;
	return (ft_substr(s1, 0, len - end));
}
