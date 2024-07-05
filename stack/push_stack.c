/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:49:15 by su_yu_            #+#    #+#             */
/*   Updated: 2024/07/05 11:58:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"

void push_stack(t_stack *stack, int value)
{
    t_node *new_node;
    
    new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
        return;
    new_node->value = value;
    if (stack->top == NULL)
    {
        new_node->prev = new_node;
		new_node->next = new_node;
        stack->top = new_node;
    }
    else
    {
        new_node->prev = stack->top->prev;
        new_node->next = stack->top;
        stack->top->prev->next = new_node;
        stack->top->prev = new_node;
    }
}
