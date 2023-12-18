/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:25:45 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/18 19:54:00 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map_path, t_vars *vars)
{
	int		fd;
	char	*readed;
	char	*line;

	fd = open(map_path, O_RDWR);
	readed = (char *)malloc(sizeof(char));
	line = get_next_line(fd);
	while (line != NULL)
	{
		readed = ft_strjoin(readed, line);
		line = get_next_line(fd);
	}
	print_map(vars, readed);
}

void	print_map(t_vars *vars, char *map)
{
	int		i;
	int		j;
	int		count_nl;
	char	**lineas;

	i = 0;
	while (map[i] != '\n' && map[i] != '\0')
		i++;
	j = 0;
	count_nl = 0;
	while (map[j] != '\0')
	{
		if (map[j] == '\n')
			count_nl++;
		j++;
	}
	put_floor(vars, i, count_nl);
}

void	put_floor(t_vars *vars, int x, int y)
{
	int		img_width_floor;
	int		img_height_floor;
	void	*img_floor;
	int		i;
	int		j;
	
	//img_player = mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm", &img_width_player, &img_height_player);
	img_floor = mlx_xpm_file_to_image(vars->mlx, "textures/floor.xpm", &img_width_floor, &img_height_floor);
	vars->win = mlx_new_window(vars->mlx, img_width_floor * x, img_height_floor * y, "hello world");
	
	//mlx_put_image_to_window(vars->mlx, vars->win, img_player, vars->squarex, vars->squarey);
	mlx_hook(vars->win, 2, 1L<<0, movement_control, &vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img_floor, vars->squarex, vars->squarey);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x - 1)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img_floor, vars->squarex + img_width_floor, vars->squarey + img_height_floor * i);
			vars->squarex += img_width_floor;
			++j;
		}
		i++;
		vars->squarex = 0;
		mlx_put_image_to_window(vars->mlx, vars->win, img_floor, vars->squarex, vars->squarey + img_height_floor * i);
	}
}