/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:47:08 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:12:40 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_iter_min(uintmax_t val, uintmax_t base)
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

char	*ft_uitoa_base_min(uintmax_t val, uintmax_t base, t_printf *var)
{
	char	*tab;
	char	*res;

	tab = ft_strdup("0123456789abcdef");
	var->uitom = ft_nb_iter_min(val, base);
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
