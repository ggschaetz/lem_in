/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 07:32:43 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 13:10:36 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_nb_p(t_printf *var, char *cp)
{
	char	*tmp;
	int		width;
	int		prec;

	width = var->format_split[var->ich].width;
	prec = var->format_split[var->ich].prec;
	tmp = ft_strnew(width + prec + (int)ft_strlen(cp));
	var->itp = 0;
	ft_appli_flag_prec_nb(var, cp, tmp);
	ft_putnstr(tmp, 0, ft_strlen(tmp), var);
	free(tmp);
}

void		ft_d(t_printf *var, va_list *ap)
{
	char		*cp;
	char		*tmp;
	char		type;

	type = var->format_split[var->ich].type;
	if (type == 'u' || type == 'U')
		tmp = ft_uitoa(ft_check_prefixe_u(var, ap));
	else if (type == 'x')
		tmp = ft_uitoa_base_min(ft_check_prefixe_u(var, ap), 16, var);
	else if (type == 'X')
		tmp = ft_uitoa_base_maj(ft_check_prefixe_u(var, ap), 16, var);
	else if (type == 'o')
		tmp = ft_uitoa_base_min(ft_check_prefixe_u(var, ap), 8, var);
	else if (type == 'O')
		tmp = ft_uitoa_base_maj(ft_check_prefixe_u(var, ap), 8, var);
	else
		tmp = ft_iitoa(ft_check_prefixe(var, ap));
	cp = ft_strdup(tmp);
	free(tmp);
	ft_nb_p(var, cp);
	free(cp);
}
