/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:07:12 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/05 16:02:21 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_line_window_1(char *line, t_map *map, int i)
{
	int		j;
	void	*img;
	int		a;

	j = -1;
	while (line[++j])
	{
		if (line[j] == '1')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/wall.xpm", &a, &a);
		if (line[j] == '0')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/free.xpm", &a, &a);
		if (line[j] == 'P')
		{
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/play.xpm", &a, &a);
			map->p_x = j;
			map->p_y = i;
		}
		if (line[j] == 'F')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/fight1.xpm", &a, &a);
		if (line[j] == 'E')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/exit11.xpm", &a, &a);
		if (line[j] == 'C')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/coll11.xpm", &a, &a);
		mlx_put_image_to_window (map->mlx, map->win, img, j * 40, i * 40);
	}

}

void	ft_line_window(char *line, t_map *map, int i)
{
	int		j;
	void	*img;
	int		a;

	j = -1;
	while (line[++j])
	{
		if (line[j] == '1')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/wall.xpm", &a, &a);
		if (line[j] == '0')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/free.xpm", &a, &a);
		if (line[j] == 'P')
		{
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/play.xpm", &a, &a);
			map->p_x = j;
			map->p_y = i;
		}
		if (line[j] == 'F')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/fight.xpm", &a, &a);
		if (line[j] == 'E')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/exit.xpm", &a, &a);
		if (line[j] == 'C')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/coll.xpm", &a, &a);	
		mlx_put_image_to_window (map->mlx, map->win, img, j * 40, i * 40);
	}
}

int	ft_img_to_window(t_map *map)
{
	int			i;
	char		*steps;
	static int	step = 0;
	static int	flag = 0;

	i = -1;
	if (flag < 50)
	{
		while (map->map[++i])
			ft_line_window(map->map[i], map, i);
	}
	else if (flag > 50)
	{
		while (map->map[++i])
			ft_line_window_1(map->map[i], map, i);	
	}
//	steps = ft_steps(steps);
	flag++;
	if (flag == 100)
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
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->stl * 40, map->str * 40,
			"so_long_bonus");
	ft_img_to_window(map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_hook(map->win, 17, 0, cloze, NULL);
	mlx_loop_hook(map->mlx, &ft_img_to_window, map);
	mlx_loop(map->mlx);
	free (map->map);
}
