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
# include "mlx.h"
# include <X11/keysym.h>

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
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	step_r;
	float	step_g;
	float	step_b;
	float	init_r;
	float	init_g;
	float	init_b;
}	t_algo;

typedef struct s_app
{
	t_map	map;
	t_image	image;
	void	*mlx;
	void	*win;
	double	scale;
	double	origin_x;
	double	origin_y;
	double	cos_radiant;
	double	sin_radiant;
}	t_app;

// parsing
int		parse_map(char *file, t_map *map);
int		fill_map(char *file, t_map *map);

// utils
void	convert_scale(t_app *app);
void	free_tab(char **tab);
void	free_map(t_point **points, int height);
int		hex_to_int(char *hex);
int		iswhitespace(char c);
int		ft_sign(int c);
void	setup_hooks(t_app *app);
void	init_color(t_algo *br, t_point a, t_point b);
void	init_bresenham(t_algo *br, t_point a, t_point b);
void	color_step(t_algo *br, int *color);

// trace
void	trace_wireframe(t_app *app);
void	draw(t_app *app);

#endif
