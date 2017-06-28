# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 13:49:44 by gschaetz          #+#    #+#              #
#    Updated: 2017/06/26 15:10:56 by gschaetz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = libft.h

SRC = ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	  ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	  ft_strcmp.c ft_strncmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isprint.c ft_isdigit.c ft_tolower.c ft_toupper.c ft_strlen.c \
	  ft_atoi.c ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_bzero.c ft_memcpy.c \
	  ft_memchr.c ft_memcmp.c ft_strdel.c ft_strclr.c ft_itoa_base.c\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_memccpy.c \
	  ft_memmove.c ft_memcpy_rev.c ft_strlcat.c ft_itoa.c ft_strsplit.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_sqrt.c ft_foreach.c ft_swap.c get_next_line.c \
	  ft_printf/ft_printf.c ft_printf/ft_parce_base.c ft_uitoa_base.c\
	  ft_printf/ft_stock_format_str.c ft_printf/ft_prefixe.c \
	  ft_printf/ft_precision.c ft_printf/ft_flags.c ft_printf/ft_width.c \
	  ft_printf/ft_type.c ft_printf/ft_convertion.c ft_printf/ft_init_fct0.c \
	  ft_printf/ft_init_fct1.c ft_printf/ft_init_fct2.c \
	  ft_printf/ft_check_prefixe.c ft_iitoa.c ft_uitoa.c ft_printf/ft_appli.c \
	  ft_printf/ft_d.c ft_printf/ft_appli1.c ft_printf/ft_appli2.c \
	  ft_printf/ft_uitoa_base_min.c ft_printf/ft_uitoa_base_maj.c \
	  ft_printf/ft_appli3.c ft_printf/ft_s.c ft_printf/ft_c.c \
	  ft_printf/ft_percent.c ft_printf/ft_lc.c ft_printf/ft_uatoi.c \
	  ft_printf/ft_oct_lc.c ft_printf/ft_ls.c ft_printf/ft_d1.c \
	  ft_printf/ft_s1.c ft_printf/ft_add_ox1.c ft_realoc_tab.c


PO =  ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o \
	  ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putstr.o ft_putstr_fd.o \
	  ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o \
	  ft_strcmp.o ft_strncmp.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	  ft_isprint.o ft_isdigit.o ft_tolower.o ft_toupper.o ft_strlen.o \
	  ft_atoi.o ft_strstr.o ft_strnstr.o ft_strchr.o ft_strrchr.o \
	  ft_memalloc.o ft_memdel.o ft_strnew.o ft_bzero.o ft_memcpy.o \
	  ft_memchr.o ft_memcmp.o ft_strdel.o ft_strclr.o ft_itoa_base.o\
	  ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
	  ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_memccpy.o \
	  ft_memmove.o ft_memcpy_rev.o ft_strlcat.o ft_itoa.o ft_strsplit.o \
	  ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
	  ft_lstmap.o ft_sqrt.o ft_foreach.o ft_swap.o get_next_line.o \
	  ft_printf/ft_printf.o ft_printf/ft_stock_format_str.o \
	  ft_printf/ft_parce_base.o ft_printf/ft_prefixe.o \
	  ft_printf/ft_precision.o ft_printf/ft_flags.o ft_printf/ft_width.o \
	  ft_printf/ft_type.o ft_printf/ft_convertion.o \
	  ft_printf/ft_init_fct0.o ft_printf/ft_init_fct1.o \
	  ft_printf/ft_init_fct2.o ft_printf/ft_check_prefixe.o \
	  ft_iitoa.o ft_uitoa.o ft_printf/ft_appli.o \
	  ft_printf/ft_d.o ft_printf/ft_appli1.o ft_printf/ft_appli2.o \
	  ft_uitoa_base.o ft_printf/ft_uitoa_base_min.o \
	  ft_printf/ft_uitoa_base_maj.o ft_printf/ft_appli3.o \
	  ft_printf/ft_s.o ft_printf/ft_c.o ft_printf/ft_percent.o \
	  ft_printf/ft_lc.o ft_printf/ft_uatoi.o ft_printf/ft_oct_lc.o \
	  ft_printf/ft_ls.o ft_printf/ft_d1.o ft_printf/ft_s1.o \
	  ft_printf/ft_add_ox1.o ft_realoc_tab.o

all: $(NAME)

%.o:%.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(PO) $(INC)
	@ar rc $(NAME) $(PO)
	@ranlib $(NAME)
	@echo "\033[31m_|        _|_|_|  _|_|_|    _|_|_|_|  _|_|_|_|_|        _|_|_|        _|_|_|"
	@echo "_|          _|    _|    _|  _|            _|          _|            _|      "
	@echo "_|          _|    _|_|_|    _|_|_|        _|          _|  _|_|        _|_|  "
	@echo "_|          _|    _|    _|  _|            _|          _|    _|            _|"
	@echo "_|_|_|_|  _|_|_|  _|_|_|    _|            _|            _|_|_|  _|  _|_|_|  "

clean:
	@rm -rf $(PO)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
