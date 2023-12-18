/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:09:09 by aalamino          #+#    #+#             */
/*   Updated: 2023/05/18 15:35:02 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	if (dstlen <= 0)
	{
		i = 0;
		while (src[i])
			++i;
		return (i);
	}
	i = 0;
	while (src[i] && i < (dstlen - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		++i;
	return (i);
}
