/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/19 11:45:14 by tde-sous         ###   ########.fr       */
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

void	ft_loadmap(char *str, t_data *data)
{
	char	*temp;
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
	if (!temp && data->max_y == 0)
		ft_exit("File is empty", EXIT_FAILURE, data);
	free(temp);
	close(data->fd);
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

void	ft_checkmap(t_data *data)
{
	size_t	size;
	int		x;
	int		y;
	unsigned int	charE;
	unsigned int	charP;

	x = 0;
	charE = 0;
	charP = 0;
	size = ft_strlen(data->map[x]);
	data->max_x = (int) size;
	while (data->map[++x])
	{
		if (size != ft_strlen(data->map[x]))
			ft_exit("Map lines have different sizes", EXIT_FAILURE, data);
	}
	x = 0;
	while (data->map[0][x])
	{
		if (data->map[0][x++] != '1')
			ft_exit("The first line is not a wall", EXIT_FAILURE, data);
	}
	if (data->max_x < 3 || data->max_y < 3)
		ft_exit("Not enough width and height.", EXIT_FAILURE, data);
	if (ft_memcmp(data->map[0], data->map[(data->max_y - 1)], sizeof(data->map[0] != 0)))
		ft_exit("The last line is not a wall", EXIT_FAILURE, data);
	y = 1;
	x = 0;
	while (data->map[y] && y < data->max_y)
	{
		if ((x == 0 || x == data->max_x - 1) && data->map[y][x] != '1')
			ft_exit("Unrecognized characters in your map file. Vertical Walls", EXIT_FAILURE, data);
		if (data->map[y][x] == 'P')
		{
			data->p_y = y;
			data->p_x = x;
			charP++;
		}
		else if (data->map[y][x] == 'E')
		{
			data->e_y = y;
			data->e_x = x;
			charE++;
		}
		else if (data->map[y][x] == 'C')
			data->nb_col++;
		else if (data->map[y][x] == '1' || data->map[y][x] == '0')
		{
		}
		else
			ft_exit("Unrecognized characters in your map file", EXIT_FAILURE, data);
		if (charP > 1 || charE > 1)
			ft_exit("Too many Player's or Exit's", EXIT_FAILURE, data);
		if (data->map[y][++x] == 0)
		{
			x = 0;
			y++;
		}
	}
	if (data->nb_col == 0 || charE == 0 || charP == 0)
		ft_exit("Not characters enough on the map", EXIT_FAILURE, data);
	ft_mapflood(data);
}

void	ft_mapflood(t_data *data)
{
	int		ne;
	int		nc;
	char	**maptemp;

	nc = data->nb_col;
	ne = 1;
	maptemp = data->map;
	ft_flood(data, maptemp, (data->p_y), data->p_x, &ne, &nc);
	if (nc != 0 || ne != 0)
		ft_exit("A valid path for the player doesn't exist", EXIT_FAILURE, data);
}

char	**ft_flood(t_data *data, char **m, int p_y , int p_x, int *ne, int *nc)
{
	if (m[p_y][p_x] == '1')
		return (m);
	else if (m[p_y][p_x] == 'X')
	{
	}
	else
	{
		if (m[p_y][p_x] == 'E')
			(*ne)--;
		else if (m[p_y][p_x] == 'C')
			(*nc)--;
		m[p_y][p_x] = 'X';
		ft_flood(data, m, (p_y + 1) , p_x, ne, nc);
		ft_flood(data, m, (p_y - 1) , p_x, ne, nc);
		ft_flood(data, m, p_y, (p_x + 1), ne, nc);
		ft_flood(data, m, p_y, (p_x - 1), ne, nc);
		return (m);
	}
	return (m);
}

void	ft_printarray(char **arr, t_data *data)
{
	int	y = 0;
	int	x = 0;

	while (arr[y] && y < data->max_y)
	{
		printf("%c", arr[y][x]);
		if (arr[y][++x] == 0)
		{
			printf("\n");
			x = 0;
			y++;
		}
	}
}

