#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	int	**z;
} t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
} t_point;

// parsing
int	parse_map(char *file, t_map *map);
int	fill_map(char *file, t_map *map);

// utils
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	free_tab(char **tab);
void	free_map(int **z, int height);

# endif