/*
The strnstr() function locates the first 
occurrence of the  null-termi-nated  string little in the string big, 
where not more than len characters are searched. Characters that appear 
after a `\0' character  are not  searched. 

If little is an empty string, big is returned; if little	occurs nowhere
in big, NULL is returned; otherwise a pointer to the first character of
the first occurrence of little is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	i = 0;
	if (little && !*little)
		return ((char *)big);
	l_len = ft_strlen(little);
	while (i + l_len <= len && big[i])
	{
		if (!ft_strncmp(big + i, little, l_len))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
