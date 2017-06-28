/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:18:47 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 13:09:48 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_identifi_flag(int i, int j, int k, t_printf *var)
{
	if (var->format_split[i].stock[j] == '#')
		var->format_split[i].flag[k] = '#';
	else if (var->format_split[i].stock[j] == ' ')
		var->format_split[i].flag[k] = ' ';
	else if (var->format_split[i].stock[j] == '0')
		var->format_split[i].flag[k] = '0';
	else if (var->format_split[i].stock[j] == '-')
		var->format_split[i].flag[k] = '-';
	else if (var->format_split[i].stock[j] == '+')
		var->format_split[i].flag[k] = '+';
	else
		var->format_split[i].flag[k] = '\0';
}

void		ft_check_flag_width(t_printf *var)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < var->ifor)
	{
		j = 1;
		k = 0;
		while (var->format_split[i].stock[j] != '.' && \
				var->format_split[i].stock[j] != \
				var->format_split[i].prefixe[0] && \
				var->format_split[i].stock[j] != var->format_split[i].type)
		{
			ft_identifi_flag(i, j++, k++, var);
		}
		if (var->format_split[i].flag != '\0')
			j++;
		i++;
	}
}
