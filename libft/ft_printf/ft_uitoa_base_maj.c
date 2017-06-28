/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:27:22 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:12:30 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_uitoa_base_maj(uintmax_t val, uintmax_t base, t_printf *var)
{
	char	*tab;
	char	*res;

	tab = ft_strdup("0123456789ABCDEF");
	var->uitom = ft_nb_iter(val, base);
	res = ft_strnew(var->uitom + 3);
	if (base < 2 || base > 16 || val == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (val != 0)
	{
		res[var->uitom--] = tab[val % base];
		val = val / base;
	}
	free(tab);
	return (res);
}
