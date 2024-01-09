/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:25:45 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/28 17:18:14y aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_vars *vars)
{
	int		fd;
	char	*readed;
	char	*line;

	fd = open(vars->map_path, O_RDWR);
	readed = (char *)malloc(sizeof(char));
	line = get_next_line(fd);
	while (line != NULL)
	{
		readed = ft_strjoin(readed, line);
		line = get_next_line(fd);
	}
	vars->map = readed;
	create_images(vars);
	count_map(vars);
	map_comprobation(vars);
	vars->win = mlx_new_window(vars->mlx, vars->img_size.img_width * vars->len_map, vars->img_size.img_height * vars->layers_map, "so_long");
	print_map(vars);
	mlx_key_hook(vars->win, movement_control, vars);
	mlx_hook(vars->win, 17, 0, close_window, NULL);
}

void	print_map(t_vars *vars)
{
	int		i;
	int		j;
	int		count_nl;
	int		len_map;

	i = 0;
	j = 0;
	count_nl = 0;
	len_map = ft_strlen(&vars->map[j]);
	while (j < len_map + 1)
	{
		if (vars->map[j] == '\n' || vars->map[j] == '\0')
		{
			put_floor(vars, i, j, count_nl);
			i = j + 1;
			++count_nl;
		}
		j++;
	}
}

void	put_floor(t_vars *vars, int len, int max, int layer)
{
	int		i;

	i = 0;
	while (i < max - len)
	{
		if (vars->map[i + len] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_floor, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		if (vars->map[i + len] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_wall, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		if (vars->map[i + len] == 'P')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_player, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		if (vars->map[i + len] == 'C')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_gold, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		++i;
	}
}

void	count_map(t_vars *vars)
{
	int	i;

	i = 0;
	vars->len_map = 0;
	vars->layers_map = 0;
	while (vars->map[vars->len_map] != '\n')
		vars->len_map++;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == '\n')
			vars->layers_map++;
		++i;
	}
	vars->layers_map++;
}
