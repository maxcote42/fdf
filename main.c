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


int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		return (1);

	if (parse_map(argv[1], &app.map) == 1)
		return (1);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, SCREEN_X, SCREEN_Y, "fdf");
	app.image.img = mlx_new_image(app.mlx, SCREEN_X, SCREEN_Y);
	app.image.addr = mlx_get_data_addr(app.image.img, &app.image.bpp,
					&app.image.line_len, &app.image.endian);
	trace_wireframe(&app);
	mlx_put_image_to_window(app.mlx, app.win, app.image.img, 0, 0);

	// mlx_hook a faire pour fermer 
	mlx_loop(app.mlx);
	free_map(app.map.points, app.map.height);
	return (0);
}


/*
// TEST PARSING
	// Affichage altitude
	unsigned int	x, y;
	ft_printf("=== Altitude Map ===\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			ft_printf("%d ", map.points[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}

	// Affichage couleur
	ft_printf("\n=== Color Map ===\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			ft_printf("%x ", map.points[y][x].color);
			x++;
		}
		ft_printf("\n");
		y++;
	}

// Affichage ISO MAP (coordonnées x_iso, y_iso)
	printf("\n=== ISO MAP ===\n");
	convert_scale(&map); // applique conversion iso
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			printf("(%0.f,%0.f) ", map.points[y][x].x_iso, map.points[y][x].y_iso);
			x++;
		}
		printf("\n");
		y++;
	}
*/