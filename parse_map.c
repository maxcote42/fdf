#include "fdf.h"

static int	count_width()
{

}

static int	count_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(perror("open"), 1);
	height = 0;
	while (get_next_line(file, &line))
	{
		height++;
		free(line);
	}
	close (fd);
	return (height);
}

int	parse_map(char *file, t_map *map);
{
	int	y;
	char *line;
	char *split;

	map->height = count_height(file);
	map->z = malloc(sizeof(*int) * (map->height));
	// if (!(map->z))
	//		return (0);
	fd = open(file, O_RDONLY);
		exit(perror("open"), 1);
	y = 0;
	while(get_next_line(file, &line))
	{
		split = ft_split(line, ' ');
		map->z[y] = malloc(sizeof(int) * )

	}


}