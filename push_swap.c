/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:05:36 by yonuma            #+#    #+#             */
/*   Updated: 2024/07/05 21:41:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack *stack_a) {
    int a;
    int b;
    int c;
	
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;

    if (a < b && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a < b && b > c && a > c)
		ra(stack_a);
	else if (a > b && b < c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a > b)
		sa(stack_a);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	(void)stack_b;
	// else if (ft_lstsize(&stack_a) <= 5)
	// 	sort_5(&stack_a, &stack_b);
	// else
	// 	sort_large(&stack_a, &stack_b);
}
