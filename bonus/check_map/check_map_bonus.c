/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:47:09 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/27 13:55:16 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_check_stl_str(t_map *map)
{
	int	str;
	int	stl;

	str = 0;
	while (map->map[str])
	{
		stl = 0;
		while (map->map[str][stl])
			stl++;
		if (str == 0)
			map->stl = stl;
		else if (stl != map->stl)
		{
			ft_error("Error: map error, stl is not norm\n");
			return (0);
		}
		str++;
	}
	map->str = str;
	return (1);
}

int	ft_check_map_bonus(t_map *map)
{
	if (!ft_check_stl_str(map))
		return (0);
	if (!ft_check_requirement_bonus(map))
		return (0);
	return (1);
}
