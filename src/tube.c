/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:04:47 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/25 17:29:06 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_check_room_exist(char **tab, t_lem *st)
{
	int		i;
	int		exist;

	i = 0;
	exist = 0;
	while (tab[i] != NULL)
		i++;
	if (i != 2)
		return (0);
	i = 0;
	while (i < st->count_room)
	{
		if (ft_strcmp(tab[0], st->ro[i].name) == 0 || ft_strcmp(tab[1], st->ro[i].name) == 0)
			exist++;
		i++;
	}
	if (exist == 2)
		return (1);
	return (0);
}

int		ft_check_loop_room(char **tab)
{
	if (ft_strcmp(tab[0], tab[1]) == 0)
		return (0);
	return (1);
}

void	ft_stock_tube(char **tab, t_lem *st)
{
	st->tu[st->count_tube].name1 = tab[0];
	st->tu[st->count_tube].name2 = tab[1];
}

int		ft_check_tube(t_lem *st, char *line)
{
	char	**tab;
	int		i;
	int		exist;

	i = 0;
	exist = 0;
	if (st->after_start == 1 || st->after_end == 1)
		return (0);
	tab = ft_strsplit(line, '-');
	if (line[ft_strlen(line) - 1] == '-' || line[0] == '-')
		return (0);
	if (ft_check_room_exist(tab, st) == 0)
		return (0);
	if (ft_check_loop_room(tab) == 0)
		return (0);
	ft_stock_tube(tab, st);
	st->count_tube++;
	st->time_tube = 1;
	return (1);
}
