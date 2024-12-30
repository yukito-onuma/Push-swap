/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:37:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/30 20:37:22 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long	convert_to_long(const char *str, int sign)
{
	long	result;

	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && (*str
					- '0') > 7))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = convert_to_long(str, sign);
	return (result);
}