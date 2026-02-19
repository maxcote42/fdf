/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxcote <maxcote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 12:34:26 by maxcote           #+#    #+#             */
/*   Updated: 2026/02/06 12:34:27 by maxcote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(char *hex)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i += 2;
	while (hex[i])
	{
		count = count * 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			count += hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			count += hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			count += hex[i] - 'a' + 10;
		i++;
	}
	return (count);
}
