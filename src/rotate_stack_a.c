/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:08:58 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/21 15:40:23 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	define_ra_rra(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		i;
	int		count;
	t_node	*current;

	current = stack_a->top;
	count = 0;
	i = 0;
	while (size > i)
	{
		if (current->prev->index < stack_b->top->index
			&& stack_b->top->index < current->index)
		{
			if (count < size / 2)
				while (count-- > 0)
					ra(stack_a);
			else
				while (count++ < size)
					rra(stack_a);
			break ;
		}
		count++;
		current = current->next;
		i++;
	}
}

void	rotate_stack_a(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	int		size;
	t_node	*current;

	size = ft_lstsize(stack_a->top);
	current = stack_a->top;
	if (stack_b->top->index < min || max < stack_b->top->index)
	{
		if (stack_b->top->index < min)
		{
			while (stack_a->top->index != min)
				ra(stack_a);
			pa(stack_b, stack_a);
		}
		else
		{
			while (stack_a->top->index != min)
				ra(stack_a);
			pa(stack_b, stack_a);
			ra(stack_a);
		}
		return ;
	}
	define_ra_rra(stack_a, stack_b, size);
	pa(stack_b, stack_a);
}
