/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:41:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:29:06 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_xy(char *input, int *stock)
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
