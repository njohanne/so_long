/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_requirement_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:56:30 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/27 13:58:57 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#include "../so_long.h"

int	ft_check_simv(char c, t_map *map)
{
	if (c == 'P')
		map->player++;
	else if (c == 'C')
		map->collect++;
	else if (c == 'E')
		map->exit++;
	else if (c == 'F')
		map->fight++;
	else if (c != '0' && c != '1')
	{
		ft_error("Error: bug simvol blya\n");
		return (0);
	}
	return (1);
}

int	ft_check_str(char *str, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->stl)
	{
		if (i == 0 || i == map->stl - 1)
		{
			if (str[i] != '1')
			{
				ft_error ("Error: net stenki\n");
				return (0);
			}
		}
		else if (!ft_check_simv(str[i], map))
			return (0);
	}
	return (1);
}

int	ft_first_end_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			ft_error("Error: map not valid up or down\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_requirement_bonus(t_map *map)
{
	int	i;

	i = 0;
	map->player = 0;
	map->collect = 0;
	map->exit = 0;
	map->fight = 0;
	while (map->map[i])
	{
		if (i == 0 || i == (map->str - 1))
		{
			if (!ft_first_end_str(map->map[i]))
				return (0);
		}
		else if (!ft_check_str(map->map[i], map))
			return (0);
		i++;
	}
	if (map->player != 1 || map->collect < 1 || map->exit < 1)
	{
		ft_error("Error: map dont have player, collect or exit\n");
		return (0);
	}
	return (1);
}
