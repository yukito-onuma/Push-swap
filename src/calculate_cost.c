/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:38:52 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/25 14:20:41 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calculate_cost1(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		count_a;
	int		count_b;

	current_b = stack_b->top;
	count_b = 0;
	while (current_b)
	{
		current_a = stack_a->top;
		count_a = 0;
		while (current_a)
		{
			process_node(current_a, current_b, count_a, count_b);
			count_a++;
			current_a = current_a->next;
			if (current_a == stack_a->top)
				break ;
		}
		if (current_b_next(stack_b, &current_b, &count_b) == 1)
			break ;
	}
	current_a = stack_a->top;
	current_b = stack_b->top;
}

void	calculate_cost2(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		count_a;
	int		count_b;

	current_b = stack_b->top;
	count_b = 0;
	while (current_b)
	{
		current_a = stack_a->top;
		count_a = 0;
		while (current_a)
		{
			process_node2(current_a, current_b, count_a, count_b);
			count_a++;
			current_a = current_a->next;
			if (current_a == stack_a->top)
				break ;
		}
		if (current_b_prev(stack_b, &current_b, &count_b) == 1)
			break ;
	}
	current_b = stack_b->top;
}

void	calculate_cost3(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		count_a;
	int		count_b;

	current_b = stack_b->top;
	count_b = 0;
	while (current_b)
	{
		current_a = stack_a->top;
		count_a = 0;
		while (current_a)
		{
			process_node3(current_a, current_b, count_a, count_b);
			count_a++;
			current_a = current_a->prev;
			if (current_a == stack_a->top)
				break ;
		}
		if (current_b_next(stack_b, &current_b, &count_b) == 1)
			break ;
	}
	current_b = stack_b->top;
}

void	calculate_cost4(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		count_a;
	int		count_b;

	current_b = stack_b->top;
	count_b = 0;
	while (current_b)
	{
		current_a = stack_a->top;
		count_a = 0;
		while (current_a)
		{
			process_node2(current_a, current_b, count_a, count_b);
			count_a++;
			current_a = current_a->prev;
			if (current_a == stack_a->top)
				break ;
		}
		if (current_b_prev(stack_b, &current_b, &count_b) == 1)
			break ;
	}
}
