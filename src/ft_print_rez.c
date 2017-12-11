/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rez.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:02:04 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:15:05 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_print_rez(t_lem *st)
{
	int		i;
	int		y;
	int		nb_ants_down;

	i = 1;
	nb_ants_down = 0;
	ft_printf("\n");
	while (i < (st->nb_row_way) + (st->nb_ants + 1))
	{
		y = 0;
		if (i > st->nb_row_way + 1)
		{
			nb_ants_down++;
			y = nb_ants_down;
		}
		while (y < i && y < st->nb_ants)
		{
			ft_printf("L%d-%s ", y + 1, \
					st->way[(i - y - st->nb_row_way) * (-1) + 1]);
			y++;
		}
		ft_printf("\n");
		i++;
	}
}
