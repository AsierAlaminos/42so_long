/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:50:01 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/21 17:48:11 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && num == 0)
	{
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
		++i;
	}
	if (i < n && num == 0)
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (num);
}
/*
int main(void)
{
	char	str1[] = "test\200";
	char	str2[] = "test\0";
	int		n = 6;
	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, n));
	printf("strncmp: %d\n", strncmp(str1, str2, n));
	return (0);
}*/
