/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:33:57 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/09 11:33:58 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
// represente le nombre de pixel entre deux points
// utile si gradient
int	ft_fraction(t_point p1, t_point p2)
{
	int dx;
	int	dy;

	dx = p2.x_iso - p1.x_iso;
	dy = p2.y_iso - p1.y_iso;
	if (abs(dx) > abs(dy))
		return (abs(dx));
	else
		return (abs(dy));
}
