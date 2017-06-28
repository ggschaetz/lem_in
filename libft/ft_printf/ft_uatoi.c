/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:45:31 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/07 15:50:47 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_uatoi(const char *str)
{
	int			i;
	uintmax_t	res;

	i = 0;
	res = 0;
	while ((str[i] == '\r' || str[i] == '\t' || str[i] == '\f' || str[i] \
				== '\v' || str[i] == '\n' || str[i] == ' ') && str[i] != '\0')
		i++;
	if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
