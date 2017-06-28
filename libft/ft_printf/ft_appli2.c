/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appli2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:21:59 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 19:01:23 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_add_ox(t_printf *var, char *tmp, char *cp)
{
	char	type;
	int		prec;

	type = var->format_split[var->ich].type;
	prec = var->format_split[var->ich].prec;
	if (ft_strchr(var->format_split[var->ich].stock, '.') != NULL && \
			prec == 0 && var->format_split[var->ich].width == 0 && \
			ft_strchr(var->format_split[var->ich].flag, 'p') == NULL)
	{
		return (tmp);
	}
	if (cp[0] == '0' && cp[1] == '\0' && \
			ft_strchr(var->format_split[var->ich].flag, 'p') == NULL)
	{
		tmp[0] = '0';
		tmp[1] = '\0';
		return (tmp);
	}
	tmp = ft_add_ox1(var, tmp, cp);
	return (tmp);
}

int			ft_check_lenf(char *cp, t_printf *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strchr(var->format_split[var->ich].flag, '+') != NULL \
			|| cp[0] == '-')
		i++;
	while (cp[i++] != '\0')
		j++;
	return (j);
}

int			ft_check_lenf_signe(char *cp, t_printf *var)
{
	int		j;
	int		i;
	char	*flag;

	j = 0;
	i = 0;
	flag = var->format_split[var->ich].flag;
	if (ft_strchr(flag, '+') != NULL && cp[0] != '-')
		j++;
	while (cp[i++] != '\0')
		j++;
	return (j);
}

int			ft_check_signe(t_printf *var, char *cp, char *tmp, int j)
{
	char	*flag;

	flag = var->format_split[var->ich].flag;
	if (ft_strchr(flag, '+') != NULL || cp[0] == '-')
	{
		if (cp[0] == '-')
		{
			tmp[var->ct++] = '-';
			j++;
		}
		else
			tmp[var->ct++] = '+';
	}
	return (j);
}

char		*ft_add_space(char *tmp, char *cp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (cp[i] != '-')
		tmp[i++] = ' ';
	while (cp[j] != '\0')
		tmp[i++] = cp[j++];
	return (tmp);
}
