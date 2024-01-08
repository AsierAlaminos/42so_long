/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:30:59 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/08 17:57:18 by aalamino         ###   ########.fr       */
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
		printf("\nA pressed\n");
		move_player(vars, -1);
	}
	if (keycode == 1)
	{
		printf("\nS pressed\n");
		move_player(vars, vars->len_map + 1);
	}
	if (keycode == 2)
	{
		printf("\nD pressed\n");
		move_player(vars, 1);
	}
	if (keycode == 13)
	{
		printf("\nW pressed\n");
		move_player(vars, (vars->len_map + 1) * -1);
	}
	vars->player_moves++;
	ft_printf("Movimientos: %d\n", vars->player_moves);
	return (0);
}

void	move_player(t_vars *vars, int direction)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P')
		{
			if (vars->map[i + direction] == '1')
				return ;
			temp = vars->map[i];
			vars->map[i] = vars->map[i + direction];
			vars->map[i + direction] = temp;
			break;
		}
		++i;
	}
	mlx_clear_window(vars->mlx, vars->win);
	print_map(vars);
}

void	env_control(t_vars *vars, int direction, int i)
{
	char	temp;

	temp = vars->map[i + direction];
	vars->map[i + direction] = vars->map[i];
	vars->map[i] = temp;
	
}