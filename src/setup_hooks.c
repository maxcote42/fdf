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
	mlx_destroy_image(app->mlx, app->image.img);
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free_map(app->map.points, app->map.height);
	exit(0);
	return (0);
}

static int	handle_cmd(int keycode, t_app *app)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(app->mlx, app->image.img);
		mlx_destroy_window(app->mlx, app->win);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		free_map(app->map.points, app->map.height);
		exit(0);
	}
	return (0);
}

void	setup_hooks(t_app *app)
{
	mlx_key_hook(app->win, handle_cmd, app);
	mlx_hook(app->win, 17, 0, handle_close, app);
}
