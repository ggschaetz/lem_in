/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:14:10 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 15:31:30 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_if_end(t_lem *st)
{
	int		i;

	i = 0;
	while (i < st->id_pr)
	{
		if (ft_strcmp(st->pr[i].father, st->ro[st->id_end].name) == 0 || \
			ft_strcmp(st->pr[i].sommet, st->ro[st->id_end].name) == 0)
			return (1);
		i++;
	}
	return (0);
}
