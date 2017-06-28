/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:43:33 by gschaetz          #+#    #+#             */
/*   Updated: 2017/03/30 13:51:06 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_iter(uintmax_t n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_uitoa(uintmax_t n)
{
	char			*dest;
	int				i;
	uintmax_t		res;

	i = ft_count_iter(n);
	res = n;
	if (!(dest = ft_strnew(i)))
		return (NULL);
	if (n == 0)
		dest[0] = 0 + 48;
	dest[--i] = res % 10 + 48;
	while (res /= 10)
		dest[--i] = res % 10 + 48;
	return (dest);
}
