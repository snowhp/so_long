/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/12 16:43:15 by tde-sous         ###   ########.fr       */
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
	size_t		len;/* String lenght size*/
	int		y;/*arr[y][]*/

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
	data->map[y] = 0;
}