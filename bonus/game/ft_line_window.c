/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:43:11 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/20 07:49:52 by njohanne         ###   ########.fr       */
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
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/w.xpm", &a, &a);
		if (line[j] == '0')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/fr.xpm", &a, &a);
		if (line[j] == 'P')
		{
			img = mlx_xpm_file_to_image(map->mlx, map->img_p, &a, &a);
			map->p_x = j;
			map->p_y = i;
		}
		if (line[j] == 'F')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/f1.xpm", &a, &a);
		if (line[j] == 'E')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/e1.xpm", &a, &a);
		if (line[j] == 'C')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/c1.xpm", &a, &a);
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
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/w.xpm", &a, &a);
		if (line[j] == '0')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/fr.xpm", &a, &a);
		if (line[j] == 'P')
		{
			img = mlx_xpm_file_to_image(map->mlx, map->img_p, &a, &a);
			map->p_x = j;
			map->p_y = i;
		}
		if (line[j] == 'F')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/f.xpm", &a, &a);
		if (line[j] == 'E')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/e.xpm", &a, &a);
		if (line[j] == 'C')
			img = mlx_xpm_file_to_image(map->mlx, "./bonus/img/c.xpm", &a, &a);
		mlx_put_image_to_window (map->mlx, map->win, img, j * 40, i * 40);
	}
}
