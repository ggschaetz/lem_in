/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:51:03 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:58:09 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnstr(char *str, int min, int len, t_printf *var)
{
	while (min < len)
	{
		var->nbc += 1;
		ft_putchar(str[min++]);
	}
}

void		ft_convertion(t_printf *var, va_list *ap)
{
	int i;
	int j;

	i = 0;
	var->ox = 0;
	while (i < var->ifor)
	{
		j = 0;
		var->ich = i;
		var->str_stock[i].lens = ft_strlen(var->str_stock[i].str);
		while (var->format_split[i].type != var->tab_fct[j].c)
			j++;
		ft_putnstr(var->str_stock[i].str, 0, var->str_stock[i].lens, var);
		var->tab_fct[j].f(var, ap);
		i++;
	}
	var->str_stock[i].lens = ft_strlen(var->str_stock[i].str);
	if (var->str_stock[i].str)
		ft_putnstr(var->str_stock[i].str, 0, var->str_stock[i].lens, var);
}
