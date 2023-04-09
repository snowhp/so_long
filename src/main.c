/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:20 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/09 09:59:29 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/solong.h"

int	main(int	argc, char**	argv)
{
	t_data	data;

	if (argc != 2)
		exit (1);
	ft_checkmap(argv[1], &data);
	/* Initialize struct*/
}