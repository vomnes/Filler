/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:19:25 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/08 19:14:13 by vomnes           ###   ########.fr       */
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

typedef struct	s_centroid
{
	int			x_1;
	int			y_1;
	int			x_2;
	int			y_2;
	int			x;
	int			y;
}				t_centroid;

typedef struct	s_move
{
	int			left_up_x;
	int         left_up_y;
	int			ok_left_up;
	int			right_up_x;
	int			right_up_y;
	int			left_down_x;
	int			left_down_y;
	int			right_down_x;
	int			right_down_y;
}				t_move;

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
	t_centroid	player_centroid;
	t_centroid  enemy_centroid;
	int			centroid_x;
	int			centroid_y;
	t_move		move; 
}               t_data;

int			get_next_line(const int fd, char **line);
int         ft_get_input(t_data *data);

void ft_global_centroid(t_data *data);
void ft_get_best_position(t_data *data);
void ft_display_position(t_data *data, char content);
int ft_get_data(t_data *data);

#endif
