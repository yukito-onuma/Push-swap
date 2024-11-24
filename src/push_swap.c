/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:20:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/24 21:27:05 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

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

void	compress_coordinates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!stack_a || !stack_a->top)
		return ;
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

int	get_min(t_stack *stack_a)
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
			break ;
	}
	return (min);
}

int	get_max(t_stack *stack_a)
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
			break ;
	}
	return (max);
}

// void	search_sorted2(t_stack *stack_a, t_stack *stack_b, int min, int max)
// {
// 	t_node	*current_a;
// 	t_node	*current_b;
// 	int		count_a; // Aのカウント
// 	int		count_b; // Bのカウント
// 	int		count_loop; // 何周目のループか

// 	current_b = stack_b->top;
// 	(void)min;
// 	(void)max;

// 	count_b = 0;
// 	count_loop = 0;
// 	while (current_b)
// 	{
// 		current_a = stack_a->top;
// 		count_a = 0;
// 		while (current_a)
// 		{
// 			if (current_b->value < min || current_b->value > max)
// 			{
// 				current_b->cost = 1 + count_b + count_loop;
// 				count_b = 1;
// 				break ;
// 			}
// 			printf("current_a->value = %d, current_b->value: %d, current_b->cost: %d, count_a: %d, count_b: %d\n",
// 				current_a->value, current_b->value, current_b->cost, count_a, count_b);
// 			if (current_a->prev->value < current_b->value
// 				&& current_b->value < current_a->value)
// 			{
// 				current_b->cost = count_a + count_b;
// 				break ;
// 			}
// 			current_a = current_a->next;
// 			count_a++;
// 			if (current_a == stack_a->top)
// 				break ;
// 		}
// 		count_b = 1;
// 		count_loop++;
// 		current_b = current_b->prev;
// 		if (current_b == stack_b->top)
// 			break;
// 	}
// 	current_b = stack_b->top;
// }

void	search_sorted1(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node	*current_a;
	t_node	*current_b;
	int		count_a;
	int		count_b;

	current_b = stack_b->top;
	(void)min;
	(void)max;
	count_b = 1;
	while (current_b)
	{
		current_a = stack_a->top;
		count_a = 0;
		while (current_a)
		{
			printf("current_a->value = %d, current_b->value: %d, current_b->cost: %d, count: %d\n",
				current_a->value, current_b->value, current_b->cost, count_a);
			if (current_b->value < min || current_b->value > max)
			{
				current_b->cost = 1 + count_b;
				break ;
			}
			if (current_a->prev->value < current_b->value
				&& current_b->value < current_a->value)
			{
				current_b->cost = count_a + count_b;
				break ;
			}
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
	current_b = stack_b->top;
}

// void	minimum_cost(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node	*current_b;
// 	t_node	*min_cost_node;

// 	if (!stack_b || !stack_b->top)
// 		return ;
// 	current_b = stack_b->top;
// 	min_cost_node = current_b;
// 	while (current_b)
// 	{
// 		if (current_b->cost < min_cost_node->cost)
// 			min_cost_node = current_b;
// 		current_b = current_b->next;
// 		if (current_b == stack_b->top)
// 			break ;
// 	}
// 	while (stack_b->top != min_cost_node)
// 		rb(stack_b);
// 	pa(stack_b, stack_a);
// 	ra(stack_a);
// }

void	search_and_push(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int i;

	min = get_min(stack_a);
	max = get_max(stack_a);
	i = 0;
	while (ft_lstsize(stack_b->top) > i)
	{
		search_sorted1(stack_a, stack_b, min, max);
		// search_sorted2(stack_a, stack_b, min, max);
		// minimum_cost(stack_a, stack_b);
		i++;
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b, int argc)
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
