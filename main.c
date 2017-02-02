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

int main(void)
{
    t_data data;

    if (ft_get_input(&data) == -1)
        return (-1);
    return (0);
}

/*
int y;
int k;
ft_printf("================ MY_Content ================\n");
ft_printf("data.xy_plateau[0] : %d - data.xy_plateau[1] : %d\n", data.xy_plateau[0], data.xy_plateau[1]);
y = 0;
while (y < data.xy_plateau[0])
    ft_putendl(data.plateau[y++]);
ft_printf("data.xy_piece[0] : %d - data.xy_piece[1] : %d\n", data.xy_piece[0], data.xy_piece[1]);
k = 0;
while (k < data.xy_piece[0])
    ft_putendl(data.piece[k++]);
*/

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
