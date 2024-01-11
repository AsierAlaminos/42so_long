/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:38:24 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/11 18:11:29by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_control(t_vars *vars)
{
	char	*save_pos;

	save_pos = ft_strdup("");
	if (node_comprobation(vars, vars->player_pos, 0, save_pos) == 'E')
		return (1);
	return (-1);
}

char	node_comprobation(t_vars *vars, int pos, int last_pos, char *save_pos)
{
	char	**splited_save;
	int		new_pos;

	//debug_map(vars, pos);
	splited_save = ft_split(save_pos, ':');
	ft_printf("splited: %s\n", splited_save[0]);
	if (splited_save[0] != NULL && ft_atoi(splited_save[0]) == vars->player_moves)
		return (vars->map[pos]);
	new_pos = save_comprobation(vars, pos, last_pos, save_pos);
	if ((vars->map[pos + 1] == '0' || vars->map[pos + 1] == 'C')
		&& pos + 1 != last_pos)
		{
			//ft_printf("1\n");
			new_pos = pos + 1;
		}
	else if ((vars->map[pos - vars->len_map - 1] == '0'
		|| vars->map[pos - vars->len_map - 1] == 'C')
		&& pos - vars->len_map - 1 != last_pos)
		{
			//ft_printf("2\n");
			new_pos = pos - vars->len_map - 1;
		}
	else if ((vars->map[pos - 1] == '0' || vars->map[pos - 1] == 'C')
		&& pos - 1 != last_pos)
		{
			//ft_printf("3\n");
			new_pos = pos - 1;
		}
	else if ((vars->map[pos + vars->len_map + 1] == '0'
		|| vars->map[pos + vars->len_map + 1] == 'C')
		&& pos + vars->len_map + 1 != last_pos)
		{
			//ft_printf("4\n");
			new_pos = pos + vars->len_map + 1;
		}
	else if (pos + 1 == last_pos || pos + vars->len_map + 1 == last_pos
		|| pos - 1 == last_pos || pos - vars->len_map - 1 == last_pos)
		{
			//ft_printf("5\n");
			return (dead_end(vars, pos, save_pos));
		}
	return (node_comprobation(vars, new_pos, pos, save_pos));
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

int	save_comprobation(t_vars *vars, int pos, int last_pos, char *save_pos)
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
	if (count >= 2 && rep == 0)
		save_pos = ft_strjoin(save_pos, ft_strjoin(ft_itoa(pos), ":"));
	return (0);
}

void	debug_map(t_vars *vars, int pos)
{
	int	i;

	i = 0;
	while (vars->map[i] != '\0')
	{
		if (i == pos)
			ft_printf("'");
		ft_printf("%c", vars->map[i]);
		i++;
	}
	ft_printf("\n");
}