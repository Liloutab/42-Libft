/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltabbiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:28:42 by ltabbiz           #+#    #+#             */
/*   Updated: 2026/11/10 19:37:48 by ltabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			lens;
	size_t			taille;
	char			*x;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (lens <= start)
		taille = 0;
	if (len > lens - start)
		taille = lens - start;
	x = malloc(taille + 1);
	if (!x)
		return (0);
	i = 0;
	while (i < taille)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
