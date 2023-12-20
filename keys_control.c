/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:30:59 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/20 20:07:20 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_control(int keycode, t_vars *vars)
{
	int		step;
	t_data	img;

	step = 20;
	if (keycode == 53)
		close_window(vars);
	if (keycode == 0)
	{
		printf("A pressed\n");
		move_player(vars, -1);
	}
	if (keycode == 1)
	{
		printf("S pressed\n");
		move_player(vars, vars->len_map + 1);
	}
	if (keycode == 2)
	{
		printf("D pressed\n");
		move_player(vars, 1);
	}
	if (keycode == 13)
	{
		printf("W pressed\n");
		move_player(vars, (vars->len_map + 1) * -1);
	}
	return (0);
}

void	move_player(t_vars *vars, int direction)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	printf("direction: %d\n", direction);
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P')
		{
			printf("i: %d / dir: %d\nplayer: %c / dir: %c\n", i, i + direction, vars->map[i], vars->map[i + direction]);
			temp = vars->map[i + direction];
			vars->map[i + direction] = vars->map[i];
			vars->map[i] = temp;
			break;
		}
		++i;
	}
	mlx_clear_window(vars->mlx, vars->win);
	print_map(vars);
}