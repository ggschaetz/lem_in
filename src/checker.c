/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:42:26 by gschaetz          #+#    #+#             */
/*   Updated: 2017/06/27 16:59:54 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_nb_ants(char *line)
{
	int i;

	i = 0;
	ft_printf("test ants nb\n");
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_checker(t_lem *st, char *line)
{
	if (st->nb_row == 0 && ft_check_nb_ants(line) == 0)
		return (0);
	return (1);
}

