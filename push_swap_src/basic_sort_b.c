/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 23:35:18 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 18:11:22 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_stack3_b(t_stack **stack1, t_move **move)
{
	int			x;
	int			y;
	int			z;

	x = (*stack1)->pos;
	y = (*stack1)->next->pos;
	z = (*stack1)->next->next->pos;
	if (x < y && y < z)
	{
		swap(*stack1, SB, move);
		reverse_rotate(stack1, RRB, move);
	}
	else if (x < z && z < y)
		rotate(stack1, RB, move);
	else if (z < x && x < y)
		swap(*stack1, SB, move);
	else if (y < z && z < x)
	{
		reverse_rotate(stack1, RRB, move);
		swap(*stack1, SB, move);
	}
	else if (y < x && x < z)
		reverse_rotate(stack1, RRB, move);
}

void			place_three_b(t_stack **stack, int len, t_move **move)
{
	while (len-- > 1)
	{
		if ((*stack)->pos < (*stack)->next->pos)
		{
			swap(*stack, SB, move);
			rotate(stack, RB, move);
		}
		else
			rotate(stack, RB, move);
	}
	while (++len < 3)
	{
		reverse_rotate(stack, RRB, move);
		if ((*stack)->pos < (*stack)->pos)
			swap(*stack, SB, move);
	}
	if ((*stack)->pos < (*stack)->next->pos)
		swap(*stack, SB, move);
}

void			sort_stack_b(t_stack **stack, int len, t_move **move)
{
	if (len <= 1)
		return ;
	else if (len <= 2)
	{
		if ((*stack)->pos < (*stack)->next->pos)
			swap(*stack, SB, move);
	}
	else if (list_size(*stack) == 3 && len == 3)
		sort_stack3_b(stack, move);
	else if (len <= 3)
		place_three_b(stack, len, move);
}
