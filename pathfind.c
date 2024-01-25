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
#include <stdlib.h>

//IMPORTANTE
//FLOOD_FILL

int	flood_fill(t_vars *vars, int pos)
{
	if (vars->map_copy[pos] == '1' || vars->map_copy == 'X')
		return ;
	if (vars->map_copy[pos] == 'C')
		vars->collec_copy++;
	vars->map_copy[pos] = 'X';
	flood_fill(vars, pos + 1);
	flood_fill(vars, pos - 1);
	flood_fill(vars,  pos + vars->len_map);
	flood_fill(vars, pos - vars->len_map);
	return (-1);
}

void	find_next(t_vars *vars, int pos)
{
	if (vars->map_copy[pos] == '0')
	{
		vars->map_copy[pos] = 'X';
		vars->path = 1;
	}
}

void	replace_player(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_copy[i] != '\0')
	{
		if (vars->map_copy[i] == 'P')
		{
			vars->map_copy[i] = 'X';
			return ;
		}
		i++;
	}
}

