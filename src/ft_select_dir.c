/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:36:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/14 12:00:47 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_select_dir(t_data *data, int select)
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
