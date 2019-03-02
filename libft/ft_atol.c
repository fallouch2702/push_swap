/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:14:32 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/13 16:26:00 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	ret;
	long	neg;

	ret = 0;
	neg = 1;
	while (*str == 32 || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		ret = ret * 10 + (*str % '0');
		str++;
	}
	return (ret * neg);
}
