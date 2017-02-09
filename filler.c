/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:48:20 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/09 19:33:57 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void ft_print_strtab(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
	{
        ft_putendl_fd(tab[i], 2);
		i++;
	}
}

void ft_free_strtab(char **tab)
{
    int i;

    i = 0;
    if (*tab)
    {
    //    while (tab[i] != NULL)
    //        free(tab[i++]);
        ft_strdel(tab);
    }
}

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
		if (ft_isdigit(input[i]))
		{
			while (ft_isdigit(input[i]))
				stock[next] = stock[next] * 10 + (input[i++] - '0');
            next++;
		}
        i++;
    }
}

static void ft_get_number_player(t_data *data, char *line)
{
    int i;

    i = 0;
    data->num_player = 0;
    if (line[0] == '$')
    {
        if (ft_strstr(line, "vomnes.filler"))
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
        }
    }
}

static int ft_get_plateau(t_data *data, char *line)
{
    int i;
    char *str;

    i = 0;
    str = NULL;
    if ((ft_strstr(line, "Plateau")))
    {
        data->ok_get_piece = 0;
        ft_get_xy(line, data->xy_plateau);
        if (!(data->plateau = (char**)ft_memalloc(sizeof(*data->plateau)
        * (data->xy_plateau[0] + 1))))
            return (-1);
        get_next_line(0, &str);
        while (i < data->xy_plateau[0])
        {
            get_next_line(0, &str);
//			ft_putchar_fd('>', 2);
            data->plateau[i] = ft_strdup(ft_strchr(str, ' ') + 1);
//            dprintf(2, "|%s\n", data->plateau[i]);
            i++;
        }
        free(str);
        data->plateau[i] = NULL;
//        ft_print_strtab(data->plateau);
		ft_global_centroid(data);
    }
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

static int ft_get_piece(t_data *data, char *line)
{
    int i;
    char *str;

    i = 0;
    str = NULL;
    if ((ft_strstr(line, "Piece")))
    {
        ft_get_xy(line, data->xy_piece);
        if (!(data->piece = (char**)ft_memalloc(sizeof(*data->piece)
        * (data->xy_piece[0] + 1))))
            return (-1);
        while (i < data->xy_piece[0])
        {
            get_next_line(0, &str);
            data->piece[i] = ft_strdup(str);
            ft_count_coord(str, data);
            i++;
        }
        free(str);
        data->piece[i] = NULL;
        data->ok_get_piece = 1;
        data->final_x = 0;
        data->final_y = 0;
        if (data->ok_get_piece == 1)
        {
            ft_get_best_position(data);
            ft_putnbr(data->final_y);
            ft_putchar(' ');
            ft_putnbr(data->final_x);
            ft_putchar('\n');
            data->nb_coord = 0;
        }
    }
    return (0);
}

int ft_get_data(t_data *data)
{
    char *line;

    line = NULL;
    data->nb_coord = 0;
    while (get_next_line(0, &line) > 0)
    {
        data->empty_space = 0;
        data->nb_player_shape = 0;
        ft_get_number_player(data, line);
        ft_get_plateau(data, line);
        ft_get_piece(data, line);
        data->empty_space = 0;
    }
    free(line);
    return (0);
}
