/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:49:43 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/30 19:49:50 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		min_pos;
	int		pos;

	current = stack->top;
	min = current->index;
	min_pos = 0;
	pos = 0;
	while (1)
	{
		if (current->index < min)
		{
			min = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
		if (current == stack->top)
			break ;
	}
	return (min_pos);
}

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(stack_a->top);
	min_pos = find_min_position(stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos--)
			ra(stack_a);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize(stack_a->top);
	i = 0;
	while (i < size - 3)
	{
		push_min_to_b(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	while (ft_lstsize(stack_b->top) > 0)
		pa(stack_b, stack_a);
}
