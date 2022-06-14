/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:33:18 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/04 18:09:58 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game(int keycode, t_map *map)
{
	int			new_x;
	int			new_y;
	static int	step = 0;

	new_y = map->p_y - (keycode == 13) + (keycode == 1);
	new_x = map->p_x - (keycode == 0) + (keycode == 2);
	if (map->map[new_y][new_x] == 'C' || map->map[new_y][new_x] == '0')
	{
		if (map->map[new_y][new_x] == 'C')
			map->collect--;
		map->map[map->p_y][map->p_x] = '0';
		map->map[new_y][new_x] = 'P';
		map->p_x = new_x;
		map->p_y = new_y;
		step++;
		ft_putnbr(step);
		ft_putchar('\n');
	}
	else if (map->map[new_y][new_x] == 'E' && map->collect == 0)
		exit (0);
}
