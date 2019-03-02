/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:13:04 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/29 23:02:01 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error(int x)
{
	if (x)
		ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int				is_all_digit(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != ' ' && *str != '-')
			return (0);
		if (*str == '-' && (*(str + 1) < '0' || *(str + 1) > '9'))
			return (0);
		str++;
	}
	return (1);
}

void			ft_swap(int *a, int *b)
{
	int			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				ft_mediane(t_stack *begin, int len)
{
	t_stack			*tmp;
	int				min;
	int				max;

	min = begin->pos;
	max = begin->pos;
	tmp = begin;
	while (len--)
	{
		if (min > tmp->pos)
			min = tmp->pos;
		if (max < tmp->pos)
			max = tmp->pos;
		tmp = tmp->next;
	}
	while (min < max)
	{
		min++;
		max--;
	}
	return (max);
}
