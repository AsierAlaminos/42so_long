/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:43:53 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/11 11:04:13 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	a = b;
	while (i < len)
	{
		a[i] = c;
		++i;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[] = "hola buenas tardes como andamos";
	printf("Antes: %s", str);
	memset();
	return (0);
}*/