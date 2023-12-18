/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:59:50 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/21 18:34:24 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	int		i;
	int		j;

	pointer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		pointer[i + j] = s2[j];
		++j;
	}
	pointer[i + j] = '\0';
	return (pointer);
}
/*
int	main(void)
{
	char	str[] = "hola buenas";
	char	str2[] = " como andamos";
	printf("ft_strjoin: %s", ft_strjoin(str, str2));
	return (0);
}*/
