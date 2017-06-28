/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 07:44:05 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 19:13:13 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_distrib_d(t_printf *var, char *tmp, char *cp, char type)
{
	int		width;
	char	*f;

	width = var->format_split[var->ich].width;
	f = var->format_split[var->ich].flag;
	if (ft_strchr(f, ' ') != NULL && ft_strchr(f, '+') == NULL && \
			ft_strchr(f, '-') == NULL && ft_strchr(f, '#') == NULL && \
			ft_strchr(f, '0') == NULL && var->format_split[var->ich].prec == 0 \
			&& width == 0 && type != 'u')
		tmp = ft_add_space(tmp, cp);
	else if (width >= var->format_split[var->ich].prec && width != 0)
		tmp = ft_appli_width_nb(var, cp, tmp);
	else if (var->format_split[var->ich].prec > var->lenf)
		tmp = ft_appli_prec_nb(var, cp, tmp);
	else if (ft_strchr(f, '#') != NULL && (type == 'x' || type == 'X'))
		tmp = ft_add_ox(var, tmp, cp);
	else if (ft_strchr(f, '#') != NULL && (type == 'o' || type == 'O'))
		tmp = ft_add_oc(var, tmp, cp);
	else
		tmp = ft_last_app_d(var, tmp, cp, type);
	return (tmp);
}

char		*ft_appli_flag_prec_nb(t_printf *var, char *cp, char *tmp)
{
	int		prec;
	int		width;
	char	*flag;
	char	type;

	var->ct = 0;
	prec = var->format_split[var->ich].prec;
	width = var->format_split[var->ich].width;
	flag = var->format_split[var->ich].flag;
	type = var->format_split[var->ich].type;
	var->lenf_s = ft_check_lenf_signe(cp, var);
	var->lenf = ft_check_lenf(cp, var);
	tmp = ft_distrib_d(var, tmp, cp, type);
	return (tmp);
}

char		*ft_appli_prec_nb(t_printf *var, char *cp, char *tmp)
{
	int		j;
	int		prec;
	int		lenf;
	int		i;

	j = 0;
	i = 0;
	var->ct = 0;
	lenf = var->lenf;
	prec = var->format_split[var->ich].prec;
	j = ft_check_signe(var, cp, tmp, j);
	if (j == 1)
		prec++;
	if (ft_strchr(var->format_split[var->ich].flag, ' ') != NULL)
	{
		tmp[var->ct++] = ' ';
		i++;
	}
	i = ft_call_add_ox(var, i, tmp, cp);
	while (var->ct < prec + i - lenf)
		tmp[var->ct++] = '0';
	while (cp[j] != '\0')
		tmp[var->ct++] = cp[j++];
	return (tmp);
}

char		*ft_zero(t_printf *var, char *tmp, char *cp)
{
	int		max;

	max = var->format_split[var->ich].width - var->lenf;
	if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL || \
			cp[0] == '-')
	{
		if (var->format_split[var->ich].prec > var->lenf)
			max = var->format_split[var->ich].width - \
				var->format_split[var->ich].prec;
		if (cp[0] != '-')
			max -= 1;
	}
	if (var->format_split[var->ich].flag[0] == ' ')
		tmp[var->ct++] = ' ';
	while (var->ct < max)
	{
		if (var->format_split[var->ich].prec <= var->lenf && \
				ft_strchr(var->format_split[var->ich].stock, '.') != NULL)
			tmp[var->ct++] = ' ';
		else
			tmp[var->ct++] = '0';
	}
	return (tmp);
}

char		*ft_appli_width_nb(t_printf *var, char *cp, char *tmp)
{
	int		len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	len = ft_len_width(var, cp);
	tmp = ft_check_d0(var, tmp, cp);
	tmp = ft_check_d1(var, tmp, cp);
	tmp = ft_check_d2(var, tmp, cp);
	j = ft_check_signe(var, cp, tmp, j);
	if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
	{
		if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL ||\
				cp[0] == '-')
			len--;
		tmp = ft_width_neg(var, len, tmp, cp);
	}
	else if (ft_strchr(var->format_split[var->ich].flag, '0') != NULL)
		tmp = ft_zero(var, tmp, cp);
	if (var->format_split[var->ich].prec > var->lenf)
		ft_prec_zero(var, tmp);
	tmp = ft_check_d3(var, tmp, cp, j);
	return (tmp);
}
