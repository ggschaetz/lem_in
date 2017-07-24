/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:10:13 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/05 16:32:41 by gschaetz         ###   ########.fr       */
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
	if (i != 3)
		return(0);
	return (1);
}

int			ft_is_tube(char *str)
{
	if (ft_strchr(str, '-') == NULL)
		return (0);
	return (1);
}
