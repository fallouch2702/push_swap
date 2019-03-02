/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:07:54 by fallouch          #+#    #+#             */
/*   Updated: 2019/02/01 01:12:34 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			apply_command(t_stack **stack1, t_stack **stack2, char *line)
{
	if (!ft_strcmp(line, SA))
		swap(*stack1, NULL);
	else if (!ft_strcmp(line, SB))
		swap(*stack2, NULL);
	else if (!ft_strcmp(line, PA))
		push(stack2, stack1);
	else if (!ft_strcmp(line, PB))
		push(stack1, stack2);
	else if (!ft_strcmp(line, RA))
		rotate(stack1, NULL);
	else if (!ft_strcmp(line, RB))
		rotate(stack2, NULL);
	else if (!ft_strcmp(line, RRA))
		reverse_rotate(stack1, NULL);
	else if (!ft_strcmp(line, RRB))
		reverse_rotate(stack2, NULL);
	else if (!ft_strcmp(line, SS))
		swap(*stack1, *stack2);
	else if (!ft_strcmp(line, RR))
		rotate(stack1, stack2);
	else if (!ft_strcmp(line, RRR))
		reverse_rotate(stack1, stack2);
	else
		error(1);
}

void			read_command(t_stack **stack1, t_stack **stack2)
{
	char		*line;

	while (get_next_line(0, &line))
	{
		apply_command(stack1, stack2, line);
		free(line);
	}
}

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

void			checker(t_stack **stack1, t_stack **stack2)
{
	read_command(stack1, stack2);
	if (is_sorted(*stack1) && !*stack2)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int ac, char **av)
{
	t_stack		*stack1;
	t_stack		*stack2;

	if (ac < 2)
		error(0);
	if (!(stack1 = parsing(++av)))
		error(0);
	stack2 = NULL;
	position(stack1);
	checker(&stack1, &stack2);
	if (stack1)
		list_clean(&stack1);
	if (stack2)
		list_clean(&stack2);
}
