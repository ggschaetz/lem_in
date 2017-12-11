/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:08:08 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:13:46 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_free_tu_and_ro(t_lem *st)
{
	int i;

	i = 0;
	while (i <= 200000)
	{
		free(st->ro[i].name);
		free(st->tu[i].name1);
		free(st->tu[i].name2);
		i++;
	}
	free(st->ro);
	free(st->tu);
}

void		ft_free_tab_line(t_lem *st)
{
	int	i;

	i = 0;
	while (i <= st->nb_row && st->nb_row != 0)
	{
		free(st->tab_line[i]);
		st->tab_line[i] = NULL;
		i++;
	}
	free(st->tab_line);
	st->tab_line = NULL;
}

void		ft_free_pr(t_lem *st)
{
	int	i;

	i = 0;
	while (i < st->id_pr)
	{
		free(st->pr[i].father);
		free(st->pr[i].sommet);
		i++;
	}
	free(st->pr);
}

void		ft_free_struct(t_lem *st)
{
	int		i;

	i = 0;
	if (st->flag_parce == 0)
	{
		ft_free_tu_and_ro(st);
		ft_free_tab_line(st);
		free(st);
		return ;
	}
	ft_free_tu_and_ro(st);
	ft_free_tab_line(st);
	ft_free_pr(st);
	while (i < st->count_room)
		free(st->way[i++]);
	free(st->way);
	free(st);
}

void		ft_free_file(t_lem *st, char **file)
{
	int		i;

	i = 0;
	while (i < st->count_room)
	{
		free(file[i]);
		i++;
	}
	free(file);
}
