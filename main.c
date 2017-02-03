/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:17:17 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/02 15:17:30 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void ft_print_strtab(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
        ft_putendl(tab[i++]);
}

int ft_get_coord_piece(t_data *data)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    if (!(data->coord = (t_coord*)malloc(sizeof(t_coord) * data->nb_coord)))
        return (-1);
    while (data->piece[y])
    {
        x = 0;
        while (data->piece[y][x])
        {
            if (data->piece[y][x] == '*')
            {
                data->coord[i].x = x;
                data->coord[i].y = y;
                i++;
            }
            x++;
        }
        y++;
    }
    return (1);
}

void ft_check_new_pos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nb_coord)
    {
        data->coord[i].new_x = data->check_pos_x + data->coord[i].x,
        data->coord[i].new_y = data->check_pos_y + data->coord[i].y;
        if (data->coord[i].new_x < 0 || data->coord[i].new_y < 0)
        {
            ft_putendl("Wrong position");
            exit(-1);
        }
        i++;
    }
}

void ft_display_new_pos(t_data *data, char content)
{
    int i;

    i = 0;
    while (i < data->nb_coord)
    {
//        ft_printf(">> %d - >> %d\n", data->coord[i].new_x, data->coord[i].new_y);
        data->plateau[data->coord[i].new_y][data->coord[i].new_x] = content;
        i++;
    }
}

int main(void)
{
    t_data data;

    data.check_pos_x = 0;
    data.check_pos_y = 10;
    data.ok_min_y = 0;
    data.player_shape = 'O';
    if (!ft_get_input(&data))
        return (-1);
    if (!ft_get_coord_piece(&data))
        return (-1);
    ft_printf("min_x >> %d\n", data.min_y);
    ft_printf("x : %d # y : %d\n", data.check_pos_x, data.check_pos_y); 
    ft_check_new_pos(&data);
    ft_display_new_pos(&data, 'x');
    ft_print_strtab(data.plateau);
    return (0);
}

//data->plateau[y][x]
//data->piece[k][z]

/*
Plateau 15 17:
    01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 ..O..............
010 ..O..............
011 .............xx..
012 .............XX..
013 .................
014 .................
Piece 2 3:
***
**.
<got (O): [10, 2]
*/
