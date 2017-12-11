/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:50:18 by gschaetz          #+#    #+#             */
/*   Updated: 2017/09/06 17:17:44 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_ro
{
	int				start;
	int				end;
	char			*name;
	int				x;
	int				y;
	int				pass;
}					t_ro;

typedef struct		s_tu
{
	char			*name1;
	char			*name2;
}					t_tu;

typedef struct		s_pr
{
	char			*father;
	char			*sommet;
}					t_pr;

typedef struct		s_lem
{
	char			**tab_line;
	char			**cpy;
	char			**way;
	int				len_max_line;
	int				nb_row;
	int				nb_ants;
	int				nb_row_way;
	int				flag_gnl;
	int				flag_start;
	int				flag_end;
	int				id_start;
	int				id_end;
	int				id_pr;
	int				count_room;
	int				count_tube;
	int				time_tube;
	int				after_start;
	int				after_end;
	int				flag_parce;
	t_ro			*ro;
	t_tu			*tu;
	t_pr			*pr;
}					t_lem;

void				ft_print_rez(t_lem *st);
void				ft_free_file(t_lem *st, char **file);
void				ft_isolate_way(t_lem *st);
void				ft_bfs(t_lem *st, int i, char *name);
void				ft_marquer(t_lem *st, char *name);
char				*ft_fils(t_lem *st, char *father, int y);
int					ft_file_empty(t_lem *st, char **file);
int					ft_is_mark(t_lem *st, char *name);
int					ft_is_end(t_lem *st, char *name);
int					ft_check_if_end(t_lem *st);
int					last_check(t_lem *st);
int					ft_is_comment(char *str);
int					ft_is_room(char *str);
int					ft_is_tube(char *str);
int					ft_check_tube(t_lem *st, char *line);
int					ft_check_room(t_lem *st, char *str);
void				ft_free_struct(t_lem *s);
void				ft_free_tab(char **tab);
int					ft_line_isdigit(char *line);
void				ft_len_max_line(t_lem *st, char *line);
int					ft_checker(t_lem *st, char *line);
void				ft_resolv(t_lem *st);

#endif
