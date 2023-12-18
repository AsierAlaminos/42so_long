/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:44:19 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/21 19:37:46 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	int_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*pointer;
	int		len;
	int		neg;

	len = int_len(n);
	neg = 1;
	if (n < 0)
	{
		++len;
		neg = -1;
	}
	pointer = (char *)malloc(len + 1);
	if (pointer == NULL)
		return (NULL);
	pointer[len] = '\0';
	while (len > 0)
	{
		pointer[len - 1] = n % 10 * neg + '0';
		n = n / 10;
		--len;
	}
	if (neg == -1)
		pointer[0] = '-';
	return (pointer);
}
/*
int	main(void)
{
	int	n = -9;
	printf("ft_itoa: %s\n", ft_itoa(n));
	return (0);
}*/
