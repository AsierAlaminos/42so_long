/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:38:24 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/10 19:52:30 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_control(t_vars *vars, int pos, int last_pos)
{
	if ((vars->map[pos + 1] == '0' || vars->map[pos + 1] == 'C')
		&& pos + 1 != last_pos)
		path_control(vars, pos + 1, pos);
	if ((vars->map[pos - vars->len_map - 1] == '0'
		|| vars->map[pos - vars->len_map - 1] == 'C')
		&& pos - vars->len_map - 1 != last_pos)
		path_control(vars, pos - vars->len_map - 1, pos);
	if ((vars->map[pos - 1] == '0' || vars->map[pos - 1] == 'C')
		&& pos - 1 != last_pos)
		path_control(vars, pos - 1, pos);
	if ((vars->map[pos + vars->len_map + 1] == '0'
		|| vars->map[pos + vars->len_map + 1] == 'C')
		&& pos + vars->len_map + 1 != last_pos)
		path_control(vars, pos + vars->len_map + 1, pos);
	return (dead_end(vars, pos));
}

int	dead_end(t_vars *vars, int pos)
{
	if (vars->map[pos + 1] == '0' || vars->map[pos + 1] == 'C')
		path_control(vars, pos + 1, pos);
	if (vars->map[pos - vars->len_map - 1] == '0'
		|| vars->map[pos - vars->len_map - 1] == 'C')
		path_control(vars, pos - vars->len_map - 1, pos);
	if (vars->map[pos - 1] == '0' || vars->map[pos - 1] == 'C')
		path_control(vars, pos - 1, pos);
	if (vars->map[pos + vars->len_map + 1] == '0'
		|| vars->map[pos + vars->len_map + 1] == 'C')
		path_control(vars, pos + vars->len_map + 1, pos);
	return (1);
}
