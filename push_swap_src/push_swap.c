/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 02:40:03 by fallouch          #+#    #+#             */
/*   Updated: 2019/02/01 01:12:13 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_sorted(t_stack *begin)
{
	t_stack			*tmp;
	int				tmp_value;

	tmp = begin->next;
	tmp_value = begin->value;
	while (tmp != begin)
	{
		if (tmp->value < tmp_value)
			return (0);
		tmp_value = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_stack			*stack1;
	t_stack			*stack2;
	t_move			*move;

	if (ac < 2)
		error(0);
	if (!(stack1 = parsing(++av)))
		error(0);
	stack2 = NULL;
	move = NULL;
	if (is_sorted(stack1))
		error(0);
	position(stack1);
	quicksort(&stack1, &stack2, list_size(stack1), &move);
	list_clean(&stack1);
	opti(move);
	print_list(move);
	list_move_clean(&move);
}
