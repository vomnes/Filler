/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:32:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/08 09:33:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int ft_get_coord_piece(t_data *d)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    d->max_x_piece = 0;
    d->max_y_piece = 0;
    if (!(d->coord = (t_coord*)malloc(sizeof(t_coord) * d->nb_coord)))
        return (-1);
    while (y < d->xy_piece[0])
    {
        x = 0;
        while (x < d->xy_piece[1])
        {
            if (d->piece[y][x] == '*')
            {
                d->coord[i].x = x;
                d->coord[i].y = y;
                d->max_x_piece = d->max_x_piece < x ? x : d->max_x_piece;
                d->max_y_piece = d->max_y_piece < y ? y : d->max_y_piece;
                i++;
            }
            x++;
        }
        y++;
    }
    return (1);
}

static int ft_position_foreach(t_data *data, int pos_x, int pos_y)
{
    int i;
    char cell;

    i = 0;
    while (i < data->nb_coord)
    {
        data->coord[i].new_x = pos_x + data->coord[i].x,
        data->coord[i].new_y = pos_y + data->coord[i].y;
        cell = data->plateau[data->coord[i].new_y][data->coord[i].new_x];
        if (cell == '.')
            data->empty_space++;
        else if (cell == data->player_shape)
            data->nb_player_shape++;
        i++;
    }
    return (1);
}

static void ft_strategy(t_data *data, int pos_x, int pos_y)
{
    if (data->nb_player_shape == 1 && data->empty_space + 1 == data->nb_coord)
    {
        if (data->empty_space > data->tmp_empty)
        {
            data->final_pos_x = pos_x;
            data->final_pos_y = pos_y;
        }
    }
}

static int ft_positions(t_data *data, int pos_x, int pos_y)
{
    data->empty_space = 0;
    data->nb_player_shape = 0;
    data->tmp_empty = 0;
    data->tmp_shape = 0;
    ft_position_foreach(data, pos_x, pos_y);
    ft_strategy(data, pos_x, pos_y);
    return (1);
}

int ft_get_best_position(t_data *data)
{
    int pos_x;
    int pos_y;

    pos_x = 0;
    pos_y = 0;
    while (pos_y < data->xy_plateau[0] - data->max_y_piece)
    {
        pos_x = 0;
        while (pos_x < data->xy_plateau[1] - data->max_x_piece)
        {
            if (pos_y < data->xy_plateau[0] - data->max_y_piece)
                ft_positions(data, pos_x, pos_y);
            pos_x++;
        }
        pos_y++;
    }
    return (1);
}

void ft_display_position(t_data *data, char content)
{
    int i;

    i = 0;
    while (i < data->nb_coord)
    {
        data->coord[i].new_x = data->final_pos_x + data->coord[i].x,
        data->coord[i].new_y = data->final_pos_y + data->coord[i].y;
        data->plateau[data->coord[i].new_y][data->coord[i].new_x] = content;
        i++;
    }
}
