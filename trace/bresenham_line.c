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

void	x_bresenham(oid *win, void *mlx, t_point *p1, t_point *p2)
{
	int		step_x;
	int		step_y;
	float	color;
	float	step_color;
	int		err;
	int		dx;
	int		dy;

	step_x = 1;
	if (p1->x_iso > p2->x_iso)
		step_x = -1;
	step_y = 1;
	if (p1->y_iso > p2->y_iso)
		step_y = -1;
	step_color = step_color(p1, p2);
	color = (float)p1->color;
	dx = abs(p2->x_iso - p1->x_iso);
	dy = abs(p2->y_iso - p1->y_iso);
	err = 2 * dy - dx;
	while (p1->x_iso != p2->x_iso)
	{
		mlx_pixel_put(mlx, win, p1->x_iso, p1->y_iso, (int)color);
		p1->x_iso += step_x;
		color += step_color;
		err += 2*dy;
		if (err >= dx)
		{
			err -= 2*dx;
			p1->y_iso += step_y;
		}
	}
}

void	y_bresenham(oid *win, void *mlx, t_point *p1, t_point *p2)
{

}

void	bresenham_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	float	dx;
	float	dy;

	dx = p2->x_iso - p1->x_iso;
	dy = p2->y_iso - p1->y_iso;
	if (abs(dx) > abs(dy))
		x_bresenham(win, mlx, p1, p2);
	else
		y_bresenham(win, mlx, p1, p2);


}
