/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:14:32 by fallouch          #+#    #+#             */
/*   Updated: 2019/01/20 23:22:42 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoll(const char *str)
{
	long long		ret;
	long long		neg;

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
