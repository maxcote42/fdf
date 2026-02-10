/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:59:37 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/09 11:59:40 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// represente le step de color pour passer de p1 a p2
float	step_color(t_point *p1, t_point *p2)
{
	int	count_pixel;
	int	dcolor;
	float	step;

	count_pixel = ft_fraction(p1, p2);
	dcolor = p2->color - p1->color;
	if (count_pixel == 0)
		return (0);
	step = (dcolor / count_pixel);
	return (step);
}
