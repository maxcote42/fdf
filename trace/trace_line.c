/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:15:07 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/09 12:15:08 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// width;   // abscisse (x)
// height;  // ordonnée (y)

static void	line_directions(t_point *p1, t_point *p2, float *step_x, float *step_y)
{
	int		dx;
	int		dy;
	int		step;

	dx = p2->x_iso - p1->x_iso;
	dy = p2->y_iso - p1->y_iso;
	if (abs(dx) > abs (dy))
		step = abs(dx);
	else
		step = abs(dy);
	*step_x = dx / (float)step;
	*step_y = dy / (float)step;
}

void	trace_line(void *mlx, void *win, t_point *p1, t_point *p2)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;
	float	color;
	float	step_col;

	x = p1->x_iso;
	y = p1->y_iso;
	
	line_directions(p1, p2, &step_x, &step_y);
	color = p1->color;
	step_col = step_color(p1, p2);
	while ((int)x != p2->x_iso || (int)y != p2->y_iso)
	{
		mlx_pixel_put(mlx, win, (int)x, (int)y, (int)color);
		color += step_col;
		x += step_x;
		y += step_y;
	}
}