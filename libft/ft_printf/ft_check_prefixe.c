/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prefixe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:39:56 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:07:20 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_condition1_u(t_printf *var, va_list *ap)
{
	if (var->format_split[var->ich].type == 'U' || \
			var->format_split[var->ich].type == 'O')
		return ((unsigned long)va_arg(*ap, unsigned long));
	else
		return ((unsigned short)(va_arg(*ap, unsigned int)));
}

uintmax_t		ft_check_prefixe_u(t_printf *var, va_list *ap)
{
	if (ft_strcmp(var->format_split[var->ich].prefixe, "hh") == 0)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "h") == 0)
		return (ft_condition1_u(var, ap));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "ll") == 0)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "l") == 0)
		return ((unsigned long)va_arg(*ap, unsigned long));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "j") == 0)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "z") == 0)
		return ((size_t)va_arg(*ap, size_t));
	else
	{
		if (var->format_split[var->ich].type == 'U' || \
				var->format_split[var->ich].type == 'O')
			return ((unsigned long int)va_arg(*ap, unsigned long int));
		else
			return ((unsigned int)va_arg(*ap, unsigned int));
	}
}

intmax_t		ft_check_prefixe(t_printf *var, va_list *ap)
{
	if (ft_strcmp(var->format_split[var->ich].prefixe, "hh") == 0)
		return ((signed char)va_arg(*ap, int));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "h") == 0)
	{
		if (var->format_split[var->ich].type == 'D')
			return ((long)va_arg(*ap, long));
		else
			return ((short)(va_arg(*ap, int)));
	}
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "ll") == 0)
		return ((long long)va_arg(*ap, long long));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "l") == 0)
		return ((long)va_arg(*ap, long));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "j") == 0)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (ft_strcmp(var->format_split[var->ich].prefixe, "z") == 0)
		return ((size_t)va_arg(*ap, size_t));
	else
	{
		if (var->format_split[var->ich].type == 'D')
			return ((long)va_arg(*ap, long));
		else
			return ((int)va_arg(*ap, int));
	}
}
