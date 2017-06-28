/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:56:46 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:13:13 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_iter(uintmax_t val, uintmax_t base)
{
	int i;

	i = 0;
	while (val >= base)
	{
		val = val / base;
		i++;
	}
	return (i);
}

char	*ft_uitoa_base(uintmax_t val, uintmax_t base)
{
	char	*tab;
	char	*res;
	int		iter;

	tab = ft_strdup("0123456789abcdef");
	iter = ft_nb_iter(val, base);
	res = ft_strnew(iter + 1);
	if (base < 2 || base > 16 || val == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (val != 0)
	{
		res[iter--] = tab[val % base];
		val = val / base;
	}
	return (res);
}
