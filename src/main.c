/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:20 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/12 16:08:36 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	main(int	argc, char**	argv)
{
	t_data	data;

	if (argc != 2)
		exit (1);
	ft_init_data(&data);
	ft_checkfile(argv[1], &data);
	ft_loadmap(&data);
	/* Initialize struct*/
}