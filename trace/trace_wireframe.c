/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_wireframe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:37:47 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/09 09:37:48 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// width;   // abscisse (x)
// height;  // ordonnée (y)

//dx = 0
static void	vertical_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	int	y;
	int	step;
	int	color;
	int	step_color;

	step = 1;
	if (p1->y_iso > p2->y_iso)
		step = -1;
	y = p1->y_iso;
	step_color = step_color(p1, p2);
	color = p1->color;
	while (y != (p2->y_iso + step))
	{
		draw_pixel(win, mlx, p1->x_iso, y, color);
		y += step;
		color += step_color;
	}
}

//dy = 0
static void	horizontal_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	int	x;
	int	step;
	int	color;
	int	step_color;

	step = 1;
	if (p1->x_iso > p2->x_iso)
		step = -1;
	x = p1->x_iso;
	step_color = step_color(p1, p2);
	color = p1->color;
	while (x != (p2->x_iso + step))
	{
		draw_pixel(win, mlx, x, p1->y_iso, color);
		x += step;
		color += step_color;
	}
}

// traduction en pixel ecran des coordonnees iso selon les coordonnes origine
static void	init_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	p1->x_iso = ORIGIN_X * SCALE;
	p1->y_iso = ORIGIN_Y * SCALE;
	p2->x_iso = ORIGIN_X * SCALE;
	p2->y_iso = ORIGIN_Y * SCALE;
	if ((p1->x_iso == p2->x_iso) && (p1->y_iso == p2->y_iso))
		//FONCTION A METTRE DE DESINER PIXEL
	else if (p1->x_iso == p2->x_iso)
		vertical_line(win, mlx, p1, p2);
	else if (p1->y_iso == p2->y_iso)
		horizontal_line(win, mlx, p1, p2);
	else
		bresenham_line(win, mlx, p1, p2);
}


void	trace_wireframe(t_map *map, void *win, void *mlx)
{
	int	x;
	int	y;
	
	convert_iso(map);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x < width - 1)
				init_line(win, mlx, &map->points[y][x], &map->points[y][x + 1]);
			if (y < height - 1)
				init_line(win, mlx, &map->points[y][x], &map->points[y + 1][x]);
			x++;
		}
		y++;
	}
}
