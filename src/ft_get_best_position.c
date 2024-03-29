/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_best_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:04:11 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:22:14 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_get_coord_piece(t_data *d)
{
	t_coord_piece i;

	i.i = 0;
	i.y = 0;
	i.x = 0;
	if (!(d->coord = (t_coord*)malloc(sizeof(t_coord) * d->nb_coord)))
		return (-1);
	while (i.y < d->xy_piece[0])
	{
		i.x = 0;
		while (i.x < d->xy_piece[1])
		{
			if (d->piece[i.y][i.x] == '*')
			{
				d->coord[i.i].x = i.x;
				d->coord[i.i].y = i.y;
				d->max_x_piece = d->max_x_piece < i.x ? i.x : d->max_x_piece;
				d->max_y_piece = d->max_y_piece < i.y ? i.y : d->max_y_piece;
				i.i++;
			}
			i.x++;
		}
		i.y++;
	}
	return (1);
}

static int	ft_position_foreach(t_data *data, int pos_x, int pos_y)
{
	int		i;
	char	cell;

	i = 0;
	while (i < data->nb_coord)
	{
		data->coord[i].new_x = pos_x + data->coord[i].x;
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

static void	ft_strategy(t_data *data, int pos_x, int pos_y)
{
	if (data->nb_player_shape == 1 && data->empty_space + 1 == data->nb_coord)
	{
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
			data->move.ok_right_up = 1;
		}
		if (pos_x <= data->move.left_down_x)
		{
			data->move.left_down_x = pos_x;
			data->move.left_down_y = pos_y;
			data->move.ok_left_down = 1;
		}
		data->move.right_down_x = pos_x;
		data->move.right_down_y = pos_y;
	}
}

static void	ft_init_move(t_data *data)
{
	data->move.left_up_x = 0;
	data->move.left_up_y = 0;
	data->move.right_up_x = 0;
	data->move.right_up_y = 0;
	data->move.ok_right_up = 0;
	data->move.left_down_x = data->xy_plateau[1];
	data->move.left_down_y = 0;
	data->move.ok_left_down = 0;
	data->move.right_down_x = 0;
	data->move.right_down_y = 0;
	data->move.ok_left_up = 0;
	data->max_x_piece = 0;
	data->max_y_piece = 0;
}

void		ft_get_best_position(t_data *data)
{
	int pos_x;
	int pos_y;

	pos_x = 0;
	pos_y = 0;
	ft_init_move(data);
	ft_get_coord_piece(data);
	while (pos_y < data->xy_plateau[0] - data->max_y_piece)
	{
		pos_x = 0;
		while (pos_x < data->xy_plateau[1] - data->max_x_piece)
		{
			if (pos_y < data->xy_plateau[0] - data->max_y_piece)
			{
				data->empty_space = 0;
				data->nb_player_shape = 0;
				data->tmp_shape = 0;
				ft_position_foreach(data, pos_x, pos_y);
				ft_strategy(data, pos_x, pos_y);
			}
			pos_x++;
		}
		pos_y++;
	}
	ft_choose_direction(data);
}
