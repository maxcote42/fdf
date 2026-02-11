/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:36:39 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:36:41 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "minilibx-linux/mlx.h"

// definitions primaires
// 30° en radians
// width;   // abscisse (x)
// height;  // ordonnée (y)

# define ANGLE 0.523599
# define SCALE 12
# define ORIGIN_X 600
# define ORIGIN_Y 500
# define SCREEN_X 1200
# define SCREEN_Y 900

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	x_iso;
	int	y_iso;
}	t_point;

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	t_point			**points;
}	t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_algo
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
}	t_algo;

typedef struct s_app
{
	t_map	map;
	t_image	image;
	void	*mlx;
	void	*win;
}	t_app;

// parsing
int		parse_map(char *file, t_map *map);
int		fill_map(char *file, t_map *map);

// utils
void	convert_scale(t_map *map);
void	free_tab(char **tab);
void	free_map(t_point **points, int height);
int		hex_to_int(char *hex);
int		iswhitespace(char c);
int		ft_fraction(t_point *p1, t_point *p2);
float	step_color(t_point *p1, t_point *p2);
int		ft_sign(int c);

// trace
void	trace_wireframe(t_app *app);

#endif
