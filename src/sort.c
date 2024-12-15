/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:30:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/15 17:24:25 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push_1(t_node *tmp, t_stack *src, t_stack *dst)
{
	if (src->top->next == src->top)
	src->top = NULL;
	else
	{
		src->top->prev->next = src->top->next;
		src->top->next->prev = src->top->prev;
		src->top = src->top->next;
	}
	if (dst->top == NULL)
	{
		dst->top = tmp;
		dst->top->next = dst->top;
		dst->top->prev = dst->top;
	}
	else
	{
		tmp->next = dst->top;
		tmp->prev = dst->top->prev;
		dst->top->prev->next = tmp;
		dst->top->prev = tmp;
		dst->top = tmp;
	}
}

void	push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (src->top == NULL)
		return ;
	tmp = src->top;
	push_1(tmp, src, dst);
}
