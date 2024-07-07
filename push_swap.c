/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:05:36 by yonuma            #+#    #+#             */
/*   Updated: 2024/07/07 19:25:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack *stack_a)
{
    int a;
    int b;
    int c;
	
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;

    if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

// int	check_digit(t_stack *stack_a)
// {
// 	t_node	*tmp;
// 	int		max;
	
// 	tmp = stack_a->top;
// 	min = tmp->value;
// 	while (tmp)
// 	{
// 		if (max > tmp->value)
// 			max = tmp->value;
// 		tmp = tmp->next;
// 	}
// 	return (max);
// }


int is_empty(t_stack *stack)
{
    return stack->top == NULL;
}

// void radix_sort(t_stack *stack_a)
// {
    
// }

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (is_empty(stack_a))
		return ;
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	//radix_sort(stack_a);
	(void)stack_b;
}
