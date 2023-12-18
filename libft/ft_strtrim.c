/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:14:47 by asmus37           #+#    #+#             */
/*   Updated: 2023/03/16 15:33:22 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	string_detect(char const *str, char character)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == character)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*pointer;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (string_detect(set, s1[i]) && s1[i] != '\0')
		++i;
	while (string_detect(set, s1[j - 1]) && (j - 1) > 0)
		--j;
	if (j < i)
		j = i;
	pointer = malloc(j - i + 1);
	if (pointer == NULL)
		return (NULL);
	while (i < j)
		pointer[k++] = s1[i++];
	pointer[k] = '\0';
	return (pointer);
}
/*
int	main(void)
{
	char	str[] = "hola buenas que tal andamos";
	char	set[] = "aob";
	printf("ft_strtrim: %s\n",ft_strtrim(str, set));
	return (0);
}*/
