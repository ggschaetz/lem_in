/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefixe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:19:49 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 12:54:30 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_identifi_pref(int j, int i, t_printf *var)
{
	if (var->format_split[i].stock[j] == 'h' && \
			var->format_split[i].stock[j - 1] == 'h')
		return ("hh\0");
	else if (var->format_split[i].stock[j] == 'l' && \
			var->format_split[i].stock[j - 1] == 'l')
		return ("ll\0");
	else if (var->format_split[i].stock[j] == 'h')
		return ("h\0");
	else if (var->format_split[i].stock[j] == 'l')
		return ("l\0");
	else if (var->format_split[i].stock[j] == 'j')
		return ("j\0");
	else if (var->format_split[i].stock[j] == 'z')
		return ("z\0");
	else
		return ("\0");
}

void		ft_check_prefixe_prec(t_printf *var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < var->ifor)
	{
		j = 0;
		while (var->format_split[i].stock[j] != '\0')
			j++;
		var->format_split[i].type = ft_type(var, i);
		j -= 2;
		var->format_split[i].prefixe =
		ft_strcat(var->format_split[i].prefixe, ft_identifi_pref(j, i, var));
		ft_identifi_prec(j, i, var);
		ft_identifi_width(i, 0, var);
		i++;
	}
}
