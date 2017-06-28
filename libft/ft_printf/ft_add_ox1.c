/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ox1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:15:27 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 19:02:48 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_add_ox1(t_printf *var, char *tmp, char *cp)
{
	char	type;
	int		prec;

	type = var->format_split[var->ich].type;
	prec = var->format_split[var->ich].prec;
	if (type == 'X')
	{
		tmp[var->ct++] = '0';
		tmp[var->ct++] = 'X';
	}
	else if (type == 'x')
	{
		tmp[var->ct++] = '0';
		tmp[var->ct++] = 'x';
	}
	if (prec == 0 && ft_strchr(var->format_split[var->ich].flag, 'p') != NULL \
			&& (cp[0] == '0' && cp[1] == '\0') && \
			ft_strchr(var->format_split[var->ich].stock, '.') != NULL)
		;
	else
		tmp = ft_strcat(tmp, cp);
	return (tmp);
}

int			ft_call_add_ox(t_printf *var, int i, char *tmp, char *cp)
{
	if (ft_strchr(var->format_split[var->ich].flag, '#') != NULL && \
			(var->format_split[var->ich].type == 'x' || \
			var->format_split[var->ich].type == 'X'))
	{
		i = 2;
		ft_add_ox(var, tmp, cp);
	}
	return (i);
}
