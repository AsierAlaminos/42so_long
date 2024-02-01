/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:38:24 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/24 18:54:31 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_vars *vars, int pos)
{
	if (pos != vars->player_pos
		&& (vars->map_copy[pos] == '1' || vars->map_copy[pos] == 'X'
			|| vars->exit == 1))
		return ;
	if (vars->map_copy[pos] == 'C')
		vars->collec_copy++;
	if (vars->map_copy[pos] == 'E' && vars->collec_copy == vars->collectible)
	{
		vars->exit = 1;
		return ;
	}
	vars->map_copy[pos] = 'X';
	flood_fill(vars, pos + 1);
	flood_fill(vars, pos - 1);
	flood_fill(vars, pos + (vars->len_map + 1));
	flood_fill(vars, pos - (vars->len_map + 1));
	return ;
}

void	copy_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != '\0')
		i++;
	vars->map_copy = (char *)(malloc(sizeof(char *) * i));
	i = 0;
	while (vars->map[i] != '\0')
	{
		vars->map_copy[i] = vars->map[i];
		i++;
	}
}
