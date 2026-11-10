/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltabbiz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:29:07 by ltabbiz           #+#    #+#             */
/*   Updated: 2026/11/09 23:20:19 by ltabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lens;
	size_t	lend;
	size_t	i;
	size_t	j;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	j = 0;
	if (size <= lend)
		return (size + lens);
	while (lend < size && dst[i])
		i++;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lend + lens);
}
