/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fct0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:50:05 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/06 10:45:17 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_i(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}

void		ft_init_fct_tab(t_printf *var)
{
	int i;

	i = 0;
	while (i < 15)
	{
		var->tab_fct[i].c = var->tab[i];
		i++;
	}
	var->tab_fct[0].f = ft_s;
	var->tab_fct[1].f = ft_ls;
	var->tab_fct[2].f = ft_p;
	var->tab_fct[3].f = ft_d;
	var->tab_fct[4].f = ft_ld;
	var->tab_fct[5].f = ft_i;
	var->tab_fct[6].f = ft_o;
	var->tab_fct[7].f = ft_lo;
	var->tab_fct[8].f = ft_u;
	var->tab_fct[9].f = ft_lu;
	var->tab_fct[10].f = ft_x;
	var->tab_fct[11].f = ft_lx;
	var->tab_fct[12].f = ft_c;
	var->tab_fct[13].f = ft_lc;
	var->tab_fct[14].f = ft_percent;
}
