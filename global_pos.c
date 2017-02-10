/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:15:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/09 13:51:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

# define LEFT_UP 1
# define RIGHT_UP 2
# define LEFT_DOWN 3
# define RIGHT_DOWN 4

static void ft_global_pos(t_global *area, t_centroid position, t_data *data)
{
	area->x = 0;
	area->y = 0;
	if (position.x < (int)((float)data->xy_plateau[1] / 2 + 0.5))
		area->x = -1;
	else
		area->x = 1;
    if (position.y < (int)((float)data->xy_plateau[0] / 2 + 0.5))
        area->y = -1;
    else
        area->y = 1;
}

static void ft_dir(t_data *data, int select)
{
	if (select == LEFT_UP)
	{
		data->final_x = data->move.left_up_x;
		data->final_y = data->move.left_up_y;
	}
	if (select == RIGHT_UP)
	{
		data->final_x = data->move.right_up_x;
		data->final_y = data->move.right_up_y;
	}
	if (select == LEFT_DOWN)
	{
		data->final_x = data->move.left_down_x;
		data->final_y = data->move.left_down_y;
	}
	if (select == RIGHT_DOWN)
	{
		data->final_x = data->move.right_down_x;
		data->final_y = data->move.right_down_y;
	}
}

int			ft_choose_direction(t_data *d)
{
    int x0;
    int y0;
    int x1;
    int y1;

    x0 = d->player_centroid.x;
    y0 = d->player_centroid.y;
    x1 = d->enemy_centroid.x;
    y1 = d->enemy_centroid.y;
		ft_global_pos(&d->p_pos, d->player_centroid, d);
    ft_global_pos(&d->e_pos, d->enemy_centroid, d);
//    dprintf(2, "data->player_pos.x = %2d | data->player_pos.y = %2d\n", d->p_pos.x, d->p_pos.y);
//    dprintf(2, "data->enemy_pos.x  = %2d | data->enemy_pos.y  = %2d\n", d->e_pos.x, d->e_pos.y);
		if ((x1 > x0 && y1 < y0) || (d->p_pos.x == -1 && d->p_pos.y == 1 && d->e_pos.x == 1 && d->e_pos.y == 1))
    {
				ft_dir(d, RIGHT_UP);
    //    ft_putendl_fd("DOWN R", 2);
        return (1);
    }
		if (x1 > x0 && y1 > y0) //Down right
    {
				ft_dir(d, RIGHT_DOWN);
    //    ft_putendl_fd("UP R", 2);
        return (1);
    }
    if (x1 == x0 && y1 < y0) // Up
    {
				if (d->p_pos.x == -1)
					ft_dir(d, RIGHT_UP);
				else
					ft_dir(d, LEFT_UP);
    //    ft_putendl_fd("UP", 2);
				return (1);
    }
    if (x1 > x0 && y1 == y0) // Right
    {
				if (d->p_pos.y == -1)
					ft_dir(d, RIGHT_DOWN);
				else
					ft_dir(d, RIGHT_UP);
    //    ft_putendl_fd("RIGHT", 2);
				return (1);
    }
    if (x1 == x0 && y1 > y0) // Down
    {
				if (d->p_pos.x == -1)
					ft_dir(d, RIGHT_DOWN);
				else
					ft_dir(d, LEFT_DOWN);
    //    ft_putendl_fd("DOWN", 2);
				return (1);
    }
    if (x1 < x0 && y1 > y0) //Down left
    {
				ft_dir(d, LEFT_DOWN);
    //    ft_putendl_fd("UP L", 2);
        return (1);
    }
    if (x1 < x0 && y1 == y0) // Left
    {
				if (d->p_pos.y == -1)
						ft_dir(d, LEFT_DOWN);
				else
						ft_dir(d, LEFT_UP);
    //    ft_putendl_fd("LEFT", 2);
				return (1);
    }
    if (x1 < x0 && y1 < y0)//Up left
    {
				ft_dir(d, LEFT_UP);
    //    ft_putendl_fd("DOWN L", 2);
        return (1);
  	}
	if (x1 == x0 && y1 == y0)
	{
		if (d->p_pos.x == -1 && d->p_pos.y == -1)
			ft_dir(d, RIGHT_DOWN);
		else if (d->p_pos.x == 1 && d->p_pos.y == -1)
			ft_dir(d, LEFT_DOWN);
		else if (d->p_pos.x == 1 && d->p_pos.y == 1)
			ft_dir(d, RIGHT_UP);
		else if (d->p_pos.x == -1 && d->p_pos.y == 1)
			ft_dir(d, LEFT_UP);
		//ft_putendl_fd("Equality", 2);
		return (1);
	}
	//ft_putendl_fd("ERROR /!\\", 2);
  return (0);
}
