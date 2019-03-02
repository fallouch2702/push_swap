/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:29:05 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:15:32 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **begin)
{
	t_list	*tmp;

	while (*begin)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
	*begin = NULL;
}
