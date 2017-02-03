/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:32:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/03 15:32:29 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

int ft_get_coord_piece(t_data *data)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    if (!(data->coord = (t_coord*)malloc(sizeof(t_coord) * data->nb_coord)))
        return (-1);
    while (data->piece[y])
    {
        x = 0;
        while (data->piece[y][x])
        {
            if (data->piece[y][x] == '*')
            {
                data->coord[i].x = x;
                data->coord[i].y = y;
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
        if (pos_x + data->coord[i].x < 0 || pos_y + data->coord[i].y < 0)
            return (-1);
        if (pos_x + data->coord[i].x > data->xy_plateau[1] ||
            pos_y + data->coord[i].y > data->xy_plateau[0])
            return (-1);
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
    if (data->nb_player_shape > 0)
    {
        if (data->empty_space > data->tmp_empty &&
        data->nb_player_shape > data->tmp_shape)
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
    if(!ft_position_foreach(data, pos_x, pos_y))
        return (-1);
    ft_strategy(data, pos_x, pos_y);
    return (1);
}

//ft_printf("$[%d] > %2d - %2d\n", i, data->coord[i].new_x, data->coord[i].new_y);

//        ft_printf("> pos_x : %2d | pos_y : %2d | ", pos_x, pos_y);
//        ft_printf("empty_space >> %d - nb_player_shape >> %d\n",
//        data->empty_space, data->nb_player_shape);

int ft_get_best_position(t_data *data)
{
    int pos_x;
    int pos_y;

    pos_x = 0;
    pos_y = data->min_y - data->xy_piece[0] + 1;
    while (pos_x != data->xy_plateau[1] && pos_y != data->xy_plateau[0])
    {
        pos_x = 0;
        while (pos_x <= data->xy_plateau[1] - data->xy_piece[1])
        {
            if (pos_y < data->xy_plateau[0] - data->xy_piece[0] + 1)
                if (!ft_positions(data, pos_x, pos_y))
                    return (-1);
            pos_x++;
        }
        pos_y++;
    }
//    ft_printf(">>%d<< >>%d<<\n", data->final_pos_x, data->final_pos_y);
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
