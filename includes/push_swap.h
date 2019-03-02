/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:13:31 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 19:27:31 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct			s_stack
{
	int					value;
	int					pos;
	struct s_stack		*before;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_move
{
	char				*move;
	struct s_move		*next;
}						t_move;

void					error(int x);
void					ft_swap(int *a, int *b);
int						ft_mediane(t_stack *begin, int len);
int						is_all_digit(char *str);
void					list_clean(t_stack **begin);
size_t					list_size(t_stack *begin);
void					list_push_back(t_stack **begin, int value);
void					list_push_front(t_stack **begin, t_stack *n);
void					swap(t_stack *a, char *flag, t_move **move);
void					push(t_stack **a, t_stack **b, char *flag,
																t_move **move);
void					rotate(t_stack **a, char *flag, t_move **move);
void					reverse_rotate(t_stack **a, char *flag, t_move **move);
t_stack					*parsing(char **av);
void					position(t_stack *begin);
void					push_swap(t_stack *begin);
void					quicksort(t_stack **stack1, t_stack **stack2, int len,
																t_move **move);
void					sort_stack_a(t_stack **stack, int len, t_move **move);
void					sort_stack_b(t_stack **stack, int len, t_move **move);
void					add_move(t_move **begin, char *move);
void					opti(t_move *begin);
void					print_list(t_move *begin);
void					list_move_clean(t_move **begin);

#endif
