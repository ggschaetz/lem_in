/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:17:32 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 13:44:28 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void		**ft_malloc_tab(int size_y, int size_x)
{
	void	**tab;
	int		i;

	tab = NULL;
	i = 0;
	if (!(tab = (void **)malloc(sizeof(void *) * (size_x + 1))))
		return (NULL);
	while (i < size_x)
	{
		if (!(tab[i] = (void *)malloc(sizeof(void) * (size_y + 1))))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
