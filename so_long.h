/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:27:39 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/08 19:24:06 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_data{
	int	img_width;
	int	img_height;
}	t_data;

typedef struct	t_img
{
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_gold;
}	t_img;

typedef struct	t_vars
{
	void	*mlx;
	void	*win;
	int		squarex;
	int		squarey;
	t_img	images;
	t_data	img_size;
	char	*map;
	int		len_map;
	int		layers_map;
	char	*map_path;
	int		player_collect;
	int		player_moves;
}	t_vars;

int		movement_control(int keycode, t_vars *vars);
int 	close_window(t_vars *vars);
int		create_square(t_vars vars, t_data img);
void	read_map(t_vars *vars);
void	print_map(t_vars *vars);
void	put_floor(t_vars *vars, int len, int max, int layer);
void	create_window(t_vars *vars, char *map);
void	create_images(t_vars *vars);
void	move_player(t_vars *vars, int direction);
void	count_map(t_vars *vars);
int		map_comprobation(t_vars *vars);
int		wall_comprobation(t_vars *vars);
int		especial_comprobation(t_vars *vars);
int	form_comprobation(t_vars *vars);

#endif