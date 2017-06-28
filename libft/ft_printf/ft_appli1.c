/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appli1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:08:28 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 14:25:19 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_width_neg(t_printf *var, int len, char *tmp, char *cp)
{
	int	min;
	int	i;

	i = 0;
	min = var->format_split[var->ich].prec - var->lenf_s;
	if (var->format_split[var->ich].prec < var->lenf)
	{
		while (cp[i] != '\0')
			i++;
		min = i - 1;
	}
	while (len > min)
		tmp[len--] = ' ';
	return (tmp);
}

int			ft_len_width(t_printf *var, char *cp)
{
	int	len;

	len = var->format_split[var->ich].width - 1;
	if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL \
			|| cp[0] == '-')
		len = var->format_split[var->ich].width;
	return (len);
}

char		*ft_prec_zero(t_printf *var, char *tmp)
{
	int max;

	max = var->format_split[var->ich].width - var->lenf;
	if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL)
		max--;
	if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
		max = var->format_split[var->ich].prec - var->lenf;
	while (var->ct < max)
		tmp[var->ct++] = '0';
	return (tmp);
}

int			ft_choice(t_printf *var, char *cp)
{
	int		ox;
	char	*flag;
	char	type;

	ox = 0;
	flag = var->format_split[var->ich].flag;
	type = var->format_split[var->ich].type;
	if (ft_strchr(flag, '#') != NULL && (type == 'x' || type == 'X'))
		ox = 2;
	if (var->lenf_s > var->format_split[var->ich].prec)
	{
		if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL \
				|| cp[0] == '-')
			return (var->lenf_s - 1 + ox);
		else
			return (var->lenf_s + ox);
	}
	else
		return (var->format_split[var->ich].prec + ox);
}

char		*ft_space(t_printf *var, char *tmp, char *cp)
{
	int i;

	i = ft_choice(var, cp);
	if (var->format_split[var->ich].width > var->lenf_s)
	{
		if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
			i = 0;
		if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL \
				|| cp[0] == '-' || \
				((ft_strchr(var->format_split[var->ich].flag, '#') != NULL) && \
				(var->format_split[var->ich].type == 'o' || \
				var->format_split[var->ich].type == 'O')))
			i++;
		while (var->ct < (var->format_split[var->ich].width - i))
		{
			tmp[var->ct++] = ' ';
		}
	}
	return (tmp);
}
