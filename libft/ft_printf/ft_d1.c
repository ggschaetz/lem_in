/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:20:21 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 16:05:22 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_last_app_d(t_printf *var, char *tmp, char *cp, char type)
{
	char		*f;

	f = var->format_split[var->ich].flag;
	if (ft_strchr(f, '+') != NULL && cp[0] != '-' && type != 'u')
		tmp[0] = '+';
	if (cp[0] == '0' && cp[1] == '\0' && ft_strchr(var->format_split\
				[var->ich].stock, '.') != NULL && \
			var->format_split[var->ich].prec == 0)
		return (tmp);
	tmp = ft_strcat(tmp, cp);
	return (tmp);
}

char		*ft_check_d0(t_printf *var, char *tmp, char *cp)
{
	char		*f;
	int			prec;

	f = var->format_split[var->ich].flag;
	prec = var->format_split[var->ich].prec;
	if (ft_strchr(f, '-') == NULL && \
			(ft_strchr(f, '0') == NULL || prec > var->lenf))
		tmp = ft_space(var, tmp, cp);
	return (tmp);
}

char		*ft_check_d1(t_printf *var, char *tmp, char *cp)
{
	char		*f;
	char		type;

	f = var->format_split[var->ich].flag;
	type = var->format_split[var->ich].type;
	if (ft_strchr(f, '#') != NULL && (type == 'x' || type == 'X'))
		tmp = ft_add_ox(var, tmp, cp);
	return (tmp);
}

char		*ft_check_d2(t_printf *var, char *tmp, char *cp)
{
	char		*f;
	char		type;

	f = var->format_split[var->ich].flag;
	type = var->format_split[var->ich].type;
	if (ft_strchr(f, '#') != NULL && (type == 'o' || type == 'O'))
		tmp = ft_add_oc(var, tmp, cp);
	return (tmp);
}

char		*ft_check_d3(t_printf *var, char *tmp, char *cp, int j)
{
	int			p;
	char		*s;

	s = var->format_split[var->ich].stock;
	p = var->format_split[var->ich].prec;
	if (cp[0] == '0' && cp[1] == '\0' && ft_strchr(s, '.') != NULL && p == 0)
	{
		tmp[var->ct] = ' ';
		return (tmp);
	}
	while (j < var->lenf_s && cp[j] != '\0')
		tmp[var->ct++] = cp[j++];
	return (tmp);
}
