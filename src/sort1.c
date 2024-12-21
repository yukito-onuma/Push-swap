/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:07:50 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/15 21:00:08 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->top->next = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	t_node	*tmp;

	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->top->next = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_stack *stack_a)
{
	stack_a->top = stack_a->top->next;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	stack_b->top = stack_b->top->next;
	ft_printf("rb\n");
}
