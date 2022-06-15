/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:33:18 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/14 17:01:22 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_img(int keycode)
{
	if (keycode == 13)
		return("./bonus/img/play.xpm");
	else if (keycode == 1)
		return("./bonus/img/coll1.xpm");
	else if (keycode == 0)
		return("./bonus/img/exit1.xpm");
	else
		return("./bonus/img/fight.xpm");
}

void	ft_game_bonus(int keycode, t_map *map)
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
	}
	else if (map->map[new_y][new_x] == 'F')
		exit (0);
	else if (map->map[new_y][new_x] == 'E' && map->collect == 0)
		exit (0);
	map->step = ft_itoa(step);
	map->img_p = ft_img(keycode);	
}
