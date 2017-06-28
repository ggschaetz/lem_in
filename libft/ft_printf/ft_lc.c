/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:09:40 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 13:06:53 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nboct(char *nbc)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(nbc);
	if (len <= 7)
		i = 1;
	else if (len <= 11)
		i = 2;
	else if (len <= 16)
		i = 3;
	else if (len <= 21)
		i = 4;
	else
		i = -1;
	return (i);
}

int			ft_size_tmp_lc(t_printf *var, int nboct)
{
	int i;

	i = 1;
	if (nboct < var->format_split[var->ich].width)
		i = var->format_split[var->ich].width - nboct;
	if (i != 1)
		var->nbc += i;
	return (i);
}

void		ft_space_lc(int size)
{
	int i;

	i = 0;
	if (size == 1)
		return ;
	while (i < size)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_lc(t_printf *var, va_list *ap)
{
	wchar_t		nb;
	int			nboct;
	int			size;
	wchar_t		uni;
	char		*stock;

	nb = va_arg(*ap, wchar_t);
	uni = nb;
	stock = ft_uitoa_base_min(nb, 2, var);
	nboct = ft_nboct(stock);
	size = ft_size_tmp_lc(var, nboct);
	if (ft_strchr(var->format_split[var->ich].flag, '-') == NULL)
		ft_space_lc(size);
	if (nboct == 1)
		ft_one(var, uni);
	else if (nboct == 2)
		ft_two(var, uni);
	else if (nboct == 3)
		ft_three(var, uni);
	else if (nboct == 4)
		ft_four(var, uni);
	if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
		ft_space_lc(size);
	free(stock);
}
