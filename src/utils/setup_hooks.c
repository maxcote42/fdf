/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:39:59 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/11 17:40:01 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_close(t_app *app)
{
	mlx_destroy_window(app->mlx, app->win);
	exit(0);
	return (0);
}

static int	handle_esc(int keycode, t_app *app)
{
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(app->mlx, app->win);
		exit(0);
	}
	else if (keycode == 61)
		app->scale *= 1.1;
	else if (keycode == 45)
		app->scale /= 1.1;
	else if (keycode == 65361)
		app->origin_x -= 20;
	else if (keycode == 65363)
		app->origin_x += 20;
	mlx_destroy_image(app->mlx, app->image.img);
	app->image.img = mlx_new_image(app->mlx, SCREEN_X, SCREEN_Y);
	app->image.addr = mlx_get_data_addr(app->image.img,
			&app->image.bpp, &app->image.line_len, &app->image.endian);
	trace_wireframe(app);
	mlx_put_image_to_window(app->mlx, app->win, app->image.img, 0, 0);
	return (0);
}

void	setup_hooks(t_app *app)
{
	mlx_key_hook(app->win, handle_esc, app);
	mlx_hook(app->win, 17, 0L, handle_close, app);
}
