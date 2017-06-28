/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:12:09 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 13:05:35 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_tmp_ls(t_printf *var, wchar_t *nb)
{
	int		i;
	int		size;
	int		tot;
	char	*stock;

	i = 0;
	tot = 0;
	size = 0;
	while (nb[i] != '\0')
	{
		stock = ft_uitoa_base_min(nb[i], 2, var);
		tot = ft_nboct(stock) + tot;
		free(stock);
		i++;
	}
	if (var->format_split[var->ich].width > tot)
		size = var->format_split[var->ich].width - tot;
	if (var->format_split[var->ich].prec == 0 && \
			ft_strchr(var->format_split[var->ich].stock, '.') != NULL)
		size = var->format_split[var->ich].width;
	var->nbc += size;
	return (size);
}

void	ft_distrib_ls(t_printf *var, wchar_t *nb)
{
	char		*stock;
	int			nboct;
	int			i;

	i = 0;
	while (nb[i] != '\0' && \
			ft_strchr(var->format_split[var->ich].stock, '.') == NULL)
	{
		stock = ft_uitoa_base_min(nb[i], 2, var);
		nboct = ft_nboct(stock);
		if (nboct == 1)
			ft_one(var, nb[i]);
		else if (nboct == 2)
			ft_two(var, nb[i]);
		else if (nboct == 3)
			ft_three(var, nb[i]);
		else if (nboct == 4)
			ft_four(var, nb[i]);
		free(stock);
		i++;
	}
}

void	ft_ls(t_printf *var, va_list *ap)
{
	wchar_t		*nb;
	int			size;

	nb = va_arg(*ap, wchar_t *);
	if (nb == NULL)
	{
		ft_putstr("(null)\0");
		var->nbc += 6;
		return ;
	}
	size = ft_size_tmp_ls(var, nb);
	if (ft_strchr(var->format_split[var->ich].flag, '-') == NULL)
		ft_space_lc(size);
	ft_distrib_ls(var, nb);
	if (ft_strchr(var->format_split[var->ich].flag, '-') != NULL)
		ft_space_lc(size);
}
