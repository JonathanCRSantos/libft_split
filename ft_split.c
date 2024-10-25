static int	ft_count_split(const char *str, char c)
{
	int	count;
	int	aux;

	aux = 0;
	count = 0;
	while (str[aux] != '\0')
	{
		if (str[aux] == c)
			aux++;
		count++;
		while (str[aux] != c && str[aux] != '\0')
			aux++;
	}
	return (count);
}

static char	**ft_fill(char **mtz, char const *str, char c)
{
	size_t	count;
	size_t	ccpy;
	size_t	len;
	int		aux;

	count = 0;
	aux = 0;
	len = ft_strlen(str);
	while (str[count])
	{
		while (str[count] == c && str[count] != '\0')
			count++;
		ccpy = count;
		while (str[count] != c && str[count] != '\0')
			count++;
		if (ccpy >= len)
			mtz[aux++] = "\0";
		else
			mtz[aux++] = ft_substr(str, ccpy, count - ccpy);
	}
	return (mtz);
}

char	**ft_split(char const *str, char c)
{
	char	**mtz;
	int		count;

	if (!str)
		return (NULL);
	count = ft_count_split(str, c);
	mtz = malloc((count + 1) * sizeof(char *));
	if (mtz == NULL)
		return (NULL);
	mtz = ft_fill(mtz, str, c);
	mtz[count] = NULL;
	return (mtz);
}
