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

int check_max(t_stack *stack)
{
    t_node 	*tmp;
    int 	max;

    tmp = stack->top;
    max = tmp->value;
    while (1)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
		if (tmp == stack->top)
			break;
	}
    return (max);
}

int check_min(t_stack *stack)
{
    t_node 	*tmp;
    int 	min;

    tmp = stack->top;
    min = tmp->value;
    while (1)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
		if (tmp == stack->top)
			break;
	}
    return (min);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	min_start(t_stack *stack_a, int min)
{
	while (stack_a->top->value != min)
		rra(stack_a);
}

void	return_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	sa; // kakuninn
	int	sa2; // kakuninn

	pb(stack_a, stack_b);
	// rrb(stack_a);
	// pa(stack_a, stack_b);
	min = check_min(stack_b);
	max = check_max(stack_b);
	while (stack_a->top)
	{
		if (stack_a->top->value < min)
		{
			while (stack_b->top->value != min)
				rrb(stack_b);
			pb(stack_a, stack_b);
		}
		else if (stack_b && stack_a->top->value > max)
		{
			while (stack_b->top->value != min)
				rb(stack_b);
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
		{
			while (!(stack_a->top->value < stack_b->top->value
				&& stack_a->top->value > stack_b->top->prev->value))
				{
					sa = ft_abs(stack_b->top->value - stack_a->top->value);
					sa2 = ft_abs(stack_b->top->prev->value - stack_a->top->value);
					if (sa >= sa2)
						rrb(stack_b);
					else
						rb(stack_b);
				}
			pb(stack_a, stack_b);
		}
		min = check_min(stack_b);
		max = check_max(stack_b);
	}
}

int contains_less_than_range2(t_stack *stack, int range2)
{
    t_node *tmp;
	
	tmp = stack->top;
    if (tmp->value <= range2)
        return (1);
    tmp = tmp->next;
    while (tmp != stack->top)
	{
        if (tmp->value <= range2)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

double	ft_ave(t_stack *stack, int size)
{
    double ave;
    t_node *tmp;

    tmp = stack->top;
	ave = 0.0;
    while (tmp != NULL)
    {
        ave += tmp->value / size;
        tmp = tmp->next;
    }
    return (ave);
}

void	ft_partition(t_stack	*src, t_stack	*dst, char	alpha, int	partition)
{
	double	ave;
	int		size;
	int		count;

	size = ft_lstsize(src->top);
	count = 0;
	ave = ft_ave(src, size);
	while (src->top && size / partition >= count)
	{
		if (src->top->value >= ave)
		{
			if (alpha == 'a')
				pa(src, dst);
			else
				pb(src, dst);
		}
		else
		{
			if (alpha == 'a')
			{
				pa(src, dst);
				ra(dst);
			}
			else
			{
				pb(src, dst);
				rb(dst);
			}
		}
		count++;
	}
}

void digit_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		partition;
	int		size;
	
	partition = 2;
	size = ft_lstsize(stack_a->top);
	printf("\nsize = %d, partition = %d\n", size, partition);
	while ((size / partition >= 50)
		|| (size / partition < 50 && partition % 2 == 0)) //　最終的にstack_bに入る条件、のはず
		{
			if (partition % 2 == 0)
			{
				ft_partition(stack_a, stack_b, 'b', partition);
				if (stack_a->top == NULL)
					partition++;
			}
			else
			{
				ft_partition(stack_b, stack_a, 'a', partition);
				if (stack_b->top == NULL)
					partition++;
			}
		}
}

// void digit_sort(t_stack *stack_a, t_stack *stack_b)
// {
//     int 	range1;
//     int 	range2;
// 	int 	max;

//     range1 = (check_max(stack_a) - check_min(stack_a)) / 3;
//     range2 = range1 * 2;
//     while (contains_less_than_range2(stack_a, range2))
// 	{
//         if (stack_a->top->value <= range1)
// 		{
//             pb(stack_a, stack_b);
//             rb(stack_b);
//         }
// 		else if (stack_a->top->value > range1 && stack_a->top->value <= range2)
//             pb(stack_a, stack_b);
//         else
//             rra(stack_a);
//     }
// 	while (stack_a->top)
// 		pb(stack_a, stack_b);
// 	max = check_max(stack_b);
// 	while (stack_b->top->value >= range2)
// 	{
// 		if (stack_b->top->value >= (max - range2) / 2 + range2)
// 			pa(stack_a, stack_b);
// 		else if (stack_b->top->value < (max - range2) / 2 + range2)
// 		{
// 			pa(stack_a, stack_b);
// 			ra(stack_a);
// 		}
// 	}
// 	max = check_max(stack_b);
// 	while (stack_b->top->value >= range1)
// 	{
// 		if (stack_b->top->value >= (max - range1) / 2 + range1)
// 			pa(stack_a, stack_b);
// 		else if (stack_b->top->value < (max - range1) / 2 + range1)
// 		{
// 			pa(stack_a, stack_b);
// 			ra(stack_a);
// 		}
// 	}
// 	max = check_max(stack_b);
// 	while (stack_b->top)
// 	{
// 		if (stack_b->top->value >= max / 2)
// 			pa(stack_a, stack_b);
// 		else
// 		{
// 			pa(stack_a, stack_b);
// 			ra(stack_a);
// 		}
// 	}
// }

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	digit_sort(stack_a, stack_b);
	return_stack_b(stack_a, stack_b);
	//min_start(stack_a, check_min(stack_a));
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	else
		sort_large(stack_a, stack_b);
}
