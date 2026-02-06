/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:34:07 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:34:08 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_map(t_point **points, int height)
{
	int	i;

	if (!points)
		return ;
	i = 0;
	while (i < height)
	{
		if (points[i])
			free(points[i]);
		i++;
	}
	free(points);
}
