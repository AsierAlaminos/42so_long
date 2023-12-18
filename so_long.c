/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:25:21 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/16 15:02:10by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(t_vars *vars)
{
	printf("[*] Exit\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	resize_window(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	return (0);
}

int	create_square(t_vars vars, t_data img)
{
	int		x;
	int		y;
	int		red;

	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = vars.squarex;
	y = vars.squarey;
	red = 0x00FF0000;
	printf("x: %d - y: %d\n", vars.squarex, vars.squarey);
	while (x <= vars.squarex + 100)
	{
		my_mlx_pixel_put(&img, x, y, red);
		x++;
	}
	while (y <= vars.squarey + 100)
	{
		my_mlx_pixel_put(&img, x, y, red);
		y++;
	}
	while (x >= vars.squarex)
	{
		my_mlx_pixel_put(&img, x, y, red);
		x--;
	}
	while (y >= vars.squarey)
	{
		my_mlx_pixel_put(&img, x, y, red);
		y--;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	return (0);
}

int main(void)
{
	t_vars	vars;
	t_data	img;
	void	*img_floor;
	void	*img_duplicate;
	int		i;
	char	*mapa;

	vars.mlx = mlx_init();
	vars.squarex = 0;
	vars.squarey = 0;
	//create_square(vars, img);
	mapa = "maps/map_one.ber";
	read_map(mapa, &vars);
	
	mlx_loop(vars.mlx);
	return (0);
}
