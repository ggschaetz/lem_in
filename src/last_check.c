/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:32:44 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:09:24 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_link_start_end_end(t_lem *st)
{
	int	y;
	int flag_start;
	int	flag_end;

	y = 0;
	flag_start = 0;
	flag_end = 0;
	while (y < st->count_tube && (flag_start == 0 || flag_end == 0))
	{
		if (ft_strcmp(st->ro[st->id_start].name, st->tu[y].name1) == 0 \
			|| ft_strcmp(st->ro[st->id_start].name, st->tu[y].name2) == 0)
			flag_start = 1;
		if (ft_strcmp(st->ro[st->id_end].name, st->tu[y].name1) == 0 \
			|| ft_strcmp(st->ro[st->id_end].name, st->tu[y].name2) == 0)
			flag_end = 1;
		y++;
	}
	if (flag_start != 1 || flag_end != 1)
		return (0);
	return (1);
}

int			last_check(t_lem *st)
{
	int i;

	i = 0;
	if (st->flag_start == 0 || st->flag_end == 0 || st->count_tube == 0)
		return (0);
	while (i < st->count_tube)
	{
		ft_printf("%s-%s\n", st->tu[i].name1, st->tu[i].name2);
		i++;
	}
	if (ft_check_link_start_end_end(st) == 0)
		return (0);
	return (1);
}
