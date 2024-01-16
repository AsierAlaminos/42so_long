/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:38:24 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/16 14:39:32 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	path_control(t_vars *vars)
{
	char	*save_pos;
	int		new_pos;
	int		last_pos;

	save_pos = malloc(sizeof(char));
	last_pos = vars->player_pos;
	new_pos = node_comprobation(vars, vars->player_pos, last_pos, save_pos);
	while (vars->map[new_pos] != 'E')
	{
		new_pos = node_comprobation(vars, new_pos, last_pos, save_pos);
		last_pos = vars->player_pos + (new_pos - vars->player_pos);
		save_comprobation(vars, new_pos, last_pos, save_pos);
		if (ft_strlen(save_pos) == 0)
			return (-1);
	}
	return (1);
}

char	node_comprobation(t_vars *vars, int pos, int last_pos, char *save_pos)
{
	char	**splited_save;

	splited_save = ft_split(save_pos, ':');
	if (splited_save[0] != NULL && ft_atoi(splited_save[0]) == vars->player_moves)
		return (vars->map[pos]);
	if ((vars->map[pos + 1] == '0' || vars->map[pos + 1] == 'C')
		&& pos + 1 != last_pos)
			return (pos + 1);
	if ((vars->map[pos - vars->len_map - 1] == '0'
		|| vars->map[pos - vars->len_map - 1] == 'C')
		&& pos - vars->len_map - 1 != last_pos)
			return (pos - vars->len_map - 1);
	if ((vars->map[pos - 1] == '0' || vars->map[pos - 1] == 'C')
		&& pos - 1 != last_pos)
			return (pos - 1);
	if ((vars->map[pos + vars->len_map + 1] == '0'
		|| vars->map[pos + vars->len_map + 1] == 'C')
		&& pos + vars->len_map + 1 != last_pos)
			return (pos + vars->len_map + 1);
	else
			return (dead_end(vars, pos, save_pos));
}

char	dead_end(t_vars *vars, int pos, char *save_pos)
{
	int	new_pos;

	if (vars->map[pos + 1] == '0' || vars->map[pos + 1] == 'C')
		new_pos = pos + 1;
	if (vars->map[pos - vars->len_map - 1] == '0'
		|| vars->map[pos - vars->len_map - 1] == 'C')
		new_pos = pos - vars->len_map - 1;
	if (vars->map[pos - 1] == '0' || vars->map[pos - 1] == 'C')
		new_pos = pos - 1;
	if (vars->map[pos + vars->len_map + 1] == '0'
		|| vars->map[pos + vars->len_map + 1] == 'C')
		new_pos = pos + vars->len_map + 1;
	return (node_comprobation(vars, new_pos, pos, save_pos));
}

char	*save_comprobation(t_vars *vars, int pos, int last_pos, char *save_pos)
{
	int		count;
	int		rep;
	char	**splited;
	int		i;

	count = 0;
	rep = 0;
	i = 0;
	if (vars->map[pos + 1] == '0')
		count++;
	if (vars->map[pos - vars->len_map - 1] == '0')
		count++;
	if (vars->map[pos - 1] == '0')
		count++;
	if (vars->map[pos + vars->len_map + 1] == '0')
		count++;
	splited = ft_split(save_pos, ':');
	while (splited[i] != NULL)
	{
		if (ft_atoi(splited[i++]) == last_pos)
			rep++;
	}
	ft_printf("join: %s\n", ft_strjoin(ft_substr(save_pos, 0, ft_strlen(save_pos)), ft_strjoin(ft_itoa(pos), ":")));
	if (count >= 2 && rep == 0)
		return (ft_strjoin(ft_itoa(pos), ":"));
	return (ft_strdup(""));
}

void	debug_map(t_vars *vars, int pos)
{
	int	i;

	i = 0;
	while (vars->map[i] != '\0')
	{
		if (i == pos)
			ft_printf("'%c'", vars->map[i]);
		else
			ft_printf("%c", vars->map[i]);
		i++;
	}
	ft_printf("\n");
}
