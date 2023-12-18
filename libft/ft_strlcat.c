/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:05 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/21 17:20:11 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstlen)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (lendst >= dstlen)
		return (dstlen + lensrc);
	j = lendst;
	i = 0;
	while (src[i] != '\0' && i + j < (dstlen - 1))
	{
		dst[j + i] = src[i];
		++i;
	}
	dst[i + j] = '\0';
	return (lendst + lensrc);
}
/*
int	main(void)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	ft_memset(dest, 0, 15);
	ft_memset(dest, 'r', 6);
	dest[14] = 'a';
	printf("Antes: %s\n", dest);
	printf("size_t: %zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	printf("Despues: %s\n", dest);
	return (0);
}*/
