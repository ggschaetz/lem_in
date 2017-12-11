/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:58:40 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 15:19:26 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_isolate_way(t_lem *st)
{
	int		i;
	int		y;
	char	*name;

	i = 0;
	y = 0;
	st->way = (char **)ft_malloc_tab(st->len_max_line, st->count_room);
	name = ft_strdup(st->ro[st->id_end].name);
	while (ft_strcmp(name, st->ro[st->id_start].name) != 0)
	{
		i = 0;
		while (ft_strcmp(st->pr[i].sommet, name) != 0)
			i++;
		name = ft_strcpy(name, st->pr[i].father);
		st->way[y] = ft_strcpy(st->way[y], st->pr[i].sommet);
		y++;
	}
	st->nb_row_way = y - 1;
	free(name);
}
