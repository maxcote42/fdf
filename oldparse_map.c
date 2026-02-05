#include "fdf.h"

static int	count_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(perror("open"), 1);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close (fd);
	return (height);
}

int	nb_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	parse_map(char *file, t_map *map)
{
	int x;
	int	y;
	char *line;
	char **split;

	map->height = count_height(file);
	map->z = malloc(sizeof(int *) * (map->height));
	if (!(map->z))
		exit (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit (1);
	}
	y = 0;
	while(get_next_line(fd, &line))
	{
		split = ft_split(line, ' ');
		free(line);
		if (!split)
		{
			free_map(map->z, map->height);
			return (0);
		}
		map->z[y] = malloc(sizeof(int) * nb_arg(split));
		if (!(map->z[y]))
		{
			free(map->z, map->height);
			return (0);
		}
		x = 0;
		while (split[x])
		{
			map->z[y][x] = ft_atoi(split[x]);
			x++;
		}
		free (split);
		y++;
	}
	map->width = x;
	close (fd);
	return (1);
}