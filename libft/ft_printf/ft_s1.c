/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:30:12 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:15:12 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_put_s(char *tmp, char *cp, t_printf *var, char *s)
{
	int		size;

	size = ft_size_s(var, s);
	cp = ft_strdup(s);
	tmp = ft_modif_s(var, size, cp, tmp);
	ft_putnstr(tmp, 0, size, var);
	free(tmp);
	free(cp);
}
