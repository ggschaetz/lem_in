/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:49:25 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:06:01 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_init_structure(t_lem *st)
{
	st->len_max_line = 0;
	st->nb_row = 0;
	st->count_room = 0;
	st->count_tube = 0;
	st->flag_gnl = 0;
	st->flag_start = 0;
	st->flag_end = 0;
	st->time_tube = 0;
	st->id_pr = 0;
	st->flag_parce = 0;
	if (!(st->tab_line = (char **)malloc(sizeof(char *) + 1)))
		return ;
	if (!(st->ro = (t_ro *)malloc(sizeof(t_ro) * 200000)))
		return ;
	if (!(st->tu = (t_tu *)malloc(sizeof(t_tu) * 200000)))
		return ;
	st->tab_line[0] = NULL;
}

void	ft_exit(t_lem *st)
{
	ft_printf("ERROR\n");
	ft_free_struct(st);
	exit(0);
}

void	ft_resolv_end_print(t_lem *st)
{
	ft_resolv(st);
	st->flag_parce = 1;
	ft_print_rez(st);
	ft_free_struct(st);
}

int		main(void)
{
	char	*line;
	int		i;
	t_lem	*st;

	i = 0;
	if (!(st = (t_lem *)malloc(sizeof(t_lem))))
		exit(0);
	ft_init_structure(st);
	while (get_next_line(0, &line) > 0)
	{
		ft_len_max_line(st, line);
		if (ft_checker(st, line) == 1)
		{
			st->tab_line = ft_realoc_tab(st->tab_line, line);
			st->nb_row++;
		}
		else
			break ;
		free(line);
	}
	if (last_check(st) == 0)
		ft_exit(st);
	ft_resolv_end_print(st);
	return (0);
}
