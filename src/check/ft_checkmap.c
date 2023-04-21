/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/21 14:10:19 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_checkfile(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(".ber", (str + i), 4) != 0)
		ft_exit("Wrong extension of the file", EXIT_FAILURE, data);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft_exit("Unable to open the map file", EXIT_FAILURE, data);
}

void	ft_maxy(t_data *d)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(d->fd);
		if (!temp)
			break ;
		free(temp);
		d->max_y++;
	}
	if (!temp && d->max_y == 0)
		ft_exit("File is empty", EXIT_FAILURE, d);
	free(temp);
	close(d->fd);
}

void	ft_loadmap(char *str, t_data *data)
{
	char	*temp;
	int		y;

	y = 0;
	ft_maxy(data);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft_exit("Unable to open the map file", EXIT_FAILURE, data);
	data->map = (char **)malloc(sizeof(char *) * (data->max_y + 1));
	if (!data->map)
		ft_exit("Failed to allocate memory", EXIT_FAILURE, data);
	y = 0;
	while (1)
	{
		temp = get_next_line(data->fd);
		if (!temp)
			break ;
		data->map[y] = ft_strtrim(temp, "\n");
		free(temp);
		y++;
	}
	close(data->fd);
	data->map[y] = 0;
}

void	ft_checkmap(t_data *d)
{
	int		chare;
	int		x;
	int		y;

	y = 1;
	x = 0;
	chare = 0;
	while (d->map[y] && y < d->max_y)
	{
		if ((x == 0 || x == d->max_x - 1) && d->map[y][x] != '1')
			ft_exit("Missing Vertical Walls", EXIT_FAILURE, d);
		ft_charver(d, x, y, &chare);
		if (d->map[y][++x] == 0)
		{
			x = 0;
			y++;
		}
	}
	if (d->nb_col == 0 || chare != 1 || d->charp != 1)
		ft_exit("Wrong number of C/E/P", EXIT_FAILURE, d);
}

void	ft_charver(t_data *d, int x, int y, int *chare)
{
	if (d->map[y][x] == 'P')
	{
		d->p_y = y;
		d->p_x = x;
		d->charp++;
	}
	else if (d->map[y][x] == 'E')
	{
		d->e_y = y;
		d->e_x = x;
		(*chare)++;
	}
	else if (d->map[y][x] == 'C')
		d->nb_col++;
	else if (d->map[y][x] == '1' || d->map[y][x] == '0')
		return ;
	else
		ft_exit("Unrecognized characters", EXIT_FAILURE, d);
}
