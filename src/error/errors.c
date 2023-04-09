/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 09:31:38 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/09 10:01:35 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"


void	ft_exit(char	*str, int i, t_data *data)
{
	if (i == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	else
		ft_printf("Errorn\n %s", str);
	/* free anymemory */
	close(data->fd);
}
