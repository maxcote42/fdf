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

void	trace_wireframe(t_app *app)
{
	int	x;
	int	y;
	int	height;
	int	width;

	height = app->map.height;
	width = app->map.width;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x < width - 1)
				trace_line(&app->map.points[y][x], &app->map.points[y][x + 1]);
			if (y < height - 1)
				trace_line(&app->map->points[y][x], &app->map->points[y + 1][x]);
			x++;
		}
		y++;
	}*/
}
