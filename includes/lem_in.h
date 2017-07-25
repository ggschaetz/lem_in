/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:50:18 by gschaetz          #+#    #+#             */
/*   Updated: 2017/07/25 17:34:28 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct		s_ro
{
	int				start;
	int				end;
	char			*name;
	int				x;
	int				y;
}					t_ro;

typedef struct		s_tu
{
	char			*name1;
	char			*name2;
}					t_tu;

typedef struct		s_lem
{
	char			**tab_line;
	char			**cpy;
	int				len_max_line;
	int				nb_row;
	int				nb_ants;
	int				flag_gnl;
	int				flag_start;
	int				flag_end;
	int				id_start;
	int				id_end;
	int				count_room;
	int				count_tube;
	int				time_tube;
	int				after_start;
	int				after_end;
	t_ro			*ro;
	t_tu			*tu;
}					t_lem;

int					last_check(t_lem *st);
int					ft_is_comment(char *str);
int					ft_is_room(char *str);
int					ft_is_tube(char *str);
int					ft_check_tube(t_lem *st, char *line);
int					ft_check_room(t_lem *st, char *str);
void				ft_free_struct(t_lem *s);
int					ft_line_isdigit(char *line);
void				ft_len_max_line(t_lem *st, char *line);
int					ft_checker(t_lem *st, char *line);


#endif
