/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltabbiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:23:01 by ltabbiz           #+#    #+#             */
/*   Updated: 2026/11/09 17:23:30 by ltabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*x;
	size_t	i;

	i = 0;
	x = malloc(ft_strlen(s) + 1);
	if (!x)
		return (NULL);
	while (i < ft_strlen(s))
	{
		x[i] = s[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
