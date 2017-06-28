/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_format_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:07:43 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 12:06:09 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_stock_str(const char *format, t_printf *var)
{
	int	i;

	i = 0;
	while (format[var->ret] != '%' && format[var->ret] != '\0')
		var->str_stock[var->istr].str[i++] = format[var->ret++];
	var->str_stock[var->istr].str[i] = '\0';
	var->istr++;
}

void		ft_stock_format(char const *format, t_printf *var)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (var->flag == 0)
	{
		var->ret++;
		var->flag = 1;
	}
	while (format[var->ret] != var->tab[i] && var->tab[i] != '\0' \
			&& format[var->ret] != '\0')
		i++;
	if (format[var->ret] != '\0' && format[var->ret] != var->tab[i])
	{
		var->ret++;
		ft_stock_format(format, var);
	}
	else if (format[var->ret] != '\0' && format[var->ret] == var->tab[i])
	{
		while (var->start <= var->ret && format[var->start] != '\0')
			var->format_split[var->ifor].stock[x++] = format[var->start++];
		var->format_split[var->ifor].stock[x] = '\0';
		var->ifor++;
	}
}
