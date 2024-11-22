/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:13:40 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/22 20:48:12 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (!ft_isdigit(*str))
			return false;
		str++;
	}
	return true;
}

void	stack_init(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_b->top = NULL;
}

// int の範囲内処理書いておく
int	main(int argc, char **argv)
{
	int		i;
	int 	*args;
	t_stack	stack_a;
	t_stack stack_b;

	args = malloc((argc - 1) * sizeof(int));
	if (args == NULL)
		return (0);
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
	i = 1;
	stack_init(&stack_a, &stack_b);
	while (argv[i])
	{
		push_stack(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	push_swap(&stack_a, &stack_b, argc);
	free(args);
    return (0);
}
