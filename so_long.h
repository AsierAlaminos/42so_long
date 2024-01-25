/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:27:39 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/24 18:57:44 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data{
	int	img_width;
	int	img_height;
}	t_data;

typedef struct t_img
{
	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_gold;
	void	*img_exit;
}	t_img;

typedef struct t_vars
{
	void	*mlx;
	void	*win;
	int		squarex;
	int		squarey;
	t_img	images;
	t_data	img_size;
	char	*map;
	char	*map_copy;
	int		len_map;
	int		layers_map;
	char	*map_path;
	int		collectible;
	int		collec_copy;
	int		player_moves;
	int		player_pos;
	int		path;
	int		exit;
}	t_vars;

int		movement_control(int keycode, t_vars *vars);
int		close_window(char *mensaje);
int		create_square(t_vars vars, t_data img);
void	read_map(t_vars *vars);
void	put_images(t_vars *vars, int len, int max, int layer);
void	print_map(t_vars *vars);
void	create_window(t_vars *vars, char *map);
void	create_images(t_vars *vars);
void	move_player(t_vars *vars, int direction);
void	count_map(t_vars *vars);
void	map_comprobation(t_vars *vars);
int		wall_comprobation(t_vars *vars);
int		especial_comprobation(t_vars *vars);
int		form_comprobation(t_vars *vars);
void	env_control(t_vars *vars, int direction, int i);
int		path_control(t_vars *vars);
void	put_player_col(t_vars *vars, char pos, int layer, int i);
void	map_comprobation(t_vars *vars);
int		char_comprobation(t_vars *vars);
void	flood_fill(t_vars *vars, int pos);
void	replace_player(t_vars *vars);
void	copy_map(t_vars *vars);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*reader(char *str, int fd);
char	*get_all_line(char *str);
char	*reduce_str(char *str);
char	*free_pointer(char *pointer);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*liberar(char *pointer);

int		ft_printf(char const *str, ...);
int		ft_flags(char f, va_list args);
int		ft_long_flags(char f, va_list args);
int		putnbr(int num);
int		putnbrulong(unsigned int num);
int		print_hex(char *num, int size_num);
int		putnbrhex(unsigned int num, char c);
int		putnbrlonghex(void *num, char *hex_chars);
int		ft_putchar(int c);
int		ft_print_str(char *str);
int		nhexlen(unsigned long long num);

#endif
