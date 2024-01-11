/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:15:28 by asmus37           #+#    #+#             */
/*   Updated: 2024/01/11 18:06:42 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	del_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*s)
		return (0);
	while (s[j] == c)
		++j;
	while (s[j] != '\0')
	{
		if (s[j] != c && s[j + 1] == c)
			++i;
		++j;
	}
	if (s[j - 1] != c)
		++i;
	return (i);
}

static int	str_count(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		++i;
		++len;
	}
	return (len);
}

static char	**liberar(char **arr, int arr_len)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static char	**add_str(char const *s, char **arr, int arr_len, char c)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	k = 0;
	while (i < arr_len && s[k] != '\0')
	{
		while (s[k] == c)
			++k;
		j = 0;
		len = str_count(s, c, k);
		arr[i] = (char *)malloc(len + 1);
		if (arr[i] == NULL)
			return (liberar(arr, i));
		while (j < len)
			arr[i][j++] = s[k++];
		arr[i][j] = '\0';
		++i;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		arr_len;
	char	**arr;

	arr_len = del_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (arr == NULL)
		return (NULL);
	return (add_str(s, arr, arr_len, c));
}
/*
int	main(void)
{
	char	str[] = "  tripouille  42  ";
	char	del = ' ';
	char	**splited;
	size_t		i;

	i = 0;
	splited = ft_split(str, del);
	while (splited[i] != NULL)
	{
		printf("%s", splited[i]);
		++i;
	}
	return (0);
}*/
