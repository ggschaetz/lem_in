/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_lc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:36:52 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/10 17:10:12 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_one(t_printf *var, wchar_t uni)
{
	unsigned char conv;

	conv = (uni & 0x7F) | 0x0;
	write(1, &conv, 1);
	var->nbc += 1;
}

void		ft_two(t_printf *var, wchar_t uni)
{
	unsigned char conv;
	unsigned char conv1;

	conv = (uni >> 6) | 0xC0;
	conv1 = (uni & 0x3F) | 0x80;
	write(1, &conv, 1);
	write(1, &conv1, 1);
	var->nbc += 2;
}

void		ft_three(t_printf *var, wchar_t uni)
{
	unsigned char conv;
	unsigned char conv1;
	unsigned char conv2;

	conv = (uni >> 12) | 0xE0;
	conv1 = ((uni >> 6) & 0x3F) | 0x80;
	conv2 = (uni & 0x3F) | 0x80;
	write(1, &conv, 1);
	write(1, &conv1, 1);
	write(1, &conv2, 1);
	var->nbc += 3;
}

void		ft_four(t_printf *var, wchar_t uni)
{
	unsigned char conv;
	unsigned char conv1;
	unsigned char conv2;
	unsigned char conv3;

	conv = (uni >> 18) | 0xF0;
	conv1 = (((uni >> 12) & 0x3F) | 0x80);
	conv2 = (((uni >> 6) & 0x3F) | 0x80);
	conv3 = (uni & 0x3F) | 0x80;
	write(1, &conv, 1);
	write(1, &conv1, 1);
	write(1, &conv2, 1);
	write(1, &conv3, 1);
	var->nbc += 4;
}
