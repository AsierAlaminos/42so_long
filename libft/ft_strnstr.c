/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:39:40 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/21 17:55:58 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)haystack;
	while (needle[j] != '\0')
		++j;
	if (j == 0)
		return (str);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] != '\0' && haystack[i + j] == needle[j]
			&& i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	needle[] = "dolor";
	int		n = 15;

	printf("ft_strnstr: %s\n", ft_strnstr(str, needle, n));
	printf("strnstr: %s\n", strnstr(str, needle, n));
	return (0);
}*/
