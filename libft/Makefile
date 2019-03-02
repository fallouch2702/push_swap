# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 23:13:46 by fallouch          #+#    #+#              #
#    Updated: 2019/01/31 22:49:19 by fallouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME = libft.a
SRC = 	ft_atoi.c ft_atol.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_list_push_back.c ft_list_push_front.c ft_memalloc.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c\
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c\
		ft_strsplit.c ft_strstr.c ft_strnstr.c ft_strsub.c ft_strtrim.c\
		ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_atoll.c\
		basic_print.c conv_d.c ft_lltoa.c ft_print.c ft_printf.c ft_putfloat.c parsing.c ft_aux.c\
		get_next_line.c\

HEADER = libft.h ft_printf.h
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) *.o
	@echo ./$(NAME)
	@ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@gcc -o $@ -c $< $(CFLAGS)

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME)

re: fclean all
