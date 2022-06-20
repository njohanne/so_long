/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:06:46 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/20 07:41:52 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_line_window(char *line, t_map *map, int i)
{
	int		j;
	void	*img;
	int		a;

	j = -1;
	while (line[++j])
	{
		if (line[j] == '1')
			img = mlx_xpm_file_to_image(map->mlx, "./mand/img/w.xpm", &a, &a);
		if (line[j] == '0')
			img = mlx_xpm_file_to_image(map->mlx, "./mand/img/f.xpm", &a, &a);
		if (line[j] == 'P')
		{
			img = mlx_xpm_file_to_image(map->mlx, "./mand/img/p.xpm", &a, &a);
			map->p_x = j;
			map->p_y = i;
		}
		if (line[j] == 'E')
			img = mlx_xpm_file_to_image(map->mlx, "./mand/img/e.xpm", &a, &a);
		if (line[j] == 'C')
			img = mlx_xpm_file_to_image(map->mlx, "./mand/img/c.xpm", &a, &a);
		mlx_put_image_to_window (map->mlx, map->win, img, j * 40, i * 40);
	}
}

void	ft_img_to_window(t_map *map)
{
	int		i;

	i = -1;
	while (map->map[++i])
	{
		ft_line_window(map->map[i], map, i);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	ft_game(keycode, map);
	ft_img_to_window (map);
	return (0);
}

int	cloze(void *vp)
{
	vp = NULL;
	exit(0);
}

void	ft_window(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->stl * 40, map->str * 40,
			"so_long");
	ft_img_to_window(map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_hook(map->win, 17, 0, cloze, NULL);
	mlx_loop(map->mlx);
	free (map->map);
}
