/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 10:29:11 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 16:46:38 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void		ft_malloc_pr(t_lem *st)
{
	if (!(st->pr = (t_pr *)malloc(sizeof(t_pr) * (st->count_room + 1))))
		return ;
}

void		ft_marquer(t_lem *st, char *name)
{
	int		i;

	i = 0;
	while (ft_strcmp(st->ro[i].name, name) != 0)
		i++;
	st->ro[i].pass = 1;
}

char		*ft_fils(t_lem *st, char *father, int y)
{
	if (ft_is_mark(st, st->tu[y].name2) != 1 && \
		ft_strcmp(st->tu[y].name1, father) == 0)
	{
		st->pr[st->id_pr].father = ft_strdup(father);
		st->pr[st->id_pr].sommet = ft_strdup(st->tu[y].name2);
		st->id_pr++;
		return (st->tu[y].name2);
	}
	if (ft_is_mark(st, st->tu[y].name1) != 1 && \
		ft_strcmp(st->tu[y].name2, father) == 0)
	{
		st->pr[st->id_pr].father = ft_strdup(father);
		st->pr[st->id_pr].sommet = ft_strdup(st->tu[y].name1);
		st->id_pr++;
		return (st->tu[y].name1);
	}
	return (NULL);
}

int			ft_file_empty(t_lem *st, char **file)
{
	int i;

	i = 0;
	while (i < st->count_room)
	{
		if (ft_strcmp(file[i], "") != 0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_resolv(t_lem *st)
{
	int		i;
	char	*name;

	i = 0;
	ft_malloc_pr(st);
	name = ft_strdup(st->ro[st->id_start].name);
	ft_bfs(st, i, name);
	if (ft_check_if_end(st) == 0)
	{
		ft_printf("no way!\n");
		ft_free_struct(st);
		exit(0);
	}
	ft_isolate_way(st);
	free(name);
}
