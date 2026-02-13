#include "fdf.h"

void	init_color(t_algo *br, t_point a, t_point b)
{
	float	fraction;
	int		dr;
	int		dg;
	int		db;

	if (br->dx > br->dy)
		fraction = (float)br->dx;
	else
		fraction = (float)br->dy;
	if (fraction == 0)
		fraction = 1;
	dr = ((b.color >> 16) & 0xFF) - ((a.color >> 16) & 0xFF);
	dg = ((b.color >> 8) & 0xFF) - ((a.color >> 8) & 0xFF);
	db = (b.color & 0xFF) - (a.color & 0xFF);
	br->step_R = (float)dr / (float)fraction;
	br->step_G = (float)dg / (float)fraction;
	br->step_B = (float)db / (float)fraction;
	br->init_R = (a.color >> 16) & 0xFF;
	br->init_G = (a.color >> 8) & 0xFF;
	br->init_B = a.color & 0xFF;
}

void	init_bresenham(t_algo *br, t_point a, t_point b)
{
	br->dx = abs(b.x_iso - a.x_iso);
	br->dy = abs(b.y_iso - a.y_iso);
	br->sx = ft_sign(b.x_iso - a.x_iso);
	br->sy = ft_sign(b.y_iso - a.y_iso);
	br->err = br->dx - br->dy;
	init_color(br, a, b);
}

void	color_step(t_algo *br, int *color)
{
	br->init_R += br->step_R;
	br->init_G += br->step_G;
	br->init_B += br->step_B;
	*color = ((int)br->init_R << 16) | ((int)br->init_G << 8) | (int)br->init_B;
}