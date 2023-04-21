/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifications.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:40:21 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/21 12:44:32 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_mapformat(t_data *d)
{
	int		x;

	x = 0;
	d->max_x = (int)ft_strlen(d->map[x]);
	while (d->map[++x])
		if (d->max_x != (int)ft_strlen(d->map[x]))
			ft_exit("Map lines have different sizes", EXIT_FAILURE, d);
	x = 0;
	while (d->map[0][x])
		if (d->map[0][x++] != '1')
			ft_exit("The first line is not a wall", EXIT_FAILURE, d);
	if (d->max_x < 3 || d->max_y < 3)
		ft_exit("Not enough width and height.", EXIT_FAILURE, d);
	if (ft_memcmp(d->map[0], d->map[(d->max_y - 1)], sizeof(d->map[0] != 0)))
		ft_exit("The last line is not a wall", EXIT_FAILURE, d);
}
