/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:20 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/12 17:33:26 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	main(int	argc, char**	argv)
{
	t_data	data;

	if (argc != 2)
		ft_exit("Usage: ./so_long MAP_PATH", EXIT_FAILURE, &data);
	ft_init_data(&data);
	ft_checkfile(argv[1], &data);
	ft_loadmap(&data);
	ft_checkmap(&data);
	/* Initialize struct*/
}
