# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 21:57:17 by fallouch          #+#    #+#              #
#    Updated: 2019/01/31 22:50:38 by fallouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:


NAME_CHECK = checker
NAME_SWAP = push_swap

CHECKER		=	checker
PUSH_SWAP	=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address

_C_SRCS		= checker_src/aux.c \
		 checker_src/checker.c \
		 checker_src/list.c \
		 checker_src/parsing.c \
		 checker_src/swap.c

_PS_SRCS	= push_swap_src/aux.c \
			push_swap_src/basic_sort_a.c \
			push_swap_src/basic_sort_b.c \
			push_swap_src/list.c \
			push_swap_src/list_move.c \
			push_swap_src/opti.c \
			push_swap_src/parsing.c \
			push_swap_src/push_swap.c \
			push_swap_src/quicksort.c \
			push_swap_src/swap.c

_LIBFT		=	libft.a

SRCS_DIR	=	.
LIB_DIR		=	libft
PS_SRCS		=	$(addprefix $(SRCS_DIR)/, $(_PS_SRCS))
C_SRCS		=	$(addprefix	$(SRCS_DIR)/, $(_C_SRCS))
LIBFT		=	$(addprefix $(LIB_DIR), $(_LIBFT))

C_OBJS		=	$(C_SRCS:.c=.o)
PS_OBJS		=	$(PS_SRCS:.c=.o)

all:	$(CHECKER) $(PUSH_SWAP) $(LIBFT)

$(CHECKER) : $(C_OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(C_OBJS) -L$(LIB_DIR) -lft
	@echo "$(CHECKER) : $(_GREEN)Done$(_END)"

$(PUSH_SWAP): $(PS_OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(PS_OBJS) -L$(LIB_DIR) -lft
	@echo "$(PUSH_SWAP) : $(_GREEN)Done$(_END)"

$(LIBFT):
	@make -C $(LIB_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
	@make fclean -C $(LIB_DIR)
	@/bin/rm -f $(C_OBJS) $(PS_OBJS)
	@echo "push_swap clean : $(_GREEN)Done$(_END)"

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "push_swap fclean : $(_GREEN)Done$(_END)"

re:
	@make fclean
	@make

.PHONY: all clean fclean re
