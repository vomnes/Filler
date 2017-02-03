/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:44:20 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/02 19:44:26 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

static void ft_get_xy(char *input, int *stock)
{
    int i;
    int next;

    i = 0;
    next = 0;
    stock[0] = 0;
    stock[1] = 0;
    while (input[i] != '\0')
    {
        while (ft_isdigit(input[i]))
            stock[next] = stock[next] * 10 + (input[i++] - '0');
        if (ft_isdigit(input[i - 1]) && input[i] != ':')
            next++;
        i++;
    }
}

static int ft_size_tab(char *line, t_data *data)
{
    if ((ft_strstr(line, "Plateau")))
    {
        ft_get_xy(line, data->xy_plateau);
        if (!(data->plateau = (char**)ft_memalloc(sizeof(*data->plateau)
        * (data->xy_plateau[0] + 1))))
            return (-1);
    }
    if ((ft_strstr(line, "Piece")))
    {
        ft_get_xy(line, data->xy_piece);
        if (!(data->piece = (char**)ft_memalloc(sizeof(*data->piece)
        * (data->xy_piece[0] + 1))))
            return (-1);
    }
    if (!data->xy_plateau[0] && !data->piece[0])
        return (-1);
    return (0);
}

void ft_count_coord(char *line, t_data *data)
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

static void ft_gather_plateau_piece(t_data *data, char *line, int *y, int *k)
{
    if (ft_isdigit(line[0]))
    {
        if (ft_strchr(line, data->player_shape) && data->ok_min_y == 0)
        {
            data->min_y = *y;
            data->ok_min_y = 1;
        }
        data->plateau[(*y)++] = ft_strdup(ft_strchr(line, ' ') + 1);
    }
    if (line[0] == '.' || line[0] == '*')
    {
        data->piece[(*k)++] = ft_strdup(line);
        ft_count_coord(line, data);
    }
}

int    ft_get_input(t_data *data)
{
    int y;
    int k;
    char *line;

    y = 0;
    k = 0;
    line = NULL;
    data->nb_coord = 0;
    while (get_next_line(0, &line) > 0)
    {
        if (ft_size_tab(line, data) == -1)
            return (-1);
        if (*line != 'P' && *line != ' ' && !ft_isdigit(*line) && *line != '.'
        && *line != '*')
            break ;
        ft_gather_plateau_piece(data, line, &y, &k);
        free(line);
    }
    data->plateau[y] = NULL;
    data->piece[k] = NULL;
    return (1);
}