/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:03:21 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/11 19:20:40 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_comprobation(t_vars *vars)
{
	int	valor;

	valor = 1;
	valor *= wall_comprobation(vars);
	valor *= especial_comprobation(vars);
	valor *= form_comprobation(vars);
	//valor *= path_control(vars);
	ft_printf("valor: %d\n", path_control(vars));
	if (valor == -1)
		close_window("Error");
}

int	wall_comprobation(t_vars *vars)
{
	int	i;
	int	len;

	i = 0;
	while (i < vars->len_map - 1)
	{
		if (vars->map[i++] != '1')
			return (-1);
	}
	i = 1;
	len = vars->len_map + 1;
	while (i < vars->layers_map - 1)
	{
		if (vars->map[len] != '1' || vars->map[len + vars->len_map - 1] != '1')
			return (-1);
		++i;
		len += vars->len_map + 1;
	}
	i = len;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i++] != '1')
			return (-1);
	}
	return (1);
}

int	especial_comprobation(t_vars *vars)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	vars->collectible = 0;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P')
			p++;
		if (vars->map[i] == 'E')
			e++;
		if (vars->map[i] == 'C')
			vars->collectible++;
		++i;
	}
	if (p != 1 && e != 1 && vars->collectible < 1)
		return (-1);
	return (1);
}

int	form_comprobation(t_vars *vars)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < vars->layers_map)
	{
		len = 0;
		while (vars->map[len + j] != '\n' && vars->map[len + j] != '\0')
			++len;
		if (len != vars->len_map)
			return (-1);
		++i;
		len++;
		j += len;
	}
	return (1);
}
