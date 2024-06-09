/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:43:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/06/16 13:09:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

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

int	main(int argc, char **argv)
{
	int	i;
	int *args = malloc((argc - 1) * sizeof(int));

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i + 1]) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!check_duplicates(args, argc - 1))
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	while (argv[i + 1])
	{
		push_swap(ft_atoi(argv[i + 1]));
		i++;
	}
	free(args);
}