/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:50:29 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:12:16 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void const *data,
		size_t data_size)
{
	t_list	*elem;

	elem = ft_lstnew(data, data_size);
	elem->next = *begin_list;
	*begin_list = elem;
}
