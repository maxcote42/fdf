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

static void	init_color(t_algo *br, t_point a, t_point b)
{
	int	fraction;

	if (br->dx > br->dy)
		fraction = br->dx;
	else
		fraction = br->dy;
	if (fraction == 0)
		return ;
	br->step_R = ((((b.color >> 16) & 0xFF) - ((a.color >> 16) & 0xFF))) / fraction;
	br->step_G = (((b.color >> 8) & 0xFF) - ((a.color >> 8) & 0xFF)) / fraction;
	br->step_B = ((b.color & 0xFF) - (a.color & 0xFF)) / fraction ;
}

static void	init_bresenham(t_algo *br, t_point a, t_point b)
{
	br->dx = abs(b.x_iso - a.x_iso);
	br->dy = abs(b.y_iso - a.y_iso);
	br->sx = ft_sign(b.x_iso - a.x_iso);
	br->sy = ft_sign(b.y_iso - a.y_iso);
	br->err = br->dx - br->dy;
	init_color(br, a, b);
}

static void	color_step(t_algo br, int *color)
{
	float	R;
	float	G;
	float	B;
	float	new_color;

	R = (*color >> 16 & 0xFF) + br.step_R;
	G = (*color >> 8 & 0xFF) + br.step_G;
	B = (*color & 0xFF) + br.step_B;
	new_color = R * 256 * 256 + G * 256 + B;
	*color = (int)new_color;
}

static void	trace_line(t_app *app, t_point a, t_point b)
{
	int		color;
	t_algo	br;

	init_bresenham(&br, a, b);
	color = a.color;
	while (1)
	{
		add_pixel(&app->image, a.x_iso, a.y_iso, color);
		if (a.x_iso == b.x_iso && a.y_iso == b.y_iso)
			break ;
		color_step(br, &color);
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
}

/* ------------------------16h
static void	init_bresenham(t_algo *br, t_point a, t_point b)
{
	br->dx = abs(b.x_iso - a.x_iso);
	br->dy = abs(b.y_iso - a.y_iso);
	br->sx = ft_sign(a.x_iso - b.x_iso);
	br->sy = ft_sign(a.y_iso - b.y_iso);
	if (br.dx >= br.dy)
	{
		br->slope = 2 * br.dy;
		br->error = -br.dx;
		br->errorinc = -2 * br.dx;
	}
	else 
	{
		br->slope = 2 * br.dx;
		br->error = -br.dy;
		br->errorinc = -2 * br.dy;
	}
}

static void bresenham(t_app *app, t_point a, t_point b, int step)
{
	t_algo	br;

	init_bresenham(&br, a, b);
	if (br.dx > br.dy)
	{
		while (a.x_iso != b.x_iso)
		{
			add_pixel(&app->image, a.x_iso, a.y_iso, color);
			a.x_iso += br.sx;
			color += step;
			br.error += br.slope;
			if (br.error >= 0)
			{
				a.y_iso += br.sy;
				br.error += br.errorinc;
			}
		}
	}
	else
		{
		while (a.y_iso != b.y_iso)
		{
			add_pixel(&app->image, a.x_iso, a.y_iso, color);
			a.y_iso += br.sy;
			color += step;
			br.error += br.slope;
			if (br.error >= 0)
			{
				a.x_iso += br.sx;
				br.error += br.errorinc;
			}
		}
	}
}


static void	trace_line(t_app *app, t_point a, t_point b)
{
	int	color;
	int	step_color;

	color = a.color;
	step = step_color(a, b);
	if ((b.x_iso == a.x_iso))
	{
		while (a.y_iso != b.y_iso)
		{
			add_pixel(&app->image, a.x_iso, a.y_iso++, color);
			color += step;
		}
	}
	else if (b.y_iso == a.y_iso)
	{
		while (a.x_iso != b.x_iso)
		{
			add_pixel(&app->image, a.x_iso++, a.y_iso, color);
			color += step;
		}
	}
	else 
		bresenham(app, a, b, step);
}

void	trace_wireframe(t_app *app)
{
	unsigned int	x;
	unsigned int	y;
	int				height;
	int				width;

	height = app->map.height;
	width = app->map.width;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x < width - 1)
				trace_line(app, app.map.points[y][x], app.map.points[y][x + 1]);
			if (y < height - 1)
				trace_line(app, app.map.points[y][x], app.map.points[y + 1][x]);
			x++;
		}
		y++;
	}
}

			if (x < width - 1)
				add_pixel(app->img, app->map);
			if (y < height - 1)
				add_pixel();


--------------- MARCHE------------------------------
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
				*/