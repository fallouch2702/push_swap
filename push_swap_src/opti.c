/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:40:27 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 19:32:36 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			opti_ra(t_move *begin)
{
	t_move			*tmp;
	t_move			*second;
	t_move			*first;

	while (begin)
	{
		tmp = begin;
		while (tmp->next && tmp->next->next)
		{
			first = tmp->next;
			second = tmp->next->next;
			if ((!ft_strcmp(first->move, RA) && !ft_strcmp(second->move, RRA))
			|| (!ft_strcmp(first->move, RRA) && !ft_strcmp(second->move, RA)))
			{
				tmp->next = second->next;
				free(first);
				free(second);
			}
			else
				tmp = tmp->next;
		}
		begin = begin->next;
	}
}

void			opti_rb(t_move *begin)
{
	t_move			*tmp;
	t_move			*second;
	t_move			*first;

	while (begin)
	{
		tmp = begin;
		while (tmp->next && tmp->next->next)
		{
			first = tmp->next;
			second = tmp->next->next;
			if ((!ft_strcmp(first->move, RB) && !ft_strcmp(second->move, RRB))
			|| (!ft_strcmp(first->move, RRB) && !ft_strcmp(second->move, RB)))
			{
				tmp->next = second->next;
				free(first);
				free(second);
			}
			else
				tmp = tmp->next;
		}
		begin = begin->next;
	}
}

void			opti_push(t_move *begin)
{
	t_move			*tmp;
	t_move			*second;
	t_move			*first;

	while (begin)
	{
		tmp = begin;
		while (tmp->next && tmp->next->next)
		{
			first = tmp->next;
			second = tmp->next->next;
			if ((!ft_strcmp(first->move, PA) && !ft_strcmp(second->move, PB))
			|| (!ft_strcmp(first->move, PB) && !ft_strcmp(second->move, PA)))
			{
				tmp->next = second->next;
				free(first);
				free(second);
			}
			else
				tmp = tmp->next;
		}
		begin = begin->next;
	}
}

void			opti(t_move *begin)
{
	opti_ra(begin);
	opti_rb(begin);
	opti_push(begin);
}
