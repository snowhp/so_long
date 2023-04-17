/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:09:44 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/17 16:34:50 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_initgraph(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit("Failed to initialize window.", EXIT_FAILURE, data);
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->max_x * SIZE, data->max_y * SIZE, "so_long 42" );
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_exit("Failed to create window.", EXIT_FAILURE, data);
	}
	data->cimg = ft_imageload(data, "textures/collectible.xpm");
	data->eimg = ft_imageload(data, "textures/exit.xpm");
	data->fimg = ft_imageload(data, "textures/floor.xpm");
	data->pimg = ft_imageload(data, "textures/player.xpm");
	data->wimg = ft_imageload(data, "textures/wall.xpm");
	ft_loadscreen(data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &ft_keyhandler, data);
	mlx_loop(data->mlx_ptr);
}

void	ft_loadscreen(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while(data->map[y])
	{
		while(data->map[y][x])
		{
			if(data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->cimg, x * SIZE, y * SIZE);
			else if(data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->eimg, x * SIZE, y * SIZE);
			else if(data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fimg, x * SIZE, y * SIZE);
			else if(data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->pimg, x * SIZE, y * SIZE);
			else if(data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->wimg, x * SIZE, y * SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}

void	*ft_imageload(t_data *data, char *path)/* https://github.com/S-LucasSerrano/miniLibX_sample#hooks */
{
	void	*imagep;

	imagep = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size, &data->size);
	if (imagep == NULL) /* Check what happens if a image have a invalid path. had segfault*/
	{
		printf("%s", path);
		ft_exit("Couldn't convert a image.", EXIT_FAILURE, data);
	}
	return (imagep);
}

int	ft_keyhandler(int	keycode, t_data *data)
{
	int		moves;

	moves = 0;
	if (keycode == XK_Escape)
		ft_exit("Game finished by user", EXIT_SUCCESS, data);
	else if ( keycode == XK_w)
		ft_moveup(data);
	else if ( keycode == XK_s)
		ft_movedown(data);
	else if ( keycode == XK_a)
		ft_moveleft(data);
	else if ( keycode == XK_d)
		ft_moveright(data);
	printf("%i", moves++);
	/* ADD OTHER KEYS */
	return (0);
}

void	ft_moveup(t_data *data)
{
	if(data->map[data->p_y + 1][data->p_x] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fimg, data->p_x * SIZE, data->p_y * SIZE);
		data->p_y++;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->cimg, data->p_x * SIZE, data->p_y * SIZE);
	}
}

void	ft_movedown(t_data *data)
{

}

void	ft_moveleft(t_data *data)
{

}

void	ft_moveright(t_data *data)
{

}
