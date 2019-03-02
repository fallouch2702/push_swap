/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:00:17 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:14:55 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*begin;
	t_list	*new;
	t_list	*before;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	begin = new;
	before = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (before)
			before->next = new;
		before = new;
		lst = lst->next;
	}
	return (begin);
}
