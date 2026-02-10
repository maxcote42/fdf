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

// on va chercher l'adresse du pixel voulu
// on lui attribue la couleur souhaitee
// bpp bits per pixel et 1 octet = 8 bits donc on divise pour passer en octet
// line_len = bytes par ligne de l'image
static void	add_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= SCREEN_X || y >= SCREEN_Y)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}


void	trace_wireframe(t_app *app)
{
	unsigned int	x;
	unsigned int	y;
	int				height;
	int				width;
	int 			img_x;
	int				img_y;

	height = app->map.height;
	width = app->map.width;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			img_x = (int)app->map.points[y][x].x_iso;
			img_y = (int)app->map.points[y][x].y_iso;
			add_pixel(&app->image, img_x, img_y, app->map.points[y][x].color);
			x++;
		}
		y++;
	}
}

/*			if (x < width - 1)
				add_pixel(app->img, app->map);
			if (y < height - 1)
				add_pixel();
				*/