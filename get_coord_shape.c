/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:53:14 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/08 15:09:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

static void ft_init_coord(t_coord_4 coord[4], t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
    {
        coord[i].x = -1;
        coord[i].y = -1;
        coord[i].ok_pick_up	= 0;
        i++;
    }
	coord[2].x = data->xy_plateau[0];
}

void ft_get_coord(t_data *data, t_coord_4 coord[4], char shape)
{
	int y;
	int x;
	char little_shape;

	y = 0;
	x = 0;
	little_shape = shape + 32;
	ft_init_coord(coord, data);
	while (data->plateau[y])
	{
		x = 0;
		while (data->plateau[y][x])
		{
			if (data->plateau[y][x] == shape || data->plateau[y][x] == little_shape)
			{
				if (coord[0].ok_pick_up == 0)
				{
					coord[0].x = x;
					coord[0].y = y;
					coord[0].ok_pick_up = 1;
				}
				if (x > coord[1].x)
				{
					coord[1].x = x;
					coord[1].y = y;
				}
				if (x <= coord[2].x)
				{
					coord[2].x = x;
					coord[2].y = y;
				}
				coord[3].x = x;
				coord[3].y = y;
			}
			x++;
		}
		y++;
	}
}

void ft_sub_centroid(t_centroid centroid)
{
	centroid.x_1 = (player_coord[0].x + player_coord[1].x + player_coord[3].x) / 3;
	centroid.y_1 = (player_coord[0].y + player_coord[1].y + player_coord[3].y) / 3;
    centroid.x_2 = (player_coord[0].x + player_coord[1].x + player_coord[3].x) / 3;
    centroid.y_2 = (player_coord[0].y + player_coord[1].y + player_coord[3].y) / 3;
	centroid.x = (centroid.x_1 + centroid.x_2) / 2;
	centroid.y = (centroid.y_1 + centroid.y_2) / 2;
}

void ft_global_centroid(t_data *centroid)
{
	ft_sub_centroid(centroid[0]);
	ft_sub_centroid(centroid[1]);
	data->centroid_x = (centroid[0].x + centroid[1].x) / 2;
	data->centroid_y = (centroid[0].y + centroid[1].y) / 2;
}

