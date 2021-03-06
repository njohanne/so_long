/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:40:34 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/20 07:51:01 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx.h"
// # include <mlx.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		stl;
	int		str;
	int		player;
	int		exit;
	int		collect;
	int		fight;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	void	*img_p;
	char	*step;
}	t_map;

void	ft_error(char *str);
size_t	ft_strlen(const char *array);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_check_map(t_map *map);
int		ft_check_requirement(t_map *map);
void	ft_window(t_map *map);
void	ft_game(int keycode, t_map *map);
void	ft_putchar(char c);
void	ft_putnbr(int n);

int		ft_check_map_bonus(t_map *map);
int		ft_check_requirement_bonus(t_map *map);
void	ft_window_bonus(t_map *map);
void	ft_game_bonus(int keycode, t_map *map);
char	*ft_itoa(int n);
void	ft_line_window(char *line, t_map *map, int i);
void	ft_line_window_1(char *line, t_map *map, int i);
#endif