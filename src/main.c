/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:13:40 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/24 16:04:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_valid_input(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	stack_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_b->top = NULL;
}

bool	is_int_range(char *str)
{
	long	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (false);
	return (true);
}

int	check_input(char **argv, int *args)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		if (!is_valid_input(argv[i + 1]) || !is_int_range(argv[i + 1]))
			return (1);
		args[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*args;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1)
	{
		args = malloc((argc - 1) * sizeof(int));
		if (args == NULL)
			return (0);
		if (check_input(argv, args) == 1)
			return (print_error());
		if (!check_duplicates(args, argc - 1))
		{
			free(args);
			return (print_error());
		}
		i = 1;
		stack_init(&stack_a, &stack_b);
		while (argv[i])
		{
			push_stack(&stack_a, ft_atoi(argv[i]));
			i++;
		}
		push_swap(&stack_a, &stack_b);
		free(args);
	}
	return (0);
}
