/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:25:21 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/16 13:19:23 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	my_mlx_pixel_put(&img, 5, 5 + i, 0x00FF0000);
	while (i > -6){
		my_mlx_pixel_put(&img, 5, 5 + i, 0x00FF0000);
		printf("y-");
		i--;
	}
	i = 0;
	while (i < 6){
		my_mlx_pixel_put(&img, 5 + i, 5, 0x00FF0000);
		printf("x+");
		i++;
	}
	i = 0;
	while (i < 6){
		my_mlx_pixel_put(&img, 5, 5 + i, 0x00FF0000);
		printf("y+");
		i++;
	}
	i = 0;
	while (i > -6){
		my_mlx_pixel_put(&img, 5 + 1, 5, 0x00FF0000);
		printf("x-");
		i--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
