/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:03:57 by gschaetz          #+#    #+#             */
/*   Updated: 2017/03/31 11:32:54 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_iter(intmax_t n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_iitoa(intmax_t n)
{
	char		*dest;
	int			i;
	uintmax_t	res;

	i = ft_count_iter(n);
	res = n;
	if (n < 0)
	{
		res = -n;
		i++;
	}
	if (!(dest = ft_strnew(i)))
		return (NULL);
	if (n == 0)
		dest[0] = 0 + 48;
	dest[--i] = res % 10 + 48;
	while (res /= 10)
		dest[--i] = res % 10 + 48;
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
