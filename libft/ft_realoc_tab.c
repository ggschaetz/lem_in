/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:13:38 by gschaetz          #+#    #+#             */
/*   Updated: 2017/06/28 11:51:09 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realoc_tab(char **tab, int size_x, int size_y)
{
	int		i;
	int		j;
	char	**cpy;
	
	i = 0;
	j = 0;
	if (!(cpy = (char **)malloc(sizeof(char *) * (size_x + 1))))
		return (NULL);
	while (i < size_x)
		cpy[i++] = ft_memalloc(size_y);
	cpy[i] = NULL;
	i = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			cpy[i][j] = tab[i][j];
			j++;
		}
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (cpy);
}

