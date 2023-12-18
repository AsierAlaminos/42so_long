/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:27:39 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/18 19:51:38 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	t_vars
{
	void	*mlx;
	void	*win;
	int		squarex;
	int		squarey;
}	t_vars;

int		movement_control(int keycode, t_vars *vars);
int 	close_window(t_vars *vars);
int		create_square(t_vars vars, t_data img);
void	read_map(char *map_path, t_vars *vars);
void	print_map(t_vars *vars, char *map);
void	put_floor(t_vars *vars, int x, int y);

#endif