/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapflood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:26:35 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/21 12:44:06 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_mapflood(t_data *data)
{
	int		ne;
	int		nc;

	nc = data->nb_col;
	ne = 1;
	ft_flood(data, data->p_y, data->p_x, &ne);
	if (data->nb_col != 0 || ne != 0)
		ft_exit("No valid path", EXIT_FAILURE, data);
	data->nb_col = nc;
}

char	**ft_flood(t_data *d, int p_y, int p_x, int *ne)
{
	if (d->map[p_y][p_x] == '1')
		return (d->map);
	else if (d->map[p_y][p_x] == 'X')
	{
	}
	else
	{
		if (d->map[p_y][p_x] == 'E')
			(*ne)--;
		else if (d->map[p_y][p_x] == 'C')
			d->nb_col--;
		d->map[p_y][p_x] = 'X';
		ft_flood(d, (p_y + 1), p_x, ne);
		ft_flood(d, (p_y - 1), p_x, ne);
		ft_flood(d, p_y, (p_x + 1), ne);
		ft_flood(d, p_y, (p_x - 1), ne);
		return (d->map);
	}
	return (d->map);
}
