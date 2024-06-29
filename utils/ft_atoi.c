/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:21 by marvin            #+#    #+#             */
/*   Updated: 2024/06/30 15:47:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

static size_t	ft_strlen_n(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i ++;
	return (i);
}

int	ft_atoi(const char *str)
{
	uint64_t	re;
	int			sign;
	int			i;

	re = 0;
	sign = 1;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		re = re * 10 + str[i++] - '0';
	if ((ft_strlen_n(str) == 19 && *str != '0' && re > 9223372036854775807)
		|| (ft_strlen_n(str) >= 20 && *str != '0' ))
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (re * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("Input: '2'\n");
// 	printf("Original: %d\n", atoi("2"));
// 	printf("Custom  : %d\n", ft_atoi("2"));
// 	return (0);
// }
