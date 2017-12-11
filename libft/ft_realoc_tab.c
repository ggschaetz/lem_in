/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:13:38 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:17:01 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_new_tab(char **tab)
{
	int		i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	return (tab);
}

char	**ft_realoc_tab(char **tab, char *str)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	j = 0;
	cpy = NULL;
	if (!(tab))
		tab = ft_new_tab(tab);
	while (tab[i])
		i++;
	if (!(cpy = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	cpy[i++] = ft_strdup(str);
	cpy[i] = NULL;
	free(tab);
	return (cpy);
}
