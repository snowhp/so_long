/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/12 20:04:08 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	ft_checkfile(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(".ber", (str + i), 4) != 0)
		ft_exit("Wrong extension of the file.", EXIT_FAILURE, data);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft_exit("Unable to open the map file.", EXIT_FAILURE, data);
}

void	ft_loadmap(t_data *data)
{
	char*		temp;
	int		y;

	data->map = (char**)malloc(sizeof(char**));
	if(!data->map)
		ft_exit("Failed to allocate memory.", EXIT_FAILURE, data);
	y = 0;
	while((temp = get_next_line(data->fd)))
	{
		data->map[y++] = ft_strtrim(temp, "\n");
		free(temp);
		printf("%s\n", data->map[y-1]);// show the map
	}
	data->max_y = y - 1;
	data->map[y] = 0;
}

void ft_checkmap(t_data *data)
{
	size_t		size;
	int		x;
	int		y;
	int		charE;
	int		charP;

	/* Line size*/
	x = 0;
	size = ft_strlen(data->map[x]);
	data->max_x = (int) size;
	while(data->map[++x])
	{
		if (size != ft_strlen(data->map[x]))
			ft_exit("Map lines have different sizes", EXIT_FAILURE, data);
	}
	/* Borders */
	x = 0;
	while (data->map[0][x])
	{
		if (data->map[0][x++] != '1')
			ft_exit("The first line is not a wall", EXIT_FAILURE, data);
	}
	if (ft_memcmp(data->map[0], data->map[data->max_y], sizeof(data->map[0])) != 0)
		ft_exit("The last line is not a wall", EXIT_FAILURE, data);
	/* Check content and forbiden things*/
	y = 1;
	x = 0;
	while (data->map[y][x] && y < data->max_y)
	{
		if((x == 0 || y == data->max_y) && data->map[y][x] != '1')
			ft_exit("Unrecognized characters in your map file. Vertical Walls", EXIT_FAILURE, data);
		if (data->map[y][x] == 'P')
			charP++;
		else if (data->map[y][x] == 'E')
			charE++;
		else if(data->map[y][x] == 'C')
			data->nb_col++;
		else if (data->map[y][x] == '1' || data->map[y][x] == '0')
		{
		}
		else
			ft_exit("Unrecognized characters in your map file.", EXIT_FAILURE, data);
		if(data->map[y][++x] == 0)
		{
			x = 0;
			y++;
		}
	}
}
