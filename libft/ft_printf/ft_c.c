/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 07:52:58 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:07:50 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_size_c(t_printf *var)
{
	int size;

	size = var->format_split[var->ich].width;
	if (size == 0)
		size = 1;
	return (size);
}

char		*ft_add_space_c(t_printf *var, char *tmp, int size)
{
	int i;

	i = 1;
	if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
		i = 0;
	while (var->ct < size - i)
		tmp[var->ct++] = ' ';
	return (tmp);
}

char		*ft_modif_c(t_printf *var, int c, int size)
{
	char	*tmp;
	char	*flag;

	flag = var->format_split[var->ich].flag;
	tmp = ft_strnew(size);
	if (ft_strchr(flag, '-') == NULL)
		tmp = ft_add_space_c(var, tmp, size);
	tmp[var->ct++] = c;
	if (ft_strchr(flag, '-') != NULL)
		tmp = ft_add_space_c(var, tmp, size);
	return (tmp);
}

void		ft_c(t_printf *var, va_list *ap)
{
	int		c;
	char	*tmp;
	int		size;

	var->ct = 0;
	if (ft_strcmp(var->format_split[var->ich].prefixe, "l\0") == 0)
	{
		ft_lc(var, ap);
		return ;
	}
	c = va_arg(*ap, int);
	size = ft_size_c(var);
	tmp = ft_modif_c(var, c, size);
	ft_putnstr(tmp, 0, size, var);
	free(tmp);
}
