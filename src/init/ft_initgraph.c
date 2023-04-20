/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:09:44 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 15:20:43 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_initgraph(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		ft_exit("Failed to initialize window.", EXIT_FAILURE, d);
	d->mlx_win = mlx_new_window(d->mlx_ptr, d->max_x * SIZE,
			d->max_y * SIZE, "so_long 42" );
	if (!d->mlx_win)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		ft_exit("Failed to create window.", EXIT_FAILURE, d);
	}
	d->cimg = ft_imageload(d, "textures/collectible.xpm");
	d->eimg = ft_imageload(d, "textures/exit.xpm");
	d->fimg = ft_imageload(d, "textures/floor.xpm");
	d->pimg = ft_imageload(d, "textures/player.xpm");
	d->wimg = ft_imageload(d, "textures/wall.xpm");
	ft_loadscreen(d);
	mlx_hook(d->mlx_win, KeyPress, KeyPressMask, &ft_keyhandler, d);
	mlx_hook(d->mlx_win, DestroyNotify, StructureNotifyMask, &ft_esc, d);
	mlx_loop(d->mlx_ptr);
}

void	ft_loadscreen(t_data *d)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (d->map[y])
	{
		while (d->map[y][x])
		{
			if (d->map[y][x] == 'C')
				mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
					d->cimg, x * SIZE, y * SIZE);
			else if (d->map[y][x] == 'E')
				mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
					d->eimg, x * SIZE, y * SIZE);
			else if (d->map[y][x] == '0')
				mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
					d->fimg, x * SIZE, y * SIZE);
			else if (d->map[y][x] == 'P')
				mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
					d->pimg, x * SIZE, y * SIZE);
			else if (d->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
					d->wimg, x * SIZE, y * SIZE);
			x++;
		}
		x = 0;
		y++;
	}
}

void	*ft_imageload(t_data *d, char *path)
{
	void	*imagep;

	imagep = mlx_xpm_file_to_image(d->mlx_ptr, path, &d->size, &d->size);
	if (imagep == NULL)
		ft_exit("Couldn't convert a image.", EXIT_FAILURE, d);
	return (imagep);
}

int		ft_keyhandler(int keycode, t_data *d)
{
	if (keycode == XK_Escape)
		ft_exit(NULL, EXIT_SUCCESS, d);
	else if (keycode == XK_w)
		ft_moveup(d);
	else if (keycode == XK_s)
		ft_movedown(d);
	else if (keycode == XK_a)
		ft_moveleft(d);
	else if (keycode == XK_d)
		ft_moveright(d);
	if (d->pwexit == 1 && (d->p_x != d->e_x || d->p_y != d->e_y))
	{
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->eimg, d->e_x * SIZE, d->e_y * SIZE);
		d->pwexit = 0;
	}
	if (d->e_x == d->p_x && d->e_y == d->p_y && d->nb_col > 0)
		d->pwexit = 1;
	return (0);
}

