/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/09 10:04:51 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_checkmap(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(".ber", (str + i), 4) != 0)
		ft_exit("Wrong extension of the file.", EXIT_FAILURE, &data);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft_exit("Unable to open the map file.", EXIT_FAILURE, &data);
}