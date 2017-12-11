/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:22:59 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 16:45:51 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**ft_enfiler(char **file, char *name, int i)
{
	file[i] = ft_strcpy(file[i], name);
	return (file);
}

char		**ft_defiler(t_lem *st, char **file, int i)
{
	while (i < st->count_room - 1)
	{
		file[i] = ft_strcpy(file[i], file[i + 1]);
		i++;
	}
	return (file);
}

char		**ft_initialise_bfs(t_lem *st, char **file, char *name, int i)
{
	file = (char **)ft_malloc_tab(st->len_max_line, st->count_room);
	file = ft_enfiler(file, name, i);
	ft_marquer(st, name);
	return (file);
}

int			ft_mise_a_la_norme(char **file, int i)
{
	while (ft_strcmp(file[i], "") != 0)
		i++;
	return (i);
}

void		ft_bfs(t_lem *st, int i, char *name)
{
	char	**file;
	int		y;
	char	*fils;

	file = ft_initialise_bfs(st, NULL, name, i);
	while (ft_file_empty(st, file) == 0 && ft_is_end(st, name) == 0)
	{
		y = 0;
		i = 0;
		name = ft_strcpy(name, file[i]);
		file = ft_defiler(st, file, i);
		while (y < st->count_tube)
		{
			fils = ft_fils(st, name, y);
			if (fils != NULL && ft_is_mark(st, fils) == 0)
			{
				ft_marquer(st, fils);
				i = ft_mise_a_la_norme(file, i);
				file = ft_enfiler(file, fils, i);
				i++;
			}
			y++;
		}
	}
	ft_free_file(st, file);
}
