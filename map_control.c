/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:03:21 by aalamino          #+#    #+#             */
/*   Updated: 2024/01/08 19:26:14 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_comprobation(t_vars *vars)
{
	int	valor;

	valor = 1;
	valor *= wall_comprobation(vars);
	valor *= especial_comprobation(vars);
	ft_printf("form: %d\n", form_comprobation(vars));
	return (valor);
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
	len = vars->len_map * 2 + 1;
	while (i < vars->layers_map - 1)
	{
		if (vars->map[0] != '1' || vars->map[len - 1] != '1')
			return (-1);
		++i;
		len += vars->len_map + 1;
	}
	while (i <= vars->len_map - 1)
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
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P')
			p++;
		if (vars->map[i] == 'E')
			e++;
		if (vars->map[i] == 'C')
			c++;
		++i;
	}
	if (p != 1 && e != 1 && c < 1)
		return (-1);
	return (1);
}

int	form_comprobation(t_vars *vars)
{
	int	i;
	int	len;

	i = 0;
	while (i < vars->layers_map)
	{
		len = i;
		while (vars->map[len] != '\n')
			++len;
		ft_printf("len: %d\n", len);
		if (len != vars->len_map)
			return (-1);
		++i;
	}
	return (1);
}
