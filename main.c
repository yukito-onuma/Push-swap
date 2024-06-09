/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:43:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/06/16 14:39:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int print_error(void)
{
	ft_printf("Error\n");
	return (0);
}

bool check_duplicates(int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && arr[i] == arr[j])
				return false;
			j++;
		}
		i++;
	}
	return true;
}

bool is_valid_input(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return false;
		str++;
	}
	return true;
}

int	main(int argc, char **argv)
{
	int	i;
	int *args = malloc((argc - 1) * sizeof(int));

	i = 0;
	while (argv[i + 1])
	{
		if (!is_valid_input(argv[i + 1]) || ft_atoi(argv[i + 1]) == -1)
			return (print_error());
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!check_duplicates(args, argc - 1))
		return (print_error());
	i = 0;
	while (argv[i + 1])
	{
		push_swap(ft_atoi(argv[i + 1]));
		i++;
	}
	free(args);
}