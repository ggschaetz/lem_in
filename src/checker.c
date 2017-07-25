/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:42:26 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/25 17:28:43 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_nb_ants(char *line, t_lem *st)
{
	int i;

	i = 0;
	//ft_printf("test ants nb\n");
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	st->nb_ants = ft_atoi(line);
	return (1);
}

/*int			ft_check_end_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		ft_printf("i = %d\n", i);
		i++;
	}
	if (str[i] == '\0')
		return (0);
	i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (ft_isdigit(str[i++]) == 0)
			return (0);
	}
	if (str[i] == '\0')
		return (0);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i++]) == 0)
			return (0);
	}
	return (1);
}

int			ft_check_tube(t_lem *st, char *line)
{
	char	**tab;
	int		i;
	int		exist;

	i = 0;
	exist = 0;
	tab = ft_strsplit(line, '-');
	while (tab[i++] != NULL)
	if (i != 3)
		return (0);
	i= 0;
	while (i < st->count_room)
	{
		if (ft_strcmp(tab[0], st->ro[i].name) == 0 || ft_strcmp(tab[2], st->ro[i].name) == 0)
			exist++;
		i++;
	}
	if (exist == 2)
		return (1);
	return (0);
}*/

int			ft_check_start_end(t_lem *st, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (st->flag_start == 1)
			return (0);
		st->flag_start++;
		st->after_start = 1;
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		if (st->flag_end == 1)
			return (0);
		st->flag_end++;
		st->after_end = 1;
	}
	return (1);
}

int			ft_identifi(char *str, t_lem *st)
{
	if (ft_is_comment(str) == 1 && st->after_start == 0 && st->after_end == 0)
		return (1);
	if (ft_is_room(str) == 1)
		return (2);
	if (ft_is_tube(str) == 1)
		return (3);
	return (0);
}

int			ft_checker(t_lem *st, char *line)
{
	int		id;

	id = 0;
	if (ft_strcmp(line, "") == 0)
		return (0);
	if (st->nb_row == 0 && ft_check_nb_ants(line, st) != 1)
		return (0);

	id = ft_identifi(line, st);
	if (id == 1 && ft_check_start_end(st, line) == 0)
		return (0);
	if (id == 2 && ft_check_room(st, line) == 0)
		return (0);
	if (id == 3 && ft_check_tube(st, line) == 0)
		return (0);
	return (1);
}

