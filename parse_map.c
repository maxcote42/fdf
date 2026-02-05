#include "fdf.h"
// height = lignes
// width = colonnes

static int count_width (char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) && (i == 0 || line[i - 1] == ' '))
			count++;
		i++;
	}
	return(count);
}

static void	count_dimension(char *file, t_map *map)
{
	int	i;
	int	fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			map->width = count_width(line);
		i++;
		free(line);
	}
	close(fd);
	map->height = i;
}

static int	fill_map(int fd, t_map *map)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_split(line, ' ');
		free(line);
		y = 0;
		map->z[x] = malloc(sizeof(int) * map->width);
		if (!map->z[x])
			return (0);
		while (y < map->width)
		{
			map->z[x][y] = ft_atoi(split[y]);
			y++;
		}
		free_tab(split);
		x++;
	}
	return (1);
}

int	parse_map(char *file, t_map *map)
{
	int	fd;

	count_dimension(file, map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	map->z = malloc(sizeof(int *) * map->height);
	if (!map->z || (fill_map(fd, map) == 0))
	{
		free_map(map->z);
		perror("malloc or fill_map");
		close(fd);
		exit(1);
	}
	close(fd);
	return(1);
}