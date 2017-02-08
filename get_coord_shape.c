/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:53:14 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/08 11:47:41 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

static void ft_init_coord(t_coord_4 coord[4])
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
}

void ft_get_coord(t_data *data, t_coord_4 coord[4], char shape)
{
	int y;
	int x;
	char little_shape;

	y = 0;
	x = 0;
	little_shape = shape + 32;
	ft_init_coord(coord);
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
				if (x < coord[1].x && x >= 0)
				{
					coord[1].x = x;
					coord[1].y = y;
				}
				if (x > coord[2].x)
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
