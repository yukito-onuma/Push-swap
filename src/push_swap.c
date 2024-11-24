/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:20:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/22 21:03:26 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void compress_coordinates(t_stack *stack_a)
{
	t_node 	*current;
	t_node 	*compare;
	int 	index;

	if (!stack_a || !stack_a->top)
		return;
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
				break;
		}
		current->index = index;
		current = current->next;
		if (current == stack_a->top)
			break;
	}
}

int get_min(t_stack *stack_a)
{
	t_node	*current;
	int		min;

	current = stack_a->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
		if (current == stack_a->top)
			break;
	}
	return (min);
}

int get_max(t_stack *stack_a)
{
	t_node	*current;
	int		max;

	current = stack_a->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
		if (current == stack_a->top)
			break;
	}
	return (max);
}

void	search_sorted1(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node 	*current_a;
	t_node 	*current_b;
	int 	count;

	current_a = stack_a->top;
	current_b = stack_b->top;
	if (stack_b->top->value < min)
	{
		stack_b->top->cost = 1;
		return ;
	}
	else if (stack_b->top->value > max)
	{
		stack_b->top->cost = 2;
		return ;
	}
	count = 2;
	while (current_b->next != stack_b->top)
	{
		while (current_a->next != stack_a->top)
		{
			if (current_a->value < current_b->value && current_b->value < current_a->next->value)
				current_b->cost = count;
			else
			{
				current_a = current_a->next;
				count++;
			}
			current_a = current_a->next;
			printf("check!!\n");
		}
		printf("kita!!\n");
		current_b = current_b->next;
	}
	stack_a->top = current_a;
	stack_b->top = current_b;
}

void	search_and_push(t_stack *stack_a, t_stack *stack_b)
{
	int min;
	int max;

	min = get_min(stack_a);
	max = get_max(stack_a);
	search_sorted1(stack_a, stack_b, min, max);
	printf("stack_b->top->cost = %d\n", stack_b->top->cost);
	printf("stack_b->top->next->cost = %d\n", stack_b->top->next->cost);
}

void    sort_large(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	size;
	(void)argc;
	compress_coordinates(stack_a);
	size = ft_lstsize(stack_a->top);
	while (ft_lstsize(stack_a->top) > size / 3)
	{
		if (stack_a->top->index + 1 > size / 3)
		{
			if (stack_a->top->index + 1 > 2 * size / 3)
				pb(stack_a, stack_b);
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
		pb(stack_a, stack_b);
	sort_3(stack_a);
	search_and_push(stack_a, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	else
		sort_large(stack_a, stack_b, argc);
}
