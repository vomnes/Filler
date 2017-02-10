/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:41:33 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 18:03:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_strtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
