/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:37:24 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:02:52 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define X_ZERO data->player_centroid.x
#define Y_ZERO data->player_centroid.y
#define X_ONE data->enemy_centroid.x
#define Y_ONE data->enemy_centroid.y

static int	ft_dir_one(t_data *data)
{
	if ((X_ONE > X_ZERO && Y_ONE < Y_ZERO) || (data->p_pos.x == -1 &&
	data->p_pos.y == 1 && data->e_pos.x == 1 && data->e_pos.y == 1))
	{
		ft_select_dir(data, RIGHT_UP);
		return (1);
	}
	if (X_ONE > X_ZERO && Y_ONE > Y_ZERO)
	{
		ft_select_dir(data, RIGHT_DOWN);
		return (1);
	}
	if (X_ONE == X_ZERO && Y_ONE < Y_ZERO)
	{
		if (data->p_pos.x == -1)
			ft_select_dir(data, RIGHT_UP);
		else
			ft_select_dir(data, LEFT_UP);
		return (1);
	}
	return (0);
}

static int	ft_dir_two(t_data *data)
{
	if (X_ONE > X_ZERO && Y_ONE == Y_ZERO)
	{
		if (data->p_pos.y == -1)
			ft_select_dir(data, RIGHT_DOWN);
		else
			ft_select_dir(data, RIGHT_UP);
		return (1);
	}
	if (X_ONE == X_ZERO && Y_ONE > Y_ZERO)
	{
		if (data->p_pos.x == -1)
			ft_select_dir(data, RIGHT_DOWN);
		else
			ft_select_dir(data, LEFT_DOWN);
		return (1);
	}
	return (0);
}

static int	ft_dir_three(t_data *data)
{
	if (X_ONE < X_ZERO && Y_ONE > Y_ZERO)
	{
		ft_select_dir(data, LEFT_DOWN);
		return (1);
	}
	if (X_ONE < X_ZERO && Y_ONE == Y_ZERO)
	{
		if (data->p_pos.y == -1)
			ft_select_dir(data, LEFT_DOWN);
		else
			ft_select_dir(data, LEFT_UP);
		return (1);
	}
	if (X_ONE < X_ZERO && Y_ONE < Y_ZERO)
	{
		ft_select_dir(data, LEFT_UP);
		return (1);
	}
	return (0);
}

static int	ft_dir_equality(t_data *data)
{
	if (X_ONE == X_ZERO && Y_ONE == Y_ZERO)
	{
		if (data->p_pos.x == -1 && data->p_pos.y == -1)
			ft_select_dir(data, RIGHT_DOWN);
		else if (data->p_pos.x == 1 && data->p_pos.y == -1)
			ft_select_dir(data, LEFT_DOWN);
		else if (data->p_pos.x == 1 && data->p_pos.y == 1)
			ft_select_dir(data, RIGHT_UP);
		else if (data->p_pos.x == -1 && data->p_pos.y == 1)
			ft_select_dir(data, LEFT_UP);
		return (1);
	}
	return (0);
}

int			ft_direction_pos(t_data *data)
{
	if (ft_dir_one(data))
		return (1);
	if (ft_dir_two(data))
		return (1);
	if (ft_dir_three(data))
		return (1);
	if (ft_dir_equality(data))
		return (1);
	return (0);
}
