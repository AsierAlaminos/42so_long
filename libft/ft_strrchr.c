/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:41:46 by aalamino          #+#    #+#             */
/*   Updated: 2023/04/20 11:17:24 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		lp;
	char	character;
	char	*str;

	i = 0;
	lp = -1;
	character = (char) c;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == character)
			lp = i;
		++i;
	}
	if (lp != -1)
		return (&str[lp]);
	if (str[i] == character)
		return (&str[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "bonjour";

	printf("ft_strchr: %s\n", ft_strrchr(str, '\0'));
	printf("strchr: %s\n", strrchr(str, '\0'));
	return (0);
}*/
