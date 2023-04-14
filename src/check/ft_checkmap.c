/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/14 01:09:09 by tde-sous         ###   ########.fr       */
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

void	ft_loadmap(char *str, t_data *data)
{
	char*		temp;
	int		y;

	y = 0;
	while (1)
	{
		temp = get_next_line(data->fd);
		if (!temp)
			break ;
		free(temp);
		data->max_y++;
	}
	if(!temp && data->max_y == 0)
		ft_exit("File is empty.", EXIT_FAILURE, data);
	free(temp);
	close(data->fd);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft_exit("Unable to open the map file.", EXIT_FAILURE, data);
	data->map = (char**)malloc(sizeof(char*) * (data->max_y + 1));
	if(!data->map)
		ft_exit("Failed to allocate memory.", EXIT_FAILURE, data);
	y = 0;
	while(y <= data->max_y)
	{
		temp = get_next_line(data->fd);
		if(!temp)
			break ;
		data->map[y] = ft_strtrim(temp, "\n");
		free(temp);
		y++;
		//printf("%s\n", data->map[y-1]);// show the map
	}
	free(temp);
	data->map[y] = 0;
}

void ft_checkmap(t_data *data)
{
	size_t		size;
	int		x;
	int		y;
	unsigned int		charE;
	unsigned int		charP;

	/* Line size*/
	x = 0;
	charE = 0;
	charP = 0;
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
	if (ft_memcmp(data->map[0], data->map[(data->max_y - 1)], sizeof(data->map[0] != 0)))
		ft_exit("The last line is not a wall", EXIT_FAILURE, data);
	/* Check content and forbiden things*/
	y = 1;
	x = 0;
	while (data->map[y] && y < data->max_y)
	{
		if((x == 0 || x == data->max_x - 1) && data->map[y][x] != '1')
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
		if(charP > 1 || charE > 1)
			ft_exit("Too many Player's or Exit's", EXIT_FAILURE, data);
		if(data->map[y][++x] == 0)
		{
			x = 0;
			y++;
		}
	}
	if(data->nb_col == 0 || charE == 0 || charP == 0)
		ft_exit("Not characters enough on the map", EXIT_FAILURE, data);
	/* ft_flood */
}
