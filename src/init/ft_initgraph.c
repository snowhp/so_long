/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:09:44 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/14 16:52:43 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_initgraph(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit("Failed to initialize window.", EXIT_FAILURE, data);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->max_y * SIZE, data->max_y * SIZE, "so_long 42" );
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_exit("Failed to create window.", EXIT_FAILURE, data);
	}
	mlx_loop(data->mlx_ptr);
}
