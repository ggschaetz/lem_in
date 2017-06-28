/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:51:15 by gschaetz          #+#    #+#             */
/*   Updated: 2017/06/26 15:04:20 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char	*s, int c);
char				*ft_strstr(const char *bstr, const char *lstr);
char				*ft_strnstr(const char *bstr, const char *lstr, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_uitoa(uintmax_t n);
char				*ft_iitoa(intmax_t n);
char				*ft_itoa_base(int val, int base);
char				*ft_uitoa_base(uintmax_t val, uintmax_t base);
char				**ft_strsplit(char const *s, char c);
char				**ft_realoc_tab(char **tab, int size_x, int size_y);
void				ft_swap(int *a, int *b);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memcpy_rev(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t n));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t n));
void				ft_foreach(int *tab, int length, void(*f)(int));
int					ft_strcmp(char *s1, char *s2);
int					ft_sqrt(int nb);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					get_next_line(int const fd, char **line);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlen(const char *str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
