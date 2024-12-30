/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:20:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/30 19:39:56 by yonuma           ###   ########.fr       */
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

void	search_and_push(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize(stack_b->top);
	i = 0;
	while (size > i)
	{
		init_cost(stack_b);
		calculate_cost1(stack_a, stack_b);
		calculate_cost2(stack_a, stack_b);
		calculate_cost3(stack_a, stack_b);
		calculate_cost4(stack_a, stack_b);
		minimum_cost(stack_b);
		rotate_stack_a(stack_a, stack_b);
		i++;
	}
}

void	pb_until3(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	size;

	size = ft_lstsize(stack_a->top);
	while (ft_lstsize(stack_a->top) > 3)
	{
		if (stack_a->top->index == max || stack_a->top->index == min)
			ra(stack_a);
		else if (stack_a->top->index > size / 4)
			pb(stack_a, stack_b);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int	size;

	size = ft_lstsize(stack_a->top);
	while (ft_lstsize(stack_a->top) > size / 2 + 1)
	{
		if (stack_a->top->index == max)
			ra(stack_a);
		if (stack_a->top->index >= (3 * size / 4))
			pb(stack_a, stack_b);
		else if (stack_a->top->index > size / 2)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
	pb_until3(stack_a, stack_b, min, max);
	sort_3(stack_a);
	search_and_push(stack_a, stack_b);
	sort_a(stack_a);
}

int    find_min_position(t_stack *stack)
{
    t_node    *current;
    int        min;
    int        min_pos;
    int        pos;

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

void    push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int    min_pos;
    int    size;

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

void    sort_small(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int i;

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

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	compress_coordinates(stack_a);
	if (check_is_sorted(stack_a) == 1)
		return ;
	min = get_min(stack_a);
	max = get_max(stack_a);
	if (ft_lstsize(stack_a->top) <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b, min, max);
	// if (ft_lstsize(stack_a->top) <= 100)
	// 	sort_3(stack_a);
	// else
	// 	sort_large(stack_a, stack_b, min, max);
}
