/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:30:59 by aalamino          #+#    #+#             */
/*   Updated: 2023/12/16 16:05:19 by aalamino         ###   ########.fr       */
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
		printf("A pressed\n");
		//vars->squarex -= step;
	if (keycode == 1)
		printf("S pressed\n");
		//vars->squarey += step;
	if (keycode == 2)
		printf("D pressed\n");
		//vars->squarex += step;
	if (keycode == 13)
		printf("W pressed\n");
		//vars->squarey -= step;
	mlx_clear_window(vars->mlx, vars->win);
	//create_square(*vars, img);
	return (0);
}