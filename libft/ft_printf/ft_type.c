/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:47:14 by gschaetz          #+#    #+#             */
/*   Updated: 2017/03/13 14:08:54 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_type(t_printf *var, int i)
{
	int j;

	j = 0;
	while (var->format_split[i].stock[j] != '\0')
		j++;
	return (var->format_split[i].stock[j - 1]);
}
