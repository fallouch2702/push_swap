/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:17:00 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 18:12:03 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				need_push(t_stack *begin, int pivot, int len, int n)
{
	t_stack			*tmp;

	if (!begin)
		return (0);
	tmp = begin;
	while (len--)
	{
		if ((n == 1 && tmp->pos < pivot) || (n == 2 && tmp->pos > pivot))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			return_back(t_stack **begin, int r, int id, t_move **move)
{
	int			len;

	len = list_size(*begin);
	if (r > len / 2)
		while (len - r++ > 0)
			rotate(begin, id == 1 ? RA : RB, move);
	else
		while (r--)
			reverse_rotate(begin, id == 1 ? RRA : RRB, move);
}

void			quicksort_b(t_stack **stack1, t_stack **stack2, int len,
		t_move **move)
{
	int			i;
	int			r;
	int			p;
	int			pivot;

	i = 0;
	r = 0;
	p = 0;
	if (len <= 3)
		return (sort_stack_b(stack2, len, move));
	pivot = ft_mediane(*stack2, len);
	while (need_push(*stack2, pivot, len - i, 2) && i++ < len)
		if ((*stack2)->pos > pivot && ++p)
			push(stack2, stack1, PA, move);
		else
		{
			rotate(stack2, RB, move);
			r++;
		}
	quicksort(stack1, stack2, p, move);
	return_back(stack2, r, 2, move);
	quicksort_b(stack1, stack2, len - p, move);
	while (p--)
		push(stack1, stack2, PB, move);
}

void			quicksort(t_stack **stack1, t_stack **stack2, int len,
		t_move **move)
{
	int			i;
	int			r;
	int			p;
	int			pivot;

	i = 0;
	r = 0;
	p = 0;
	if (len <= 3)
		return (sort_stack_a(stack1, len, move));
	pivot = ft_mediane(*stack1, len);
	while (need_push(*stack1, pivot, len - i, 1) && i++ < len)
		if ((*stack1)->pos < pivot && ++p)
			push(stack1, stack2, PB, move);
		else
		{
			rotate(stack1, RA, move);
			r++;
		}
	return_back(stack1, r, 1, move);
	quicksort(stack1, stack2, len - p, move);
	quicksort_b(stack1, stack2, p, move);
	while (p--)
		push(stack2, stack1, PA, move);
}
