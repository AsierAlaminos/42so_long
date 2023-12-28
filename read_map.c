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
	create_window(vars, vars->map);
	print_map(vars);
	mlx_key_hook(vars->win, movement_control, vars);
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
	printf("i: %d / j: %d / count_nl: %d\n", i, j, count_nl);
}

void	put_floor(t_vars *vars, int len, int max, int layer)
{
	int		img_width;
	int		img_height;
	void	*img_floor;
	void	*img_wall;
	int		i;

	printf("len: %d / max: %d\n", len, max);
	i = 0;
	while (i < max - len)
	{
		printf("%c", vars->map[i + len]);
		if (vars->map[i + len] == '0')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_floor, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		if (vars->map[i + len] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_wall, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		if (vars->map[i + len] == 'P')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_player, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);
		/*if (vars->map[i + len] == 'C')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images.img_gold, vars->squarex + vars->img_size.img_width * i, vars->squarey + vars->img_size.img_height * layer);*/
		++i;
	}
}

void	create_window(t_vars *vars, char *map)
{
	int	i;
	int	j;
	int	count_nl;

	i = 0;
	j = 0;
	count_nl = 0;
	while (map[i] != '\n')
		++i;
	while (map[j] != '\0')
	{
		if (map[j] == '\n')
			++count_nl;
		++j;
	}
	++count_nl;
	printf("count_nl: %d\n", count_nl);
	vars->win = mlx_new_window(vars->mlx, vars->img_size.img_width * i, vars->img_size.img_height * count_nl, "so_long");
	vars->len_map = i;
	vars->layers_map = count_nl;
}
