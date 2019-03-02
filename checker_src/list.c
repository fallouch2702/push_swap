/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 20:14:13 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/29 23:48:10 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack						*create_new_elem(int value)
{
	t_stack			*new;

	if (!(new = malloc(sizeof(t_stack))))
		error(0);
	new->next = NULL;
	new->before = NULL;
	new->value = value;
	new->pos = -1;
	return (new);
}

void						list_push_back(t_stack **begin, int value)
{
	t_stack			*tmp;
	t_stack			*new;

	tmp = *begin;
	new = create_new_elem(value);
	if (!tmp)
	{
		*begin = new;
		new->next = *begin;
		new->before = *begin;
	}
	else
	{
		while (tmp->next != *begin)
			tmp = tmp->next;
		new->next = *begin;
		new->before = tmp;
		tmp->next = new;
		(*begin)->before = new;
	}
}

void						list_push_front(t_stack **begin, t_stack *new)
{
	t_stack			*tmp;

	tmp = *begin;
	if (!new)
		return ;
	if (!tmp)
	{
		new->before = new;
		new->next = new;
	}
	else
	{
		new->before = tmp->before;
		new->next = tmp;
		tmp->before->next = new;
		tmp->before = new;
	}
	*begin = new;
}

void						list_clean(t_stack **begin)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	tmp = *begin;
	tmp->before->next = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

size_t						list_size(t_stack *begin)
{
	t_stack				*tmp;
	size_t				len;

	if (begin == NULL)
		return (0);
	len = 1;
	tmp = begin->next;
	while (tmp != begin)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
