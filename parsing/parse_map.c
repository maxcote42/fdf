// width;   // abscisse (x)
// height;  // ordonnée (y)
#include "../fdf.h"

static int	count_arg(char *line)
{
	int	i;
	int	count;

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
	int		x;
	int		y;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (y == 0)
			x = count_arg(line);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->width = x;
	map->height = y;
	return (0);
}

int	parse_map(char *file, t_map *map)
{
	if (get_dim(file, map) == 1)
		return (1);
	if (fill_map(file, map) == 1)
		return (1);
	return (0);
}
