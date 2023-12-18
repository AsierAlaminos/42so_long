/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:21:18 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/15 19:39:24 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		i;

	pointer = (char *)malloc(ft_strlen(s1) + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		++i;
	}
	pointer[i] = '\0';
	return (pointer);
}
/*
int	main(void)
{
	char	str[] = "hola buenas como andamos";

	printf("ft_strdup: %s", ft_strdup(str));
	printf("strdup: %s", strdup(str));
	return (0);
}*/
