/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:09:44 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/16 21:12:59 by tde-sous         ###   ########.fr       */
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
	ft_imageload(data, data->cimg, "textures/collectible.xpm");
	ft_imageload(data, data->eimg, "textures/exit.xpm");
	ft_imageload(data, data->fimg, "textures/floor.xpm");
	ft_imageload(data, data->pimg, "textures/players.xpm");
	ft_imageload(data, data->wimg, "textures/wall.xpm");
	mlx_loop(data->mlx_ptr);
}

void	ft_imageload(t_data *data, void *imagep, char *path)
{
	imagep = mlx_xpm_file_to_image(imagep, path, 50, 50);
	if(imagep == NULL)
	{
		ft_exit("Couldn't convert a image.", EXIT_FAILURE, data);
	}
}
