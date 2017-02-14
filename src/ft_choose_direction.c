/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:56:23 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/14 12:00:12 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_global_pos(t_global *area, t_centroid position, t_data *data)
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

int			ft_choose_direction(t_data *data)
{
	ft_global_pos(&data->p_pos, data->player_centroid, data);
	ft_global_pos(&data->e_pos, data->enemy_centroid, data);
	ft_direction_pos(data);
	return (0);
}
