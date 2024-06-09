/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:21 by marvin            #+#    #+#             */
/*   Updated: 2024/06/09 18:43:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static long	convert_to_long(const char *str, int sign)
{
	long	result;

	result = -1;
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

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = -1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (sign == -1)
		return (-1);
	result = (int)convert_to_long(str, sign);
	return (result);
}

#include <stdio.h>
#include <stdlib.h>

// int	main(void)
// {
// 	printf("Input: '53 d 1'\n");
// 	printf("Original: %d\n", atoi("a"));
// 	printf("Custom  : %d\n", ft_atoi("a"));
// 	return (0);
// }
