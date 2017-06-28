/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_constant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:49:06 by gschaetz          #+#    #+#             */
/*   Updated: 2017/06/27 11:41:39 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_len_max_line(t_lem *st, char *line)
{
	int size;

	size = ft_strlen(line);
	if (size > st->len_max_line)
		st->len_max_line = size;
}

