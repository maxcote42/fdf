#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_point;

// width;   // abscisse (x)
// height;  // ordonnée (y)
typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	t_point	**points;
} t_map;

// parsing
int		parse_map(char *file, t_map *map);
int		fill_map(char *file, t_map *map);

// utils
void	free_tab(char **tab);
void	free_map(int **z, int height);
int		hex_to_int(char *hex);
int		iswhitespace(char c);

# endif