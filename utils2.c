#include "push_swap.h"

int is_flag(char *s)
{
    return (!strncmp(s, "--", 2));
}

int equals(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]) == 0);
}