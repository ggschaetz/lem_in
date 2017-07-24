/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:42:26 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/24 11:10:55 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_nb_ants(char *line)
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
	return (1);
}

int			ft_check_end_isdigit(char *str)
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

int			ft_check_start_end(t_lem *st, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (st->flag_start == 1)
			return (0);
		st->flag_start++;
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		if (st->flag_end == 1)
			return (0);
		st->flag_end++;
	}
	return (1);
}

int			ft_identifi(char *str)
{
	if (ft_is_comment(str) == 1)
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
	if (st->nb_row == 0 && ft_check_nb_ants(line) != 1)
		return (0);
	id = ft_identifi(line);
	//if (st->stock_start == 1 && ft_check_room(st, line) == 1)
	//	ft_stock_start(st, line);

	//if (st->stock_end == 1)
	//	ft_stock_end(st, line);
	//ft_printf("id = %d\n", id);
	if (id == 1 && ft_check_start_end(st, line) == 0)
		return (0);
	if (id == 2 && ft_check_room(st, line) == 0 && st->time_tube == 0)
		return (0);
	return (1);
}

