/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:36:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:40:57 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_select_dir(t_data *data, int select)
{
	if (select == LEFT_UP)
	{
		data->final_x = data->move.left_up_x;
		data->final_y = data->move.left_up_y;
	//	ft_putendl_fd("LEFT_UP", 2);
	}
	if (select == RIGHT_UP)
	{
		data->final_x = data->move.right_up_x;
		data->final_y = data->move.right_up_y;
	//	ft_putendl_fd("RIGHT_UP", 2);
	}
	if (select == LEFT_DOWN)
	{
		data->final_x = data->move.left_down_x;
		data->final_y = data->move.left_down_y;
	//	ft_putendl_fd("LEFT_DOWN", 2);
	}
	if (select == RIGHT_DOWN)
	{
		data->final_x = data->move.right_down_x;
		data->final_y = data->move.right_down_y;
	//	ft_putendl_fd("RIGHT_DOWN", 2);
	}
}
