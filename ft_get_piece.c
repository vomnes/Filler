/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:23:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:27:47 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_count_coord(char *line, t_data *data)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '*')
			data->nb_coord++;
		i++;
	}
}

static void	ft_end_output(t_data *data)
{
	data->final_x = 0;
	data->final_y = 0;
	ft_get_best_position(data);
	ft_putnbr(data->final_y);
	ft_putchar(' ');
	ft_putnbr(data->final_x);
	ft_putchar('\n');
	data->nb_coord = 0;
	ft_free_strtab(data->plateau);
	ft_free_strtab(data->piece);
	data->piece = NULL;
	free(data->coord);
	data->coord = NULL;
}

int			ft_get_piece(t_data *data, char *line)
{
	int i;

	i = 0;
	if ((ft_strstr(line, "Piece")))
	{
		ft_get_xy(line, data->xy_piece);
		if (!(data->piece = (char**)ft_memalloc(sizeof(*data->piece)
		* (data->xy_piece[0] + 1))))
			return (-1);
		while (i < data->xy_piece[0])
		{
			ft_gnl_tab_free(data->piece, &i, 0);
			ft_count_coord(data->piece[i], data);
			i++;
		}
		data->piece[i] = NULL;
		ft_end_output(data);
	}
	return (0);
}
