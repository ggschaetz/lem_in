/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:08:08 by gschaetz          #+#    #+#             */
/*   Updated: 2017/06/27 11:38:08 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_free_struct(t_lem *st)
{
	int i;

	i = 0;
	while (i <= st->nb_row && st->nb_row != 0)
	{
		free(st->tab_line[i]);
		st->tab_line[i] = NULL;
		i++;
	}
	free(st->tab_line);
	st->tab_line = NULL;
	free(st);
}

void		ft_free_tab(t_lem *st)
{
	int i;

	i = 0;
	while (i < st->nb_row)
	{
		free(st->tab_line[i]);
		st->tab_line[i] = NULL;
		i++;
	}
	free(st->tab_line);
	st->tab_line = NULL;
}

void		ft_free_cpy(t_lem *st)
{
	int i;

	i = 0;
	while (i <= st->nb_row)
	{
		free(st->cpy[i]);
		st->cpy[i] = NULL;
		i++;
	}
	free(st->cpy);
	st->cpy = NULL;
}
