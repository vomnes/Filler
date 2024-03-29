/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:16:11 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/14 12:06:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_init_coord(t_coord_4 coord[4], t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		coord[i].x = -1;
		coord[i].y = -1;
		coord[i].ok_pick_up = 0;
		i++;
	}
	coord[2].x = data->xy_plateau[0];
}

static void	ft_stock_coord(t_coord_4 coord[4], int *x, int *y)
{
	if (coord[0].ok_pick_up == 0)
	{
		coord[0].x = *x;
		coord[0].y = *y;
		coord[0].ok_pick_up = 1;
	}
	if (*x > coord[1].x)
	{
		coord[1].x = *x;
		coord[1].y = *y;
	}
	if (*x <= coord[2].x)
	{
		coord[2].x = *x;
		coord[2].y = *y;
	}
	coord[3].x = *x;
	coord[3].y = *y;
}

static void	ft_get_coord(t_data *data, t_coord_4 coord[4], char shape)
{
	int		y;
	int		x;
	char	little_shape;

	y = 0;
	x = 0;
	little_shape = shape + 32;
	ft_init_coord(coord, data);
	while (data->plateau[y])
	{
		x = 0;
		while (data->plateau[y][x])
		{
			if (data->plateau[y][x] == shape ||
				data->plateau[y][x] == little_shape)
				ft_stock_coord(coord, &x, &y);
			x++;
		}
		y++;
	}
}

static void	ft_sub_centroid(t_centroid *centroid, t_coord_4 coord[4])
{
	centroid->x_1 = (coord[0].x + coord[1].x + coord[3].x) / 3;
	centroid->y_1 = (coord[0].y + coord[1].y + coord[3].y) / 3;
	centroid->x_2 = (coord[0].x + coord[2].x + coord[3].x) / 3;
	centroid->y_2 = (coord[0].y + coord[2].y + coord[3].y) / 3;
	centroid->x = (float)(centroid->x_1 + centroid->x_2) / 2 + 0.5;
	centroid->y = (float)(centroid->y_1 + centroid->y_2) / 2 + 0.5;
}

void		ft_global_centroid(t_data *data)
{
	ft_get_coord(data, data->player_coord, data->player_shape);
	ft_get_coord(data, data->enemy_coord, data->enemy_shape);
	ft_sub_centroid(&data->player_centroid, data->player_coord);
	ft_sub_centroid(&data->enemy_centroid, data->enemy_coord);
	data->centroid_x = (float)(data->player_centroid.x +
						data->enemy_centroid.x) / 2 + 0.5;
	data->centroid_y = (float)(data->player_centroid.y +
						data->enemy_centroid.y) / 2 + 0.5;
}
