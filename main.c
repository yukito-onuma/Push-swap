/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:43:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/06/09 17:08:23 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	printf("1 : %s\n", argv[1]);
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i + 1]) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (argv[i + 2])
	{
		push_swap(ft_atoi(argv[i + 2]));
		i++;
	}
}
