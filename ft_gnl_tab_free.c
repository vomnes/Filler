/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_tab_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:42:05 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/10 17:42:06 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "filler.h"

void ft_gnl_tab_free(char **tab, int *i, int precision)
{
  char *str;

  str = NULL;
  get_next_line(0, &str);
  tab[*i] = ft_strdup(str + precision);
  free(str);
  str = NULL;
}
