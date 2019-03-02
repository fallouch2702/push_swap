/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:45:35 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:12:03 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void const *data,
		size_t data_size)
{
	t_list	*tmp;

	if (!(*begin_list))
	{
		*begin_list = ft_lstnew(data, data_size);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = ft_lstnew(data, data_size);
}
