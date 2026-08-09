#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (i > 0 && s[i - 1] == c && s[i] != c))
			counter++;
		i++;
	}
	return (counter);
}

static void	ft_free(char **arr, size_t idx)
{
	while (idx--)
		free(arr[idx]);
	free(arr);
}

static char	**create_arr(char const *s, char c, size_t arr_len, char **arr)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (i < arr_len)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		arr[i] = ft_substr(s, 0, word_len);
        if (!arr[i])
        {
            ft_free(arr, i);
            return (NULL);
        }
        s += word_len;
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	arr_len;
	char	**arr;

	if (!s)
		return (NULL);
	arr_len = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!arr)
		return (NULL);
	return (create_arr(s, c, arr_len, arr));
}
