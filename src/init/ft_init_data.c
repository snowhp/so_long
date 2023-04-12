/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:23:22 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/12 19:29:48 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void  ft_init_data(t_data *data)
{
      data->fd = 0;
      data->map = NULL;
      data->max_y = 0;
      data->max_x = 0;
      data->nb_col = 0;
}
