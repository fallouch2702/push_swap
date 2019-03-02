/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:33:57 by fallouch          #+#    #+#             */
/*   Updated: 2019/02/01 01:04:28 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct				s_stack
{
	int						value;
	int						pos;
	struct s_stack			*before;
	struct s_stack			*next;
}							t_stack;

void						error(int x);
int							is_all_digit(char *str);
void						ft_swap(int *a, int *b);
void						swap(t_stack *a, t_stack *b);
void						push(t_stack **a, t_stack **b);
void						rotate(t_stack **a, t_stack **b);
void						reverse_rotate(t_stack **a, t_stack **b);
t_stack						*parsing(char **av);
void						position(t_stack *begin);
size_t						list_size(t_stack *begin);
void						list_push_front(t_stack **begin, t_stack *n);
void						list_push_back(t_stack **begin, int value);
void						list_clean(t_stack **begin);

#endif
