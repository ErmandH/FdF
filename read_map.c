/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:00:53 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/08 19:48:39 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_count_width(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static	size_t	ft_count_heigth(int fd)
{
	size_t	height;
	char	*line;

	height = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static void	fill_row(t_dot *row, char *line, size_t x, size_t row_i)
{
	size_t	i;
	char	**split;

	split = ft_split(line, ' ');
	i = 0;
	while (i < x)
	{
		row[i].y = row_i;
		row[i].x = i;
		row[i].z = ft_atoi(split[i]);
		if (i == x - 1)
			row[i].is_last = 1;
		else
			row[i].is_last = 0;
		i++;
	}
	free_columns(split);
	free(split);
}

static t_dot	**create_matrix(char *map_name, size_t width, size_t height)
{
	t_dot	**map;
	char	*line;
	int		fd;
	size_t	i;

	map = (t_dot **)malloc(sizeof(t_dot *) * (height + 1));
	if (!map)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		map[i] = (t_dot *)malloc(sizeof(t_dot) * width);
		if (!map[i])
			return (NULL);
		fill_row(map[i], line, width, i);
		set_color(map[i], i, width);
		free(line);
		i++;
	}
	map[0][0].is_rainbow = 1;
	map[i] = NULL;
	close(fd);
	return (map);
}

t_dot	**read_map(char *map_name)
{
	int		fd;
	t_dot	**map;
	char	*line;
	size_t	width;
	size_t	height;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error("Invalid file\n");
	line = get_next_line(fd);
	if (!line)
		error("Invalid map\n");
	width = ft_count_width(line, ' ');
	free(line);
	height = ft_count_heigth(fd);
	map = create_matrix(map_name, width, height);
	if (!map)
		return (NULL);
	return (map);
}
