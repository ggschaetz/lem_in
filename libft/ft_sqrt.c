/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:58:22 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/22 16:44:01 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int n;
	int res;

	n = 0;
	res = 0;
	if (nb == 1)
		res = 1;
	while (n * n < nb && n <= (nb / 2))
	{
		res = n;
		n++;
	}
	if (n * n == nb)
		res = n;
	else
		res = 0;
	return (res);
}
