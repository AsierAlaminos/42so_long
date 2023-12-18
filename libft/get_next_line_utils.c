/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:02:03 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/18 19:12:22 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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
		return (free_pointer(temp));
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
		return (free_pointer(str));
	if (str[0] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
		return (free_pointer(str));
	temp = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (str[i] != '\0')
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}
