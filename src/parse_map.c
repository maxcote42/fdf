/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:37:51 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:37:52 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// width;   // abscisse (x)
// height;  // ordonnée (y)
#include "fdf.h"

static unsigned int	count_arg(char *line)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((!iswhitespace(line[i]))
			&& ((i == 0) || (iswhitespace(line[i - 1]))))
			count++;
		i++;
	}
	return (count);
}

static int	get_dim(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (map->height == 0)
			map->width = count_arg(line);
		if (map->height != 0 && map->width != count_arg(line))
		{
			free(line);
			close(fd);
			return (1);
		}
		map->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	parse_map(char *file, t_map *map)
{
	if (get_dim(file, map) == 1)
	{
		ft_printf("La carte n'est pas correctement dimensionnée\n");
		return (1);
	}
	if (fill_map(file, map) == 1)
		return (1);
	return (0);
}
