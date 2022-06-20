/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:07:12 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/20 07:46:01 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_img_to_window(t_map *map)
{
	int			i;
	static int	step = 0;
	static int	flag = 0;

	i = -1;
	if (flag == 0)
	{
		while (map->map[++i])
			ft_line_window(map->map[i], map, i);
	}
	else if (flag == 25)
	{
		while (map->map[++i])
			ft_line_window_1(map->map[i], map, i);
	}
	mlx_string_put(map->mlx, map->win, 15, 15, 0x000000, map->step);
	flag++;
	if (flag == 50)
		flag = 0;
	return (1);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	ft_game_bonus(keycode, map);
	ft_img_to_window(map);
	return (0);
}

int	cloze(void *vp)
{
	vp = NULL;
	exit(0);
}

void	ft_window_bonus(t_map *map)
{
	map->step = ft_itoa(0);
	map->img_p = "./bonus/img/play.xpm";
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->stl * 40, map->str * 40,
			"so_long_bonus");
	ft_img_to_window(map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_loop_hook(map->mlx, &ft_img_to_window, map);
	mlx_loop(map->mlx);
	mlx_hook(map->win, 17, 0, cloze, NULL);
	free (map->map);
	free (map->step);
}
