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

void	trace_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	p1->x_iso = ORIGIN_X * SCALE;
	p1->y_iso = ORIGIN_Y * SCALE;
	p2->x_iso = ORIGIN_X * SCALE;
	p2->y_iso = ORIGIN_Y * SCALE;
	if (p1->x_iso == p2->x_iso)
		horizontal_line(win, mlx, &map->points[y][x], &map->points[y][x + 1]);
	else if (p1->y_iso == p2->y_iso)
		vertical_line(win, mlx, &map->points[y][x], &map->points[y][x + 1]);
	else
		bresenham_line(win, mlx, &map->points[y][x], &map->points[y][x + 1]);
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
				trace_line(win, mlx, &map->points[y][x], &map->points[y][x + 1]);
			if (y < height - 1)
				trace_line(win, mlx, &map->points[y][x], &map->points[y + 1][x]);
			x++;
		}
		y++;
	}
}
