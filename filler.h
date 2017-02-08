/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:19:25 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/08 11:51:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"

typedef struct  s_coord
{
    int         x;
    int         y;
    int         new_x;
    int         new_y;
}               t_coord;

typedef struct  s_coord_4
{
    int         x;
    int         y;
	short       ok_pick_up;
}               t_coord_4;

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
	char		enemy_shape;
    int         empty_space;
    int         tmp_empty;
    int         nb_player_shape;
    int         tmp_shape;
    int         ok_get_piece;
    int         max_x_piece;
    int         max_y_piece;
	t_coord_4	player_coord[4];
	t_coord_4   enemy_coord[4];
}               t_data;

int			get_next_line(const int fd, char **line);
int         ft_get_input(t_data *data);

void ft_get_coord(t_data *data, t_coord_4 coord[4], char shape);
int ft_get_coord_piece(t_data *data);
int ft_get_best_position(t_data *data);
void ft_display_position(t_data *data, char content);
int ft_get_data(t_data *data);

#endif
