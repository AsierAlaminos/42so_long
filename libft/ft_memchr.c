/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:01:18 by aalamino          #+#    #+#             */
/*   Updated: 2023/04/20 10:55:47 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		++i;
	}
	return (NULL);
}
/*
int	main(void)
{
	int	str1[] = {0, 1, 2, 3, 4, 5};
	//int		c = 2 + 256;
	//int		n = 3;
	printf("ft_memchr: %s\n", ft_memchr(str1, 2 + 256, 3));
	printf("memchr: %s\n", memchr(str1, 2 + 256, 3));
	return (0);
}*/
