/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltabbiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:38:58 by ltabbiz           #+#    #+#             */
/*   Updated: 2026/11/10 18:24:50 by ltabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count += 1;
		i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*free_all(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	k;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	k = 0;
	while (k < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		len = word_len(&s[i], c);
		tab[k] = ft_substr(s, i, len);
		if (!tab[k])
			return (free_all(tab, k), NULL);
		i += len;
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
