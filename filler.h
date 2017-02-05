/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:19:25 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/02 15:19:27 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 48
# define NB_MAX_FD 4864

typedef struct  s_coord
{
    int         x;
    int         y;
    int         new_x;
    int         new_y;
}               t_coord;

typedef struct  s_data
{
    int         xy_plateau[2];
    int         xy_piece[2];
    char        **plateau;
    char        **piece;
    int         num_player;
    int         nb_coord;
    int         min_y;
    int         ok_min_y;
    t_coord     *coord;
    int         final_pos_x;
    int         final_pos_y;
    char        player_shape;
    int         empty_space;
    int         tmp_empty;
    int         nb_player_shape;
    int         tmp_shape;
}               t_data;

int			get_next_line(const int fd, char **line);
int         ft_get_input(t_data *data);

int ft_get_coord_piece(t_data *data);
int ft_get_best_position(t_data *data);
void ft_display_position(t_data *data, char content);
int ft_get_data(t_data *data);

#endif
