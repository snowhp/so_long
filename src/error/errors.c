/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:31:38 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/19 15:27:40 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_exit(char	*str, int i, t_data *data)
{
	int		y;

	y = 0;
	if (data->map)
	{
		while (data->map[y])
			free(data->map[y++]);
		free(data->map[y]);
		free(data->map);
	}
	ft_destroyimg(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (i == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	ft_printf("Error\n%s", str);
	exit(EXIT_FAILURE);
}

void	ft_destroyimg(t_data *data)
{
	if (data->cimg)
		mlx_destroy_image(data->mlx_ptr, data->cimg);
	if (data->eimg)
		mlx_destroy_image(data->mlx_ptr, data->eimg);
	if (data->fimg)
		mlx_destroy_image(data->mlx_ptr, data->fimg);
	if (data->pimg)
		mlx_destroy_image(data->mlx_ptr, data->pimg);
	if (data->wimg)
		mlx_destroy_image(data->mlx_ptr, data->wimg);
}


int		ft_esc(t_data *data)
{
	ft_exit(NULL, EXIT_SUCCESS, data);
	return (0);
}
