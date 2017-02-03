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

int main(void)
{
    t_data data;

    data.final_pos_x = 0;
    data.final_pos_y = 0;
    data.ok_min_y = 0;
    data.player_shape = 'O';
    if (!ft_get_input(&data))
        return (-1);
    if (!ft_get_coord_piece(&data))
        return (-1);
//    ft_printf("min_x >> %d\n", data.min_y);
//    ft_printf("x : %d # y : %d\n", data.check_pos_x, data.check_pos_y);
    if (!ft_get_best_position(&data))
        return (-1);
//    ft_check_new_pos(&data);
    ft_display_position(&data, 'o');
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
