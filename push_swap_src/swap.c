/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:24:54 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 17:27:02 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_stack *a, char *flag, t_move **move)
{
	if (!a)
		return ;
	if (a)
	{
		if (a && a->next != a)
		{
			ft_swap(&a->value, &a->next->value);
			ft_swap(&a->pos, &a->next->pos);
		}
	}
	add_move(move, flag);
}

void		push(t_stack **a, t_stack **b, char *flag, t_move **move)
{
	t_stack			*tmp;

	tmp = (*a);
	if (!*a)
		return ;
	if (list_size(*a) == 1)
		*a = NULL;
	if (*a)
	{
		(*a)->next->before = (*a)->before;
		(*a)->before->next = (*a)->next;
		(*a) = (*a)->next;
	}
	list_push_front(b, tmp);
	add_move(move, flag);
}

void		rotate(t_stack **a, char *flag, t_move **move)
{
	if (!*a)
		return ;
	if (*a)
		*a = (*a)->next;
	add_move(move, flag);
}

void		reverse_rotate(t_stack **a, char *flag, t_move **move)
{
	if (!*a)
		return ;
	if (*a)
		*a = (*a)->before;
	add_move(move, flag);
}
