/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:00:39 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 18:51:09 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free(t_printf *var)
{
	int i;

	i = 0;
	while (i < var->len_format)
	{
		free(var->format_split[i].stock);
		free(var->format_split[i].prefixe);
		free(var->format_split[i].flag);
		free(var->str_stock[i].str);
		i++;
	}
	free(var->str_stock);
	free(var->format_split);
	free(var->tab_fct);
	free(var->tab);
	free(var->tab_pre);
	free(var);
}

t_printf	*ft_malloc_struct(t_printf *var, int size)
{
	int i;

	i = 0;
	i = 0;
	if (!(var = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	if (!(var->str_stock = (t_st *)malloc(sizeof(t_st) * size)))
		return (NULL);
	if (!(var->format_split = (t_format *)malloc(sizeof(t_format) * size)))
		return (NULL);
	if (!(var->tab_fct = (t_fct *)malloc(sizeof(t_fct) * 15)))
		return (NULL);
	while (i < size)
	{
		var->str_stock[i].str = ft_strnew(size);
		var->format_split[i].stock = ft_strnew(size);
		var->format_split[i].flag = ft_strnew(size);
		var->format_split[i].prefixe = ft_strnew(size);
		i++;
	}
	return (var);
}

t_printf	*ft_init_struct(t_printf *var, char const *format)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(format);
	var = ft_malloc_struct(var, size);
	var->tab_pre = ft_strnew(3);
	var->tab = ft_strdup("sSpdDioOuUxXcC%\0");
	var->istr = 0;
	var->ifor = 0;
	var->nbc = 0;
	var->flag = 0;
	var->len_format = size;
	return (var);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	*var;

	var = NULL;
	if (ft_strcmp((char *)format, "") == 0)
		return (0);
	va_start(ap, format);
	var = ft_init_struct(var, format);
	ft_parce_format(format, var);
	if (var->ifor == 0)
		return (var->nbc);
	ft_check_prefixe_prec(var);
	ft_check_flag_width(var);
	ft_init_fct_tab(var);
	ft_convertion(var, &ap);
	ft_free(var);
	va_end(ap);
	return (var->nbc);
}
