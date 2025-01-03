/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:43:10 by yonuma            #+#    #+#             */
/*   Updated: 2024/07/07 19:24:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "push_swap.h"

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
		if (!isdigit(*str)) // 本家のisdigit使ってるから注意
			return false;
		str++;
	}
	return true;
}

void	stack_init(t_stack *stack_a, t_stack *stack_b) // God !!
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
	// -------------------中身確認---------------------------
	// struct s_node *ptr;
	// ptr = stack_a.top;
	// for (int i = 0; i < ft_lstsize(ptr); i++) {
	// 	printf("stack_a[%d]->value = %d\n", i, (ptr)->value);
	// 	ptr = ptr->next;
	// }
	// -----------------------------------------------------
	push_swap(&stack_a, &stack_b);
	// -------------------中身確認---------------------------
	// struct s_node *atr;
	// struct s_node *btr;
	// atr = stack_a.top;
	// btr = stack_b.top;
	// for (int i = 0; i < ft_lstsize(atr) + 1; i++) {
	// 	printf("stack_a[%d]->value = %d 	stack_b[%d]->value = %d\n", i, (atr)->value, i, (btr)->value);
	// 	atr = atr->next;
	// 	btr = btr->next;
	// }
	// -----------------------------------------------------
	free(args);
}