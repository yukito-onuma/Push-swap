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

	if (a > b && b < c && a > c) // 3 1 2
		ra(stack_a);
	else if (a > b && b > c && a > c) // 3 2 1
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (a > b && b < c && a < c) // 2 1 3
		sa(stack_a);
	else if (a < b && b > c && a < c) // 1 3 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c) // 2 3 1
		rra(stack_a);
}

int	check_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	tmp = stack->top;
	max = tmp->value;
	while (tmp->next != stack->top)
	{
		tmp = tmp->next;
		if (max < tmp->value)
			max = tmp->value;
	}
	return (max);
}

int	check_min(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	tmp = stack->top;
	min = tmp->value;
	while (tmp->next != stack->top)
	{
		tmp = tmp->next;
		if (min > tmp->value)
			min = tmp->value;
	}
	return (min);
}

void	choice_command(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

	max = 0;
	min = 0;
	while (ft_lstsize(stack_a->top) > 3)
	{
		if (stack_a->top->value > max)
		{
			while (stack_b->top && stack_b->top->value != max)
				rb(stack_b);
			pb(stack_a, stack_b);
		}
		else if (stack_a->top->value < min)
		{
			while (stack_b->top->value == max)
				pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
		{
			if (stack_b->top)
			{
				while (!(stack_a->top->value > stack_b->top->value
					&& stack_a->top->value < stack_b->top->prev->value))
        				rb(stack_b);
			}
			pb(stack_a, stack_b);
		}
		max = check_max(stack_b);
		min = check_min(stack_b);
	}
}

void	min_start(t_stack *stack_a, int min)
{
	while (stack_a->top->value != min)
		ra(stack_a);
}

void	return_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	while (stack_b->top != NULL)
	{
		min = check_min(stack_a);
		max = check_max(stack_a);
		while (ft_lstsize(stack_b->top) != 0)
		{
			if (stack_b->top->value < min)
			{
				while (stack_a->top->value != min)
					ra(stack_a);
				pa(stack_a, stack_b);
			}
			else if (stack_a->top->value > max)
			{
				while (stack_a->top->prev->value != min)
					rra(stack_a);
			}
			else
			{
				while ((stack_a->top->value < stack_b->top->value
					&& stack_a->top->prev->value > stack_b->top->value)
					|| (stack_a->top->value > stack_b->top->value
					&& stack_a->top->prev->value > stack_b->top->value))
						rra(stack_a);
				pa(stack_a, stack_b);
			}
			min = check_min(stack_a);
			max = check_max(stack_a);
		}
	}
	min_start(stack_a, min);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	choice_command(stack_a, stack_b);
	sort_3(stack_a);
	return_stack_a(stack_a, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	else
		sort_large(stack_a, stack_b);
}
