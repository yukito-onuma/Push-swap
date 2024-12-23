/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:34:13 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/21 16:32:18 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_cost(t_node *current_b, int new_cost, int direction)
{
	if (current_b->cost > new_cost)
	{
		current_b->cost = new_cost;
		current_b->direction = direction;
	}
}

void	process_node(t_node *current_a, t_node *current_b, int count_a, int count_b)
{
	int new_cost;

	if (current_a->prev->index < current_b->index && current_b->index < current_a->index)
	{
		new_cost = 1 + count_a + count_b;
		update_cost(current_b, new_cost, 0);
	}
}

void	search_sorted1(t_stack *stack_a, t_stack *stack_b)
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
		count_b++;
		current_b = current_b->next;
		if (current_b == stack_b->top)
			break ;
	}
	current_a = stack_a->top;
	current_b = stack_b->top;
}

void	process_node2(t_node *current_a, t_node *current_b, int count_a, int count_b)
{
	int new_cost;

	if (current_a->prev->index < current_b->index && current_b->index < current_a->index)
	{
		new_cost = 1 + count_a + count_b;
		update_cost(current_b, new_cost, 1);
	}
}

void	search_sorted2(t_stack *stack_a, t_stack *stack_b)
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
		count_b++;
		current_b = current_b->prev;
		if (current_b == stack_b->top)
			break ;
	}
	current_b = stack_b->top;
}

void	process_node3(t_node *current_a, t_node *current_b, int count_a, int count_b)
{
	int new_cost;

	if (current_a->prev->index < current_b->index && current_b->index < current_a->index)
	{
		new_cost = 1 + count_a + count_b;
		update_cost(current_b, new_cost, 0);
	}
}

void	search_sorted3(t_stack *stack_a, t_stack *stack_b)
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
		count_b++;
		current_b = current_b->next;
		if (current_b == stack_b->top)
			break ;
	}
	current_b = stack_b->top;
}

void	search_sorted4(t_stack *stack_a, t_stack *stack_b)
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
		count_b++;
		current_b = current_b->prev;
		if (current_b == stack_b->top)
			break ;
	}
}
