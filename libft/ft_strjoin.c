/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:31:55 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/29 23:58:36 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*new;
	char		*p;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	p = new;
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	return (p);
}
