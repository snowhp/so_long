/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:31:38 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/13 15:21:49 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"


void	ft_exit(char	*str, int i, t_data *data)
{
	int		y;

	/* free anymemory */
	close(data->fd);/* Should be close after no longer needed prob ft_checkmap.c*/
	y = 0;
	while (data->map[y])
		free(data->map[y++]);
	if (data->map)
		free(data->map);
	if (i == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	ft_printf("Error\n%s", str);
	exit(EXIT_FAILURE);
}
