/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:48:11 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/04 19:23:28 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_name_file_map(char *str)
{
	int	len;

	len = ft_strlen(str);
	len--;
	if (str[len] == 'r' && str[len - 1] == 'e' && str[len - 2] == 'b'
		&& str[len - 3] == '.')
		return (1);
	ft_error("Error: map is not .ber, why?\n");
	return (0);
}

char	*ft_line_map(char *line, int fd)
{
	char	*buf;
	int		rd;

	buf = (char *)malloc(sizeof(char));
	if (!buf)
	{
		ft_error("Error: not memory for buf");
		return (0);
	}
	rd = read(fd, buf, 1);
	if (rd == 0)
	{
		ft_error("Error: not bits in file\n");
		return (0);
	}
	line = "";
	while (rd)
	{
		line = ft_strjoin(line, buf);
		rd = read(fd, buf, 1);
	}
	free(buf);
	return (line);
}

char	**ft_load_map(int fd)
{
	char	**map;
	char	*line;

	line = (char *)malloc(sizeof(char));
	if (!line)
	{
		ft_error("Error: not memory for line");
		return (0);
	}
	line = ft_line_map(line, fd);
	map = ft_split(line, '\n');
	free(line);
	return (map);
}

int	main(int avc, char **avg)
{
	int		fd;
	t_map	map;

	if (avc != 2)
	{
		ft_error("Error: ./so_long ./*.ber\n");
		return (0);
	}
	if (!ft_check_name_file_map(avg[1]))
		return (0);
	fd = open (avg[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error: map is not open\n");
		return (0);
	}
	map.map = ft_load_map(fd);
	if (!ft_check_map(&map))
		return (0);
	ft_window (&map);
	free(map.map);
	return (0);
}
