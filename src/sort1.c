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
	t_node	*a;
	t_node	*b;

	a = stack_a->top;
	b = a->next;
	a->next = b->next;
	a->next->prev = a;
	b->prev = a->prev;
	b->prev->next = b;
	b->next = a;
	a->prev = b;
	stack_a->top = b;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	t_node	*a;
	t_node	*b;

	a = stack_b->top;
	b = a->next;
	a->next = b->next;
	a->next->prev = a;
	b->prev = a->prev;
	b->prev->next = b;
	b->next = a;
	a->prev = b;
	stack_b->top = b;
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
