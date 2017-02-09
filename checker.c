/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:32:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/09 11:43:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

static int ft_get_coord_piece(t_data *d)
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
//		dprintf(2, "pos_x -> %d | pos_y -> %d | nb_player_shape = %d | empty_space = %d\n",
//				pos_x, pos_y, data->nb_player_shape, data->empty_space);
        if (data->move.ok_left_up == 0)
        {
            data->move.left_up_x = pos_x;
            data->move.left_up_y = pos_y;
            data->move.ok_left_up = 1;
        }
        if (pos_x > data->move.right_up_x)
        {
            data->move.right_up_x = pos_x;
            data->move.right_up_y = pos_y;
        }
        if (pos_x <= data->move.left_down_x)
        {
            data->move.left_down_x = pos_x;
            data->move.left_down_y = pos_y;
        }
        data->move.right_down_x = pos_x;
        data->move.right_down_y = pos_y;
    }
}

static int ft_positions(t_data *data, int pos_x, int pos_y)
{
    data->empty_space = 0;
    data->nb_player_shape = 0;
    data->tmp_shape = 0;
    ft_position_foreach(data, pos_x, pos_y);
    ft_strategy(data, pos_x, pos_y);
    return (1);
}

static int ft_choose_direction(t_data *data)
{
	int x0;
	int y0;
	int x1;
	int y1;

	x0 = data->player_centroid.x;
	y0 = data->player_centroid.y;
	x1 = data->enemy_centroid.x;
	y1 = data->enemy_centroid.y;
	if (x1 == x0 && y1 < y0) // Up
	{
		ft_putendl_fd("UP", 2);
	}
	if (x1 > x0 && y1 < y0) //Up right
	{
		data->final_x = data->move.right_down_x;
		data->final_y = data->move.right_down_y;
		ft_putendl_fd("DOWN R", 2);
		return (1);
	}
	if (x1 > x0 && y1 == y0) // Right
	{
		ft_putendl_fd("RIGHT", 2);
	}
	if (x1 > x0 && y1 > y0) //Down right
	{
		data->final_x = data->move.right_up_x;
		data->final_y = data->move.right_up_y;
		ft_putendl_fd("UP R", 2);
		return (1);
	}
	if (x1 == x0 && y1 > y0) // Down
	{
		ft_putendl_fd("DOWN", 2);
	}
	if (x1 < x0 && y1 > y0) //Down left
	{
		data->final_x = data->move.left_up_x;
		data->final_y = data->move.left_up_y;
		ft_putendl_fd("UP L", 2);
		return (1);
	}
	if (x1 < x0 && y1 == y0) // Left
	{
		ft_putendl_fd("LEFT", 2);
	}
	if (x1 < x0 && y1 < y0)//Up left
	{
		data->final_x = data->move.left_down_x;
		data->final_y = data->move.left_down_y;
		ft_putendl_fd("DOWN L", 2);
		return (1);
	}
	data->final_x = data->move.left_up_x;
	data->final_y = data->move.left_up_y;
	data->final_x = data->move.right_up_x;
	data->final_y = data->move.right_up_y;
	data->final_x = data->move.left_down_x;
	data->final_y = data->move.left_down_y;
	data->final_x = data->move.right_down_x;
	data->final_y = data->move.right_down_y;
	return (0);
}

void ft_get_best_position(t_data *data)
{
    int pos_x;
    int pos_y;

    pos_x = 0;
    pos_y = 0;
	data->move.left_up_x = 0;
    data->move.left_up_y = 0;
    data->move.right_up_x = 0;
    data->move.right_up_y = 0;
    data->move.left_down_x = data->xy_plateau[1];
    data->move.left_down_y = 0;
    data->move.right_down_x = 0;
    data->move.right_down_y = 0;
	data->move.ok_left_up = 0;
	ft_get_coord_piece(data);
	ft_global_pos(&data->player_pos, data->player_centroid, data);
	ft_global_pos(&data->enemy_pos, data->enemy_centroid, data);
	dprintf(2, "data->player_pos.x = %2d | data->player_pos.y = %2d\n", data->player_pos.x, data->player_pos.y);
	dprintf(2, "data->enemy_pos.x  = %2d | data->enemy_pos.y  = %2d\n", data->enemy_pos.x, data->enemy_pos.y);
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
/*	dprintf(2, "data->move.left_up_x : %d - data->move.left_up_y : %d\n", data->move.left_up_x, data->move.left_up_y);
	dprintf(2, "data->move.right_up_x : %d - data->move.right_up_y : %d\n", data->move.right_up_x, data->move.right_up_y);
	dprintf(2, "data->move.left_down_x : %d - data->move.left_down_y : %d\n", data->move.left_down_x, data->move.left_down_y);
	dprintf(2, "data->move.right_down_x : %d - data->move.right_down_y : %d\n", data->move.right_down_x, data->move.right_down_y);*/
	ft_choose_direction(data);
}

void ft_display_position(t_data *data, char content)
{
    int i;

    i = 0;
    while (i < data->nb_coord)
    {
        data->coord[i].new_x = data->final_x + data->coord[i].x,
        data->coord[i].new_y = data->final_y + data->coord[i].y;
        data->plateau[data->coord[i].new_y][data->coord[i].new_x] = content;
        i++;
    }
}
