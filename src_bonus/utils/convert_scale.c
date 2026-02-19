/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:37:57 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/09 09:37:58 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// width;   // abscisse (x)
// height;  // ordonnée (y)

// traduction en pixel ecran des coordonnees iso selon les coordonnees origine
static void	convert_point_iso(t_app *app, t_point *p)
{
	p->x_iso = app->origin_x + app->scale * ((p->x - p->y) * app->cos_radiant);
	p->y_iso = app->origin_y + app->scale
		* ((p->x + p->y) * app->sin_radiant - p->z);
}

void	convert_scale(t_app *app)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < app->map.height)
	{
		x = 0;
		while (x < app->map.width)
		{
			convert_point_iso(app, &app->map.points[y][x]);
			x++;
		}
		y++;
	}
}
