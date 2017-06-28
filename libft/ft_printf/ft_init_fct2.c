/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:14:58 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 13:08:18 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_u(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}

void		ft_lu(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}

void		ft_x(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}

void		ft_lx(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}
