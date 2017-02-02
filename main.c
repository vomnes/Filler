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

void ft_get_xy(char *input, int *stock)
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

int main()
{
    char *line;
    t_data data;

    get_next_line(0, &line);
    if ((ft_strstr(line, "Plateau")))
        ft_get_xy(line, data.xy_plateau);
    else if ((ft_strstr(line, "Piece")))
        ft_get_xy(line, data.xy_piece);
    ft_printf("data.xy_plateau[0] : %d - data.xy_plateau[1] : %d\n", data.xy_plateau[0], data.xy_plateau[1]);
    ft_printf("data.xy_piece[0] : %d - data.xy_piece[1] : %d\n", data.xy_piece[0], data.xy_piece[1]);
    return (0);
}


/*
Plateau 15 17:
    01234567890123456
000 XXXXXXXXXXXXXXXX.
001 XXXXXXXXXXXXXXXX.
002 XXXXXXXXXXXXXXXX.
003 XXXXXXXXXXXXXXXX.
004 XXXXXXXXXXXXXXOOO
005 ..OX.XXOOOOOOOOOO
006 oooXXXXXOOOOOOOOO
007 .OOOOOXXOOOOOOOOO
008 .OOOOXXXXXOOOOOOO
009 OOOOOOOOXXOOOOOOO
010 .OOOOXXXXXOOOOOOO
011 .OOOOOOOXXOOOOOOO
012 OOOOOOOXXXXXXXXOO
013 OOOOOOOOOOOOOOOOO
014 ..OOOOOOOOOOOOOOO
Piece 2 3:
..*
.**
<got (O): [0, 0]
*/
