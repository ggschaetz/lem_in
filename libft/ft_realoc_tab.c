/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:13:38 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/05 11:04:51 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_new_tab(char *str)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i++] = NULL;
	}
	free(tab);
	tab = NULL;
}

char	**ft_realoc_tab(char **tab, char *str)
{
	int		i;
	int		j;
	char	**cpy;
	
	i = 0;
	j = 0;
	if (!(tab))
		return (ft_new_tab(str));
	while (tab[i])
		i++;
	if (!(cpy = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i++] = ft_strdup(str);
	cpy[i] = NULL;
	free_tab(tab);
	return (cpy);
}

