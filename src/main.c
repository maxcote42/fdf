/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:35:46 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:35:47 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_variables(t_app *app)
{
	double	radiant;
	
	radiant = 30.0 * M_PI / 180.0;
	app->cos_radiant = cos(radiant);
	app->sin_radiant = sin(radiant);
	app->scale = 10;
	app->origin_x = SCREEN_X / 2;
	app->origin_y = SCREEN_Y / 2;
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		return (1);
	if (parse_map(argv[1], &app.map) == 1)
		return (1);
	init_variables(&app);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, SCREEN_X, SCREEN_Y, "fdf");
	app.image.img = mlx_new_image(app.mlx, SCREEN_X, SCREEN_Y);
	app.image.addr = mlx_get_data_addr(app.image.img,
			&app.image.bpp, &app.image.line_len, &app.image.endian);
	trace_wireframe(&app);
	setup_hooks(&app);
	mlx_loop(app.mlx);
	free_map(app.map.points, app.map.height);
	return (0);
}