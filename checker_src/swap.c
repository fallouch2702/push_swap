/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:24:54 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/29 23:47:43 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		swap(t_stack *stack1, t_stack *stack2)
{
	t_stack			*a;
	t_stack			*b;

	a = stack1;
	b = stack2;
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
	if (b)
		swap(b, NULL);
}

void		push(t_stack **a, t_stack **b)
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
}

void		rotate(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	if (*a)
		*a = (*a)->next;
	if (b)
		rotate(b, NULL);
}

void		reverse_rotate(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	if (*a)
		*a = (*a)->before;
	if (b)
		reverse_rotate(b, NULL);
}
