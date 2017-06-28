/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:04:30 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 12:03:51 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parce_format(const char *format, t_printf *var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	var->ret = 0;
	if (ft_strchr(format, '%') == NULL)
	{
		ft_putnstr((char *)format, 0, ft_strlen(format), var);
		ft_free(var);
	}
	while (var->ret < var->len_format && ft_strchr(format, '%') != NULL)
	{
		var->flag = 0;
		ft_stock_str(format, var);
		var->start = var->ret;
		if (var->ret < var->len_format)
			ft_stock_format(format, var);
		var->ret++;
	}
	if (var->istr == 1 && var->ifor == 0)
	{
		ft_putstr(format);
		ft_free(var);
	}
}
