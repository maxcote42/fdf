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
	t_map	map;

	if (argc != 2)
		return (1);
	if (parse_map(argv[1], &map) == 0)
		return (1);
	// Affichage altitude
	unsigned int	x, y;
	ft_printf("=== Altitude Map ===\n");
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			ft_printf("%4d ", map.points[y][x].z);
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
			ft_printf("%#08x ", map.points[y][x].color);
			x++;
		}
		ft_printf("\n");
		y++;
	}

	return (0);
}

