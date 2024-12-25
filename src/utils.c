/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:06:04 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/24 14:00:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min(t_stack *stack_a)
{
	t_node	*current;
	int		min;

	current = stack_a->top;
	min = current->index;
	while (1)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
		if (current == stack_a->top)
			break ;
	}
	return (min);
}

int	get_max(t_stack *stack_a)
{
	t_node	*current;
	int		max;

	current = stack_a->top;
	max = current->index;
	while (1)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
		if (current == stack_a->top)
			break ;
	}
	return (max);
}

void	minimum_cost(t_stack *stack_b)
{
	t_node	*current_b;
	t_node	*min_cost_node;

	if (!stack_b || !stack_b->top)
		return ;
	current_b = stack_b->top;
	min_cost_node = current_b;
	while (current_b)
	{
		if (current_b->cost < min_cost_node->cost)
			min_cost_node = current_b;
		current_b = current_b->next;
		if (current_b == stack_b->top)
			break ;
	}
	while (stack_b->top != min_cost_node)
	{
		if (min_cost_node->direction == 0)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	init_cost(t_stack *stack_b)
{
	t_node	*current_b;

	if (!stack_b || !stack_b->top)
		return ;
	current_b = stack_b->top;
	while (current_b)
	{
		current_b->cost = INT_MAX;
		current_b = current_b->next;
		if (current_b == stack_b->top)
			break ;
	}
}

void	sort_a(t_stack *stack_a)
{
	int	half_size;

	half_size = ft_lstsize(stack_a->top) / 2;
	while (stack_a->top->index != 1)
	{
		if (stack_a->top->index > half_size)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
