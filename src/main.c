/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:49:25 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/24 11:10:19 by gschaetz         ###   ########.fr       */
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
	if (!(st->tab_line = (char **)malloc(sizeof(char *) + 1)))
		return ;
	st->tab_line[0] = NULL;
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
		//ft_printf("len max = %d\n", st->len_max_line);
		//ft_printf("nb->row = %d\n", st->nb_row);

		if (ft_checker(st, line) == 1)
		{

				st->tab_line = ft_realoc_tab(st->tab_line, line);
				st->nb_row++;
				//ft_printf("row  = %d\n", st->nb_row);
		}
		else
			break;
		//ft_printf(" line :%s\n", line);
		free(line);
	}
	int y;
	y = 0;
/*	while (st->tab_line[y] != NULL)
	{
		ft_printf("tab_line[%d] = %s\n", y, st->tab_line[y]);
		y++;
	}
	ft_printf("start = %d\n", st->flag_start);*/
	ft_free_struct(st);
	return (0);
}
