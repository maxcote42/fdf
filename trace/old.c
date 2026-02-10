/*//dx = 0
static void	vertical_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	int		y;
	int		step;
	float	color;
	int		step_col;

	step = 1;
	if (p1->y_iso > p2->y_iso)
		step = -1;
	y = p1->y_iso;
	step_col = step_color(p1, p2);
	color = p1->color;
	while (y != (p2->y_iso + step))
	{
		mlx_pixel_put(mlx, win, p1->x_iso, y, color);
		y += step;
		color += step_col;
	}
}

//dy = 0
static void	horizontal_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	int	x;
	int	step;
	int	color;
	int	step_col;

	step = 1;
	if (p1->x_iso > p2->x_iso)
		step = -1;
	x = p1->x_iso;
	step_col = step_color(p1, p2);
	color = p1->color;
	while (x != (p2->x_iso + step))
	{
		mlx_pixel_put(mlx, win, x, p1->y_iso, color);
		x += step;
		color += step_col;
	}
}

static void	init_line(void *win, void *mlx, t_point *p1, t_point *p2)
{
	mlx_pixel_put(mlx, win, p1->x_iso, p1->y_iso, p1->color);
	if ((p1->x_iso == p2->x_iso) && (p1->y_iso == p2->y_iso))
		return ;
	else if (p1->x_iso == p2->x_iso)
		vertical_line(win, mlx, p1, p2);
	else if (p1->y_iso == p2->y_iso)
		horizontal_line(win, mlx, p1, p2);
	else
		trace_line(win, mlx, p1, p2);
}*/