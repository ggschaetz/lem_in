/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 09:54:39 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 15:04:59 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_size_s(t_printf *var, char *s)
{
	int width;
	int	prec;
	int	size;
	int	len;

	size = 0;
	len = (int)ft_strlen(s);
	width = var->format_split[var->ich].width;
	prec = var->format_split[var->ich].prec;
	if (len == 0)
		size = width;
	else if (prec >= len && width <= len)
		size = len;
	else if (width > len || (prec < len && width > prec))
		size = width;
	else if (prec < len && prec > width && prec != 0)
		size = prec;
	else if (prec == 0 && width == 0)
		size = len;
	else if (prec >= width && prec > len)
		size = prec;
	else
		size = width;
	return (size);
}

char		*ft_add_space_s(t_printf *var, char *tmp, char *cp, int size)
{
	int		prec;
	int		width;
	int		len;
	int		i;
	int		len_cp;

	i = 0;
	prec = var->format_split[var->ich].prec;
	width = var->format_split[var->ich].width;
	len_cp = (int)ft_strlen(cp);
	if ((prec > 0 && prec <= len_cp) || \
			(ft_strchr(var->format_split[var->ich].stock, '.') != NULL && \
			prec <= len_cp))
		len = ft_abs(width - prec);
	else
		len = ft_abs(width - len_cp);
	if (width >= size)
	{
		while (i < len)
		{
			tmp[var->ct++] = ' ';
			i++;
		}
	}
	return (tmp);
}

char		*ft_add_prec_s(t_printf *var, char *tmp, char *cp)
{
	int		prec;
	int		i;

	i = 0;
	prec = var->format_split[var->ich].prec;
	if (prec > 0 && prec <= (int)ft_strlen(cp))
	{
		while (i < prec)
		{
			tmp[var->ct++] = cp[i++];
		}
	}
	else
	{
		while (cp[i] != '\0')
			tmp[var->ct++] = cp[i++];
	}
	return (tmp);
}

char		*ft_modif_s(t_printf *var, int size, char *cp, char *tmp)
{
	tmp = ft_strnew(size);
	if (ft_strchr(var->format_split[var->ich].flag, '-') == NULL)
		tmp = ft_add_space_s(var, tmp, cp, size);
	tmp = ft_add_prec_s(var, tmp, cp);
	if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
		tmp = ft_add_space_s(var, tmp, cp, size);
	return (tmp);
}

void		ft_s(t_printf *var, va_list *ap)
{
	char	*s;
	char	*tmp;
	char	*cp;

	s = NULL;
	tmp = NULL;
	var->ct = 0;
	cp = NULL;
	if (ft_strcmp(var->format_split[var->ich].prefixe, "l\0") == 0)
	{
		ft_ls(var, ap);
		free(tmp);
		return ;
	}
	s = (char *)va_arg(*ap, char *);
	if (s == NULL)
	{
		tmp = ft_strdup("(null)\0");
		var->nbc += 6;
		ft_putstr(tmp);
		free(tmp);
		return ;
	}
	ft_put_s(tmp, cp, var, s);
}
