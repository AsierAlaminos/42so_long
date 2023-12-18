/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:55:47 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/22 16:30:56 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	int		len;
	int		i;

	len = ft_strlen(s);
	pointer = (char *)malloc(len + 1);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		pointer[i] = (char)f(i, s[i]);
		++i;
	}
	pointer[i] = '\0';
	return (pointer);
}
