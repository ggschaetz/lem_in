/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:02:51 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/25 17:28:59 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_stock_info_room(t_lem *st, char **tab)
{
	int i;

	i = 0;
	/*ft_printf("after_start = %d, end = %d\n", st->after_start, st->after_end);
	while (tab[i] != NULL)
	{
		ft_printf("tab[%i] = %s\n", i, tab[i]);
		i++;
	}*/
	st->ro[st->count_room].name = ft_strdup(tab[0]);
	st->ro[st->count_room].x = ft_atoi(tab[1]);
	st->ro[st->count_room].y = ft_atoi(tab[2]);
	if (st->after_start == 1)
	{
		st->ro[st->count_room].start = 1;
		st->id_start = st->count_room;
		st->after_start = 0;
	}
	else if (st->after_end == 1)
	{
		st->ro[st->count_room].end = 1;
		st->id_end = st->count_room;
		st->after_end = 0;
	}
}

int		ft_check_format_room(char **tab, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
		i++;
	//ft_printf("test = %c\n", tab[0][0]);
	if (ft_strchr(str, '-') != NULL || tab[0][0] == 'L' || i != 3 || tab[0][0] == '#')
		return (0);
	i = 1;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			//ft_printf("char = %c\n", tab[i][j]);
			if (ft_isdigit(tab[i][j] != 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_check_duplicate_room(char **tab, t_lem *st)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < st->count_room)
	{
		if (ft_strcmp(tab[0], st->ro[i].name) == 0)
			return (0);
		if (ft_atoi(tab[1]) == st->ro[i].x && ft_atoi(tab[2]) == st->ro[i].y)
			return (0);
		i++;
	}
	return (1);
}

int			ft_check_room(t_lem *st, char *str)
{
	char	**tab;

	if (st->time_tube != 0)
		return (0);
	tab = ft_strsplit(str, ' ');
	if (ft_check_format_room(tab, str) == 0)
		return (0);
	if (ft_check_duplicate_room(tab, st) == 0)
		return (0);
	ft_stock_info_room(st, tab);
	st->count_room++;
	return (1);
}
