/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:45:25 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 12:55:18 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_size_percent(t_printf *var)
{
	int size;

	size = 1;
	if (var->format_split[var->ich].width > size)
		size = var->format_split[var->ich].width;
	return (size);
}

char		*ft_add_space_percent(t_printf *var, char *tmp, int size)
{
	char	*flag;

	flag = var->format_split[var->ich].flag;
	while (var->ct < (size - 1))
	{
		if (ft_strchr(flag, '0') != NULL && ft_strchr(flag, '-') == NULL)
			tmp[var->ct++] = '0';
		else
			tmp[var->ct++] = ' ';
	}
	return (tmp);
}

char		*ft_modif_percent(t_printf *var, char *tmp, int size)
{
	int		i;
	char	*flag;

	i = 0;
	flag = var->format_split[var->ich].flag;
	if (ft_strchr(flag, '-') == NULL)
		tmp = ft_add_space_percent(var, tmp, size);
	tmp[var->ct++] = '%';
	if (ft_strchr(flag, '-') != NULL)
		tmp = ft_add_space_percent(var, tmp, size + 1);
	return (tmp);
}

void		ft_percent(t_printf *var, va_list *ap)
{
	int		size;
	char	*tmp;

	if (ap)
		tmp = NULL;
	var->ct = 0;
	size = ft_size_percent(var);
	tmp = ft_strnew(size);
	tmp = ft_modif_percent(var, tmp, size);
	ft_putnstr(tmp, 0, size, var);
	free(tmp);
}
