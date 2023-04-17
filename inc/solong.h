/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:23 by tde-sous          #+#    #+#             */
/*   Updated: 2023/04/17 11:29:34 by tde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define SIZE 50

/**
 * @brief Data structure containing all data of the game
 * @param fd FileDescriptor for map (.ber extension) file
 */
typedef struct s_data
{
	int		fd;
	char**	map;
	int		max_y;/* For a 5 line file this value will be 5, and acessible by map[]*/
	int		max_x;
	int		p_y;
	int		p_x;
	int		nb_col;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*cimg;
	void	*eimg;
	void	*fimg;
	void	*pimg;
	void	*wimg;
	int		size;
}	t_data;

/**
 * @brief Given a str, this function will check if the map have a .ber
 * extension, if the file is possible to be open.
 *
 * @param str Map file
 * @return This function does not return
 */
void	ft_checkfile(char *str, t_data *data);

/**
 * @brief Exit properly with a error message and error code.
 *
 * @param str Custom error message: "Error\\n str"
 * @param i Error code
 * @return This function does not return
 */
void	ft_exit(char	*str, int i, t_data *data);

/**
 * @brief Initialize struct values.
 */
void  ft_init_data(t_data *data);
void	ft_loadmap(char *str, t_data *data);
void ft_checkmap(t_data *data);
void	ft_mapflood(t_data *data);
char **ft_flood(t_data *data, char **maptemp, int p_y , int p_x, int *ne, int *nc);
void	ft_printarray(char **arr, t_data *data);
void	ft_initgraph(t_data *data);
void	*ft_imageload(t_data *data, char *path);
int		ft_keyhandler(int	keycode, t_data *data);
void	ft_loadscreen(t_data *data);

#endif
