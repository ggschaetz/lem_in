/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:12:17 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/10 17:37:53 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strclr_ret(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		s[i++] = '\0';
	return (s);
}

void		ft_p(t_printf *var, va_list *ap)
{
	char		*pref;
	char		*flag;

	pref = var->format_split[var->ich].prefixe;
	flag = var->format_split[var->ich].flag;
	var->format_split[var->ich].type = 'x';
	pref = ft_strcat(ft_strclr_ret(pref), "l\0");
	flag = ft_strcat(flag, "#p\0");
	ft_d(var, ap);
}

void		ft_ld(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}

void		ft_o(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}

void		ft_lo(t_printf *var, va_list *ap)
{
	ft_d(var, ap);
}
