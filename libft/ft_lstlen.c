/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:37:55 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:15:03 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *begin)
{
	int	i;

	i = 0;
	if (!begin)
		return (0);
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}
