/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:04:46 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:14:21 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;

	len = 0;
	slen = ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		len++;
		size--;
	}
	while (*src && size-- > 1)
		*dst++ = *src++;
	size++;
	if (size == 1 || *src == 0)
		*dst = '\0';
	return (slen + len);
}
