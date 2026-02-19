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

#include "fdf.h"

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

static void	trace_line(t_app *app, t_point a, t_point b)
{
	int		color;
	t_algo	br;

	init_bresenham(&br, a, b);
	color = a.color;
	add_pixel(&app->image, a.x_iso, a.y_iso, color);
	while (a.x_iso != b.x_iso || a.y_iso != b.y_iso)
	{
		color_step(&br, &color);
		br.e2 = 2 * br.err;
		if (br.e2 > -br.dy)
		{
			br.err -= br.dy;
			a.x_iso += br.sx;
		}
		if (br.e2 < br.dx)
		{
			br.err += br.dx;
			a.y_iso += br.sy;
		}
		add_pixel(&app->image, a.x_iso, a.y_iso, color);
	}
}

void	trace_wireframe(t_app *app)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	height;
	unsigned int	width;

	convert_scale(app);
	height = app->map.height;
	width = app->map.width;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x < width - 1)
				trace_line(app, app->map.points[y][x],
					app->map.points[y][x + 1]);
			if (y < height - 1)
				trace_line(app, app->map.points[y][x],
					app->map.points[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->image.img, 0, 0);
}
