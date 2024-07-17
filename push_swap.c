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

void	push_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;
	int	ave;
	int	number;

	max = check_max(stack_a);
	min = check_min(stack_a);
	ave = (max + min) / 2;
	number = 2;
	while (number > 0)
	{
		while (stack_a->top == stack_a->top->next) // 間違ってる。１周するまで見る
		{
			if (stack_a->top->value > ave)
				pb(stack_a, stack_b);
		}

		number --;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

// 	今のままだと効率が悪いのでやはり何パターンか計算すべき
// void	choice_command(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	max;
// 	int	min;
// 	int	ave;
// 	int	sa; // kakuninn
// 	int	sa2; // kakuninn

// 	max = 0;
// 	min = 0;
// 	//tmp = stack_a->top;
// 	while (/*stack_a->top->next != tmp && */ft_lstsize(stack_a->top) > 3)
// 	{
// 		ave = (check_max(stack_a) + check_min(stack_a)) / 5 * 4;
// 		if (stack_a->top->value >= ave)
// 		{
// 			//-------受け取ったvalueを挿入ソート-------------------------------------
// 			if (stack_a->top->value > max)
// 			{
// 				while (stack_b->top && stack_b->top->value != max)
// 					rb(stack_b);
// 				pb(stack_a, stack_b);
// 			}
// 			else if (stack_a->top->value < min)
// 			{
// 				while (stack_b->top->value == max)
// 					pb(stack_a, stack_b);
// 				rb(stack_b);
// 			}
// 			else
// 			{
// 				if (stack_b->top)
// 				{
// 					while (!(stack_a->top->value > stack_b->top->value
// 						&& stack_a->top->value < stack_b->top->prev->value))
// 						{
// 							sa = ft_abs(stack_b->top->value - stack_a->top->value);
// 							sa2 = ft_abs(stack_b->top->prev->value - stack_a->top->value);

// 							if (sa >= sa2)
// 								rrb(stack_b);
// 							else
// 								rb(stack_b);
// 						}
// 				}
// 				pb(stack_a, stack_b);
// 			}
// 			max = check_max(stack_b);
// 			min = check_min(stack_b);
// 		}
// 		ra(stack_a);
// 		//------------------ここまで---------------------------------------------
// 	}
// }

void	min_start(t_stack *stack_a, int min)
{
	while (stack_a->top->value != min)
		rra(stack_a);
}

void	return_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	max2;

	while (stack_b->top != NULL)
	{
		min = check_min(stack_a);
		max = check_max(stack_a);
		max2 = check_max(stack_b);
		while (ft_lstsize(stack_b->top) != 0)
		{
			while (stack_b->top->value != max2)
				rrb(stack_b);
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

int contains_less_than_range2(t_stack *stack, int range2) {
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

void digit_sort(t_stack *stack_a, t_stack *stack_b) {
    int 	range1;
    int 	range2;

    range1 = (check_max(stack_a) - check_min(stack_a)) / 3;
    range2 = range1 * 2;
    while (contains_less_than_range2(stack_a, range2))
	{
        if (stack_a->top->value <= range1)
		{
            pb(stack_a, stack_b);
            rb(stack_b);
        }
		else if (stack_a->top->value > range1 && stack_a->top->value <= range2)
            pb(stack_a, stack_b);
        else
            rra(stack_a);
    }
	while (ft_lstsize(stack_a->top) != 0)
		pb(stack_a, stack_b);
	printf("end\n");
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	digit_sort(stack_a, stack_b);
	// choice_command(stack_a, stack_b);
	// sort_3(stack_a);
	// return_stack_a(stack_a, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->top) <= 3)
		sort_3(stack_a);
	else
		sort_large(stack_a, stack_b);
}
