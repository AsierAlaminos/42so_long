/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:30:59 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/09 18:52:02 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement_control(int keycode, t_vars *vars)
{
	int		step;

	step = 20;
	if (keycode == 53)
	{
		ft_printf("\n[*] GAME OVER\n");
		close_window(vars);
	}
	if (keycode == 0)
		move_player(vars, -1);
	if (keycode == 1)
		move_player(vars, vars->len_map + 1);
	if (keycode == 2)
		move_player(vars, 1);
	if (keycode == 13)
		move_player(vars, (vars->len_map + 1) * -1);
	return (0);
}

void	move_player(t_vars *vars, int direction)
{
	int		i;

	i = 0;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P')
		{
			if (vars->map[i + direction] == '1')
				return ;
			vars->player_moves++;
			ft_printf("Movimientos: %d\n", vars->player_moves);
			env_control(vars, direction, i);
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

	if (vars->map[i + direction] == 'E' && vars->collectible == 0)
	{
		ft_printf("[*] NIVEL COMPLETADO!!!\n");
		close_window();
	}
	if (vars->map[i + direction] == 'C')
	{
		vars->collectible--;
		vars->map[i + direction] = vars->map[i];
		vars->map[i] = '0';
		return ;
	}
	temp = vars->map[i + direction];
	vars->map[i + direction] = vars->map[i];
	vars->map[i] = temp;
}
