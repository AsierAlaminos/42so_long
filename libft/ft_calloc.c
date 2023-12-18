/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:09:41 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/15 19:34:03 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	else
		ft_bzero(pointer, count * size);
	return (pointer);
}
/*
int	main(void)
{
	int	i;
	int	*memory_space = (int *)calloc(10, sizeof(int));
	int	*memory_space2 = (int *)ft_calloc(10, sizeof(int));
	
	i = 0;
	printf("calloc: ");
	while (i < 10)
	{
		printf("%d ", memory_space[i]);
		++i;
	}
	i = 0;
	printf("ft_calloc: ");
	while (i < 10)
	{
		printf("%d ", memory_space2[i]);
		++i;
	}	
	return (0);
}*/
