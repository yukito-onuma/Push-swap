/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:20:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/22 20:18:34 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top->index;
	second = stack_a->top->next->index;
	third = stack_a->top->next->next->index;

	if ((first > second) && (second > third))
	{
		ra(stack_a);
		sa(stack_a);
    }
	else if ((first < second) && (second > third) && (first < third))
    {
        rra(stack_a);
        sa(stack_a);
    }
	else if ((first > second) && (second < third) && (first < third))
        sa(stack_a);
	else if ((first < second) && (second > third))
        rra(stack_a);
	else if ((first > second) && (second < third))
        ra(stack_a);
}

void	compress_coordinates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	// if (!stack_a || !stack_a->top)
	// 	return ;
	current = stack_a->top;
	while (current)
	{
		index = 0;
		compare = stack_a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
			if (compare == stack_a->top)
				break ;
		}
		current->index = index;
		current = current->next;
		if (current == stack_a->top)
			break ;
	}
}

void	search_and_push(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	size;
	int	i;

	size = ft_lstsize(stack_b->top);
	min = get_min(stack_a);
	max = get_max(stack_a);
	i = 0;
	while (size > i)
	{
		init_cost(stack_b);
		search_sorted1(stack_a, stack_b, min, max);
		search_sorted2(stack_a, stack_b, min, max);
		search_sorted3(stack_a, stack_b, min, max);
		search_sorted4(stack_a, stack_b, min, max);
		minimum_cost(stack_b);
		min = get_min(stack_a);
		max = get_max(stack_a);
		rotate_stack_a(stack_a, stack_b, max, min);
		i++;
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	size;

	size = ft_lstsize(stack_a->top);
	while (ft_lstsize(stack_a->top) > size / 3)
	{
		if (stack_a->top->index  > size / 3)
		{
			if (stack_a->top->index + 1 > 2 * size / 3)
			{
				if (stack_a->top->index == max)
					ra(stack_a);
				pb(stack_a, stack_b);
			}
			else
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
		}
		else
			ra(stack_a);
	}
	while (ft_lstsize(stack_a->top) > 3)
	{
		if (stack_a->top->index == max || stack_a->top->index == min)
			ra(stack_a);
		else
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	search_and_push(stack_a, stack_b);
	sort_a(stack_a);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int min;
	int max;

	compress_coordinates(stack_a);
	min = get_min(stack_a);
	max = get_max(stack_a);
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	else
		sort_large(stack_a, stack_b, min, max);
}
