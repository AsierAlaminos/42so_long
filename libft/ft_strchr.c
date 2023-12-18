/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:05:30 by aalamino          #+#    #+#             */
/*   Updated: 2023/04/20 10:44:53 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;
	char	*str;

	i = 0;
	character = (char) c;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == character)
			return (&str[i]);
		++i;
	}
	if (str[i] == character)
		return (&str[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "teste";
	//char	c = 'w';
	int		ch = 1024;
	printf("ft_strchr: %s\n", ft_strchr(str, ch));
	printf("strchr: %s\n", strchr(str, ch));
	return (0);
}*/
