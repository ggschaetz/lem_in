/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appli3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 09:30:19 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:08:14 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_abs(int nb)
{
	if (nb > 0)
		return (nb);
	return (nb * -1);
}

char		*ft_add_oc(t_printf *var, char *tmp, char *cp)
{
	char	type;
	int		prec;

	type = var->format_split[var->ich].type;
	prec = var->format_split[var->ich].prec;
	if (cp[0] == '0' && cp[1] == '\0')
	{
		tmp[0] = '0';
		tmp[1] = '\0';
		return (tmp);
	}
	if (type == 'O' || type == 'o')
		tmp[var->ct++] = '0';
	if (prec == 0)
		tmp = ft_strcat(tmp, cp);
	return (tmp);
}
