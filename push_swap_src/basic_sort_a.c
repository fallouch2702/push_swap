/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 02:01:07 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 18:11:26 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_stack3_a(t_stack **stack1, t_move **move)
{
	int			x;
	int			y;
	int			z;

	x = (*stack1)->pos;
	y = (*stack1)->next->pos;
	z = (*stack1)->next->next->pos;
	if (x > y && y > z)
	{
		swap(*stack1, SA, move);
		reverse_rotate(stack1, RRA, move);
	}
	else if (x > z && z > y)
		rotate(stack1, RA, move);
	else if (z > x && x > y)
		swap(*stack1, SA, move);
	else if (y > z && z > x)
	{
		reverse_rotate(stack1, RRA, move);
		swap(*stack1, SA, move);
	}
	else if (y > x && x > z)
		reverse_rotate(stack1, RRA, move);
}

void			place_three_a(t_stack **stack, int len, t_move **move)
{
	while (len-- > 1)
	{
		if ((*stack)->pos > (*stack)->next->pos)
		{
			swap(*stack, SA, move);
			rotate(stack, RA, move);
		}
		else
			rotate(stack, RA, move);
	}
	while (++len < 3)
	{
		reverse_rotate(stack, RRA, move);
		if ((*stack)->pos > (*stack)->pos)
			swap(*stack, SA, move);
	}
	if ((*stack)->pos > (*stack)->next->pos)
		swap(*stack, SA, move);
}

void			sort_stack_a(t_stack **stack, int len, t_move **move)
{
	if (len <= 1)
		return ;
	else if (len <= 2)
	{
		if ((*stack)->pos > (*stack)->next->pos)
			swap(*stack, SA, move);
	}
	else if (list_size(*stack) == 3 && len == 3)
		sort_stack3_a(stack, move);
	else if (len <= 3)
		place_three_a(stack, len, move);
}
