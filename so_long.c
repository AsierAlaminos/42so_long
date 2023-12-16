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
	void	*img_player;
	void	*img_duplicate;
	int		img_width;
	int		img_height;
	int		i;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "hello world");
	vars.squarex = 5;
	vars.squarey = 5;
	//create_square(vars, img);
	mlx_hook(vars.win, 2, 1L<<0, movement_control, &vars);
	i = 0;
	while (i < 30)
	{
		img_player = mlx_xpm_file_to_image(vars.mlx, "textures/floor.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars.mlx, vars.win, img_player, vars.squarex + img_width, vars.squarey);
		vars.squarex += img_width;
		++i;
	}
	mlx_loop(vars.mlx);
	return (0);
}
