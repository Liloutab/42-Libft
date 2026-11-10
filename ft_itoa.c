/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltabbiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:00:36 by ltabbiz           #+#    #+#             */
/*   Updated: 2026/11/10 00:26:04 by ltabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(long nb)
{
	if (nb < 0)
		return (1 + count(-nb));
	if (nb / 10 == 0)
		return (1);
	return (1 + count(nb / 10));
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nb;
	size_t	len;

	nb = n;
	len = count(nb);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (nb < 0)
	{
		c[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		c[0] = '0';
	while (nb > 0)
	{
		len--;
		c[len] = '0' + nb % 10;
		nb /= 10;
	}
	return (c);
}
