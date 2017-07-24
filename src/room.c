/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:02:51 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/24 11:11:14 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			ft_check_room(t_lem *st, char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i] != NULL)
		i++;
	//ft_printf("test = %c\n", tab[0][0]);
	if (ft_strchr(str, '-') != NULL || tab[0][0] == 'L' || i != 3)
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
	st->count_room++;
	return (1);
}

