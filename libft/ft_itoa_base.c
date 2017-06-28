/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:53:50 by gschaetz          #+#    #+#             */
/*   Updated: 2017/03/30 15:54:52 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nb_iter(int val, int base)
{
	int i;

	i = 0;
	if (val < 0)
		val = val * -1;
	while (val >= base)
	{
		val = val / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int val, int base)
{
	char	*tab;
	char	*res;
	int		iter;

	tab = strdup("0123456789abcdef");
	iter = ft_nb_iter(val, base);
	res = ft_strnew(iter + 1);
	if (base < 2 || base > 16 || val == 0)
		return ("0\0");
	if (base == 10 && val < 0)
		iter++;
	val = (val < 0) ? val * -1 : val;
	res[0] = '-';
	while (val != 0)
	{
		res[iter--] = tab[val % base];
		val = val / base;
	}
	return (res);
}
