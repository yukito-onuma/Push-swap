/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:25:58 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/15 17:24:13 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	if (stack->top == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		stack->top = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev->next = new_node;
		stack->top->prev = new_node;
	}
}
