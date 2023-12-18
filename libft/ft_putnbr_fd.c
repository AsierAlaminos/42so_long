/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:33:58 by aalamino          #+#    #+#             */
/*   Updated: 2023/03/20 14:01:14 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483647 - 1)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			ft_putnbr_fd(n * -1, fd);
		}
		if (n >= 0 && n <= 9)
		{
			num = n + '0';
			write(fd, &num, 1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
