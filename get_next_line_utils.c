/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:02:03 by aalamino          #+#    #+#             */
/*   Updated: 2023/11/26 17:55:43 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;
	char	*str;

	i = 0;
	character = (char) c;
	str = (char *) s;
	if (!s)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == character)
			return (&str[i]);
		++i;
	}
	if (str[i] == character)
		return (&str[ft_strlen(str)]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pointer;
	int		i;
	int		j;

	pointer = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!pointer)
		return (liberar(s1));
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
	free(s1);
	return (pointer);
}

char	*get_all_line(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	if (!str || str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	temp = (char *)malloc(i + 2);
	if (!temp)
		return (liberar(temp));
	j = 0;
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	if (str[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*reduce_str(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (liberar(str));
	if (str[0] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
		return (liberar(str));
	temp = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (str[i] != '\0')
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}
