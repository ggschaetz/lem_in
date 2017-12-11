/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:04:47 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:01:57 by gschaetz         ###   ########.fr       */
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
		if (ft_strcmp(tab[0], st->ro[i].name) == 0 || \
			ft_strcmp(tab[1], st->ro[i].name) == 0)
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
	st->tu[st->count_tube].name1 = ft_strdup(tab[0]);
	st->tu[st->count_tube].name2 = ft_strdup(tab[1]);
	ft_free_tab(tab);
}

int		ft_wood_if(t_lem *st, char *line, char **tab)
{
	if (line[ft_strlen(line) - 1] == '-' || line[0] == '-')
	{
		ft_free_tab(tab);
		return (0);
	}
	if (ft_check_room_exist(tab, st) == 0)
	{
		ft_free_tab(tab);
		return (0);
	}
	if (ft_check_loop_room(tab) == 0)
	{
		ft_free_tab(tab);
		return (0);
	}
	return (1);
}

int		ft_check_tube(t_lem *st, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	if (st->after_start == 1 || st->after_end == 1)
		return (0);
	tab = ft_strsplit(line, '-');
	if (ft_wood_if(st, line, tab) == 0)
		return (0);
	ft_stock_tube(tab, st);
	st->count_tube++;
	st->time_tube = 1;
	return (1);
}
