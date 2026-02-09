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

#include "../fdf.h"

// width;   // abscisse (x)
// height;  // ordonnée (y)

// traduction en pixel ecran des coordonnees iso selon les coordonnes origine
void	convert_point_iso(t_point *p)
{
	p->x_iso = ORIGIN_X + SCALE * ((p->x - p->y) * cos(ANGLE));
	p->y_iso = ORIGIN_Y + SCALE * ((p->x + p->y) * sin(ANGLE) - p->z);
}

void	convert_scale(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			convert_point_iso(&map->points[y][x]);
			x++;
		}
		y++;
	}
}