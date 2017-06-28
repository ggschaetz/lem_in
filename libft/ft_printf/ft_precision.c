/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:18:27 by gschaetz          #+#    #+#             */
/*   Updated: 2017/03/22 16:01:30 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_identifi_prec(int j, int i, t_printf *var)
{
	char	tmp[10];
	int		l;

	l = 0;
	while (var->format_split[i].prefixe[0] == var->format_split[i].stock[j])
		j--;
	if (ft_isdigit(var->format_split[i].stock[j]) != 1)
		var->format_split[i].prec = 0;
	else
	{
		while (ft_isdigit(var->format_split[i].stock[j]) == 1)
			j--;
		if (var->format_split[i].stock[j] != '.')
			var->format_split[i].prec = 0;
		else
		{
			j++;
			while (ft_isdigit(var->format_split[i].stock[j]) == 1)
				tmp[l++] = var->format_split[i].stock[j++];
			tmp[l] = '\0';
			var->format_split[i].prec = ft_atoi(tmp);
		}
	}
}
