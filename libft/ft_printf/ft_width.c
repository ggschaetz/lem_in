/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:19:15 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 12:17:47 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_stock_in_tmp(t_printf *var, int j, int i, char *tmp)
{
	int		k;
	char	*st;

	k = 0;
	st = var->format_split[i].stock;
	while (ft_isdigit(st[j]) == 1)
		tmp[k++] = st[j++];
	tmp[k] = '\0';
	return (tmp);
}

void		ft_identifi_width(int i, int j, t_printf *var)
{
	char	*tmp;
	int		k;
	char	*st;

	k = 0;
	st = var->format_split[i].stock;
	tmp = ft_strnew(10);
	var->format_split[i].width = 0;
	while (ft_isdigit(st[j]) != 1 && st[j] != '\0')
		j++;
	if (st[j] == '\0' || st[j - 1] == '.')
	{
		free(tmp);
		return ;
	}
	while (st[j] == '0' || st[j] == ' ' || st[j] == '+' || st[j] == '-')
		j++;
	if (ft_isdigit(st[j]) == 1)
		tmp = ft_stock_in_tmp(var, j, i, tmp);
	if (tmp[0] == '\0')
		var->format_split[i].width = 0;
	else
		var->format_split[i].width = ft_atoi(tmp);
	free(tmp);
}
