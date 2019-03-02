/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:32:59 by fallouch          #+#    #+#             */
/*   Updated: 2019/02/01 01:16:25 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack				*parsing(char **av)
{
	t_stack			*begin;
	long long		tmp;

	begin = NULL;
	while (*av)
	{
		if (!is_all_digit(*av))
			error(1);
		while (**av)
		{
			while (**av == ' ')
				(*av)++;
			if (**av == 0)
				break ;
			tmp = ft_atoll(*av);
			if (tmp > INT_MAX || tmp < INT_MIN)
				error(1);
			list_push_back(&begin, tmp);
			while ((**av >= '0' && **av <= '9') || **av == '-')
				*av = *av + 1;
		}
		av++;
	}
	return (begin);
}

int					*sort_tab(int *tab, int len)
{
	int			i;
	int			j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (j + 1 < len && tab[j + 1] < tab[j])
				ft_swap(&tab[j + 1], &tab[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (i + 1 < len && tab[i] == tab[i + 1])
			error(1);
		i++;
	}
	return (tab);
}

void				put_position(t_stack *begin, int *tab, int len)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	while (i < len)
	{
		tmp = begin;
		while (tmp)
		{
			if (tmp->value == tab[i] && tmp->pos == -1)
			{
				tmp->pos = i + 1;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void				position(t_stack *begin)
{
	t_stack			*tmp;
	int				*tab;
	int				i;

	tmp = begin;
	if (!(tab = malloc(sizeof(int) * list_size(begin))))
		error(0);
	i = 0;
	while (tmp->next != begin)
	{
		tab[i++] = tmp->value;
		tmp = tmp->next;
	}
	tab[i++] = tmp->value;
	if (!(tab = sort_tab(tab, i)))
		error(1);
	put_position(begin, tab, i);
	free(tab);
}
