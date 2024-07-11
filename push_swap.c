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
		ra(stack_a);
		sa(stack_a);
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
			while (stack_b->top && stack_b->top->value != min)
				rb(stack_b);
			pb(stack_a, stack_b);
		}
		else if (stack_a->top->value < min)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
		{
			if (stack_b->top)
			{
				while (stack_a->top->value > stack_b->top->value)
					rb(stack_b);
			}
			pb(stack_a, stack_b);
		}
		max = check_max(stack_b);
		min = check_min(stack_b);
	}
}

void	return_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->top != NULL)
	{
		int	min;
		int	max;

		min = stack_a->top->value;
		max = stack_a->top->prev->value;
		while (ft_lstsize(stack_b->top) != 0)
		{
			if (stack_b->top->value < min || stack_b->top->value > max)
				pa(stack_a, stack_b);
			else
			{
				while ((stack_b->top->value > stack_a->top->value)
					|| ft_lstsize(stack_b->top) == 0)
					ra(stack_a);
				pa(stack_a, stack_b);
			}
		}
	}
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
