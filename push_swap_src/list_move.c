/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:17:58 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/30 18:44:58 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move			*create_new_move(char *move)
{
	t_move		*new;

	if (!(new = malloc(sizeof(t_move))))
		error(0);
	new->move = move;
	new->next = NULL;
	return (new);
}

void			add_move(t_move **begin, char *move)
{
	t_move			*tmp;

	if (!*begin)
		*begin = create_new_move(move);
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_new_move(move);
	}
}

void			print_list(t_move *begin)
{
	while (begin)
	{
		ft_putendl(begin->move);
		begin = begin->next;
	}
}

void			list_move_clean(t_move **begin)
{
	t_move			*tmp;

	while (*begin)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	*begin = NULL;
}
