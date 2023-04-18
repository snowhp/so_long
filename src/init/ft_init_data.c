/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:23:22 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 10:03:57 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_init_data(t_data *data)
{
	data->fd = 0;
	data->map = 0;
	data->max_y = 0;
	data->max_x = 0;
	data->p_y = 0;
	data->p_x = 0;
	data->moves = 0;
	data->nb_col = 0;
	data->cimg = 0;
	data->eimg = 0;
	data->fimg = 0;
	data->pimg = 0;
	data->wimg = 0;
	data->size = SIZE;
}
