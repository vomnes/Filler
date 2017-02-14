/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spe_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:58:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/14 11:59:00 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_dir_one(t_data *data)
{
	if (data->e_pos.x == -1 && data->e_pos.y == -1 &&
	data->p_pos.x == 1 && data->e_pos.y == -1)
	{
		if (data->flag_dir < 40)
		{
			if (data->flag_dir % 6 == 0)
				ft_select_dir(data, LEFT_UP);
			else
				ft_select_dir(data, LEFT_DOWN);
		}
		else
			ft_select_dir(data, LEFT_UP);
		data->flag_dir++;
		return (1);
	}
	return (0);
}

static int	ft_dir_two(t_data *data)
{
	if (data->e_pos.x == -1 && data->e_pos.y == 1 &&
	data->p_pos.x == 1 && data->e_pos.y == 1 && data->flag_dir < 15)
	{
		ft_select_dir(data, RIGHT_UP);
		data->flag_dir++;
		return (1);
	}
	if (data->e_pos.x == 1 && data->e_pos.y == -1 &&
	data->p_pos.x == 1 && data->e_pos.y == -1)
	{
		ft_select_dir(data, LEFT_UP);
		return (1);
	}
	if (data->e_pos.x == -1 && data->e_pos.y == -1 &&
	data->p_pos.x == -1 && data->e_pos.y == -1)
	{
		ft_select_dir(data, RIGHT_UP);
		return (1);
	}
	return (0);
}

int			ft_spe_dir(t_data *data)
{
	if (ft_dir_one(data))
		return (1);
	if (ft_dir_two(data))
		return (1);
	return (0);
}
