/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:13:53 by gschaetz          #+#    #+#             */
/*   Updated: 2017/04/12 19:00:57 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

typedef struct		s_format
{
	char			*stock;
	char			*flag;
	int				prec;
	int				width;
	int				lenf;
	char			*prefixe;
	char			type;
}					t_format;

typedef struct		s_st
{
	char			*str;
	int				lens;
}					t_st;

typedef struct s_p	t_printf;

typedef struct		s_fct
{
	char			c;
	void			(*f)(t_printf *, va_list *);
}					t_fct;

struct				s_p
{
	t_format		*format_split;
	t_st			*str_stock;
	t_fct			*tab_fct;
	char			*tab;
	char			*tab_pre;
	int				itp;
	int				ich;
	int				ct;
	int				len_format;
	int				lenf;
	int				lenf_s;
	int				uitom;
	int				ox;
	int				istr;
	int				ifor;
	int				start;
	int				flag;
	int				ret;
	int				nbc;
};

int					ft_call_add_ox(t_printf *var, int i, char *tmp, char *cp);
char				*ft_add_ox1(t_printf *var, char *tmp, char *cp);
void				ft_put_s(char *tmp, char *cp, t_printf *var, char *s);
char				*ft_modif_s(t_printf *var, int size, char *cp, char *tmp);
int					ft_size_s(t_printf *var, char *s);
char				*ft_check_d0(t_printf *var, char *tmp, char *cp);
char				*ft_check_d1(t_printf *var, char *tmp, char *cp);
char				*ft_check_d2(t_printf *var, char *tmp, char *cp);
char				*ft_check_d3(t_printf *var, char *tmp, char *cp, int j);
char				*ft_last_app_d(t_printf *var, char *tmp, char *cp,
					char type);
void				ft_space_lc(int size);
int					ft_nboct(char *nb);
void				ft_one(t_printf *var, wchar_t uni);
void				ft_three(t_printf *var, wchar_t uni);
void				ft_four(t_printf *var, wchar_t uni);
void				ft_two(t_printf *var, wchar_t uni);
uintmax_t			ft_uatoi(const char *nb);
void				ft_lc(t_printf *var, va_list *ap);
void				ft_percent(t_printf *var, va_list *ap);
void				ft_c(t_printf *var, va_list *ap);
int					ft_abs(int nb);
void				ft_s(t_printf *var, va_list *ap);
char				*ft_add_oc(t_printf *var, char *tmp, char *cp);
char				*ft_add_ox(t_printf *var, char *tmp, char *cp);
char				*ft_uitoa_base_min(uintmax_t val, uintmax_t base,
					t_printf *var);
char				*ft_uitoa_base_maj(uintmax_t val, uintmax_t base,
					t_printf *var);
int					ft_check_signe(t_printf *var, char *cp, char *tmp, int j);
int					ft_check_lenf(char *cp, t_printf *var);
int					ft_check_lenf_signe(char *cp, t_printf *var);
char				*ft_add_space(char *tmp, char *cp);
char				*ft_space(t_printf *var, char *tmp, char *cp);
int					ft_choice(t_printf *var, char *cp);
char				*ft_prec_zero(t_printf *var, char *tmp);
int					ft_len_width(t_printf *var, char *cp);
char				*ft_width_neg(t_printf *var, int len, char *tmp, char *cp);
void				ft_putnstr(char *str, int min, int len, t_printf *var);
void				ft_free(t_printf *var);
char				*ft_appli_flag_prec_nb(t_printf *var, char *cp, char *tmp);
void				ft_putnstr(char *str, int min, int len, t_printf *var);
char				*ft_appli_cp_nb(t_printf *var, char *cp, char *tmp);
char				*ft_appli_prec_nb(t_printf *var, char *cp, char *tmp);
char				*ft_appli_width_nb(t_printf *var, char *cp, char *tmp);
intmax_t			ft_check_prefixe(t_printf *var, va_list *ap);
uintmax_t			ft_check_prefixe_u(t_printf *var, va_list *ap);
void				ft_ls(t_printf *var, va_list *ap);
void				ft_p(t_printf *var, va_list *ap);
void				ft_d(t_printf *var, va_list *ap);
void				ft_ld(t_printf *var, va_list *ap);
void				ft_o(t_printf *var, va_list *ap);
void				ft_lo(t_printf *var, va_list *ap);
void				ft_u(t_printf *var, va_list *ap);
void				ft_lu(t_printf *var, va_list *ap);
void				ft_x(t_printf *var, va_list *ap);
void				ft_lx(t_printf *var, va_list *ap);
void				ft_lc(t_printf *var, va_list *ap);
void				ft_init_fct_tab(t_printf *var);
void				ft_convertion(t_printf *var, va_list *ap);
char				ft_type(t_printf *var, int i);
void				ft_check_flag_width(t_printf *var);
void				ft_identifi_width(int i, int j, t_printf *var);
void				ft_identifi_prec(int j, int i, t_printf *var);
void				ft_check_prefixe_prec(t_printf *var);
void				ft_stock_str(const char *format, t_printf *var);
void				ft_stock_format(char const *format, t_printf *var);
void				ft_print_stock(t_printf *var);
void				ft_parce_format(const char *format, t_printf *var);
int					ft_printf(const char *format, ...);

#endif
