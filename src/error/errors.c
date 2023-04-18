/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:31:38 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 10:59:12 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_exit(char	*str, int i, t_data *data)
{
	int		y;

	/* free anymemory */
	y = 0;
	if (data->map)
	{
		while (data->map[y])
		{
			free(data->map[y]);
			y++;
		}
		free(data->map[y]);
		free(data->map);
	}
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (i == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	ft_printf("Error\n%s", str);
	exit(EXIT_FAILURE);
}
