/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:23:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/21 11:43:46 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_moveup(t_data *d)
{
	if (d->map[d->p_y - 1][d->p_x] == '1')
		return ;
	if (d->map[d->p_y - 1][d->p_x] == 'C')
	{
		d->nb_col--;
		d->map[d->p_y - 1][d->p_x] = '0';
	}
	if (d->map[d->p_y - 1][d->p_x] == 'E' && d->nb_col == 0)
	{
		ft_printf("Game as finished! Congratulations\n");
		ft_exit(NULL, EXIT_SUCCESS, d);
	}
	if (d->map[d->p_y - 1][d->p_x] != '1')
	{
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->fimg, d->p_x * SIZE, d->p_y * SIZE);
		d->p_y--;
		ft_printf("Moves: %i\n", ++d->moves);
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->pimg, d->p_x * SIZE, d->p_y * SIZE);
	}
}

void	ft_movedown(t_data *d)
{
	if (d->map[d->p_y + 1][d->p_x] == '1')
		return ;
	if (d->map[d->p_y + 1][d->p_x] == 'C')
	{
		d->nb_col--;
		d->map[d->p_y + 1][d->p_x] = '0';
	}
	if (d->map[d->p_y + 1][d->p_x] == 'E' && d->nb_col == 0)
	{
		ft_printf("Game as finished! Congratulations\n");
		ft_exit(NULL, EXIT_SUCCESS, d);
	}
	if (d->map[d->p_y + 1][d->p_x] != '1')
	{
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->fimg, d->p_x * SIZE, d->p_y * SIZE);
		d->p_y++;
		ft_printf("Moves: %i\n", ++d->moves);
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->pimg, d->p_x * SIZE, d->p_y * SIZE);
	}
}

void	ft_moveleft(t_data *d)
{
	if (d->map[d->p_y][d->p_x - 1] == '1')
		return ;
	if (d->map[d->p_y][d->p_x - 1] == 'C')
	{
		d->nb_col--;
		d->map[d->p_y][d->p_x - 1] = '0';
	}
	if (d->map[d->p_y][d->p_x - 1] == 'E' && d->nb_col == 0)
	{
		ft_printf("Game as finished! Congratulations\n");
		ft_exit(NULL, EXIT_SUCCESS, d);
	}
	if (d->map[d->p_y][d->p_x - 1] != '1')
	{
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->fimg, d->p_x * SIZE, d->p_y * SIZE);
		d->p_x--;
		ft_printf("Moves: %i\n", ++d->moves);
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->pimg, d->p_x * SIZE, d->p_y * SIZE);
	}
}

void	ft_moveright(t_data *d)
{
	if (d->map[d->p_y][d->p_x + 1] == '1')
		return ;
	if (d->map[d->p_y][d->p_x + 1] == 'C')
	{
		d->nb_col--;
		d->map[d->p_y][d->p_x + 1] = '0';
	}
	if (d->map[d->p_y][d->p_x + 1] == 'E' && d->nb_col == 0)
	{
		ft_printf("Game as finished! Congratulations\n");
		ft_exit(NULL, EXIT_SUCCESS, d);
	}
	if (d->map[d->p_y][d->p_x + 1] != '1')
	{
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->fimg, d->p_x * SIZE, d->p_y * SIZE);
		d->p_x++;
		ft_printf("Moves: %i\n", ++d->moves);
		mlx_put_image_to_window(d->mlx_ptr, d->mlx_win,
			d->pimg, d->p_x * SIZE, d->p_y * SIZE);
	}
}
