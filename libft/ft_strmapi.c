#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*d;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (!d)
		return (NULL);
	d[len] = 0;
	while (len--)
		d[len] = f(len, s[len]);
	return (d);
}
