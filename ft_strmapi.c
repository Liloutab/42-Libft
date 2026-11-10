/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltabbiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:42:00 by ltabbiz           #+#    #+#             */
/*   Updated: 2026/11/10 19:07:56 by ltabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	c = malloc(ft_strlen(s) + 1);
	if (!c)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
