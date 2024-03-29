/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:25:21 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/24 18:57:41 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(char *mensaje)
{
	if (mensaje == NULL)
		ft_printf("[*] GAME OVER\n");
	else
		ft_printf("%s\n", mensaje);
	exit(EXIT_SUCCESS);
	return (0);
}

void	create_images(t_vars *vars)
{
	t_img	images;
	t_data	img_size;
	int		img_width;
	int		img_height;

	images.img_floor = mlx_xpm_file_to_image(vars->mlx,
			"textures/floor.xpm", &img_width, &img_height);
	images.img_wall = mlx_xpm_file_to_image(vars->mlx,
			"textures/wall.xpm", &img_width, &img_height);
	images.img_gold = mlx_xpm_file_to_image(vars->mlx,
			"textures/gold.xpm", &img_width, &img_height);
	images.img_player = mlx_xpm_file_to_image(vars->mlx,
			"textures/player.xpm", &img_width, &img_height);
	images.img_exit = mlx_xpm_file_to_image(vars->mlx,
			"textures/door.xpm", &img_width, &img_width);
	vars->images = images;
	img_size.img_width = img_width;
	img_size.img_height = img_height;
	vars->img_size = img_size;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		close_window("Error\nArgumentos invalidos");
	vars.mlx = mlx_init();
	vars.squarex = 0;
	vars.squarey = 0;
	vars.player_moves = 0;
	vars.map_path = argv[1];
	read_map(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
