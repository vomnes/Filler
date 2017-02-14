/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:31:49 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:39:13 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_get_number_player(t_data *data, char *line)
{
	int i;

	i = 0;
	data->num_player = 0;
	if (line[0] == '$')
	{
		if (ft_strstr(line, "/filler]"))
		{
			while (line[i++])
			{
				if (line[i] == 'p' && ft_isdigit(line[i + 1]))
				{
					data->num_player = line[i + 1] - '0';
					data->player_shape = data->num_player == 2 ? 'X' : 'O';
					data->enemy_shape = data->num_player == 2 ? 'O' : 'X';
				}
			}
			data->flag_dir = 0;
		}
	}
}

static void	ft_gnl_free(char **tab, int *i)
{
	char *str;

	str = NULL;
	get_next_line(0, &str);
	tab[*i] = ft_strdup(ft_strchr(str, ' ') + 1);
	free(str);
	str = NULL;
}

static int	ft_get_plateau(t_data *data, char *line)
{
	int		i;
	char	*str;
	char	*new;

	i = -1;
	str = NULL;
	if ((ft_strstr(line, "Plateau")))
	{
		ft_get_xy(line, data->xy_plateau);
		if (!(data->plateau = (char**)ft_memalloc(sizeof(*data->plateau)
		* (data->xy_plateau[0] + 1))))
			return (-1);
		get_next_line(0, &new);
		ft_strddel(new);
		while (++i < data->xy_plateau[0])
			ft_gnl_free(data->plateau, &i);
		free(str);
		str = NULL;
		data->plateau[i] = NULL;
		ft_global_centroid(data);
	}
	free(line);
	line = NULL;
	return (0);
}

int			ft_run_filler(t_data *data)
{
	char *line;

	line = NULL;
	data->nb_coord = 0;
	while (get_next_line(0, &line) > 0)
	{
		data->empty_space = 0;
		data->nb_player_shape = 0;
		ft_get_number_player(data, line);
		if (ft_get_plateau(data, line) == -1)
			return (-1);
		if (ft_get_piece(data, line) == -1)
			return (-1);
		data->empty_space = 0;
	}
	free(line);
	line = NULL;
	return (0);
}
