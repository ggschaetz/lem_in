/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:50:18 by gschaetz          #+#    #+#             */
/*   Updated: 2017/06/27 11:49:51 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct		s_lem
{
	char			**tab_line;
	char			**cpy;
	int				len_max_line;
	int				nb_row;
	int				flag_gnl;
	int				flag_start;
	int				flag_end;
}					t_lem;

void				ft_free_struct(t_lem *s);
int					ft_line_isdigit(char *line);
void				ft_len_max_line(t_lem *st, char *line);
int					ft_checker(t_lem *st, char *line);


#endif
