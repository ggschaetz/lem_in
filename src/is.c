/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:10:13 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:07:26 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_is_comment(char *str)
{
	if (str[0] != '#')
		return (0);
	return (1);
}

int			ft_is_room(char *str)
{
	int		i;
	char	**tab;

	i = 0;
	if (ft_strchr(str, '-') != NULL)
		return (0);
	tab = ft_strsplit(str, ' ');
	while (tab[i] != NULL)
		i++;
	ft_free_tab(tab);
	if (i != 3)
		return (0);
	return (1);
}

int			ft_is_tube(char *str)
{
	if (ft_strchr(str, '-') == NULL)
		return (0);
	return (1);
}

int			ft_is_end(t_lem *st, char *name)
{
	int i;

	i = 0;
	while (i < st->count_room)
	{
		if (ft_strcmp(st->ro[i].name, name) == 0 && st->ro[i].end == 1)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_mark(t_lem *st, char *name)
{
	int	i;

	i = 0;
	while (ft_strcmp(st->ro[i].name, name) != 0)
		i++;
	if (st->ro[i].pass == 1)
		return (1);
	return (0);
}
