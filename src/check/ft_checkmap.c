/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:04:00 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/09 09:33:02 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void    ft_checkmap(char *str)
{
    int	i;

    i = ft_strlen(str) - 4;
	if (ft_strncmp(".ber", (str + i), 4) != 0)
		ft_exit("Wrong extension of the file.", EXIT_FAILURE);
	if (open(str, O_RDONLY, 0444) == -1)
		ft_exit("Unable to open the map file.", EXIT_FAILURE );
}

int	main()
{
	ft_checkmap("asdasd.map.ber");
	ft_checkmap("mapbeasdr");
	ft_checkmap("map.bas.der");
	ft_checkmap("map..be.ra");
	return 0;
}