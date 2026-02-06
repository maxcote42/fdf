/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:37:46 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:37:47 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_altitude(char *value)
{
	int	i;
	int	count;
	int	sign;

	i = 0;
	sign = 1;
	count = 0;
	if (value[i] == '-' || value[i] == '+' )
	{
		if (value[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(value[i]))
	{
		count = count * 10 + (value[i] - '0');
		i++;
	}
	return (sign * count);
}

static int	get_color(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value [i] == ',')
			return (hex_to_int(&value[i + 1]));
		i++;
	}
	return (0xFFFFFF);
}

static void	fill_line(char **values, t_map *map, int y)
{
	int	x;

	x = 0;
	while (x < (int)map->width)
	{
		map->points[y][x].x = x;
		map->points[y][x].y = y;
		map->points[y][x].z = get_altitude(values[x]);
		map->points[y][x].color = get_color(values[x]);
		x++;
	}
}

static int	split_line(char *line, t_map *map, int y)
{
	char	**values;

	map->points[y] = malloc(sizeof(t_point) * map->width);
	if (!map->points[y])
		return (1);
	values = ft_split(line, ' ');
	if (!values)
		return (1);
	fill_line(values, map, y);
	free_tab(values);
	return (0);
}

int	fill_map(char *file, t_map *map)
{
	int		fd;
	int		y;
	char	*line;

	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		if (split_line(line, map, y++) == 1)
		{
			close(fd);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
