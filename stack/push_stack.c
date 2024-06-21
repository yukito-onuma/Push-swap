/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su_yu_ <su_yu_@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:49:15 by su_yu_            #+#    #+#             */
/*   Updated: 2024/06/10 11:05:05 by su_yu_           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

t_node *create_node(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
        return NULL;
    new_node->value = value;
    new_node->next = new_node;
    new_node->prev = new_node;
    return new_node;
}

void push_stack(t_stack *stack, int value)
{
    t_node *new_node = create_node(value);
    if (new_node == NULL)
        return;
    if (stack->top == NULL)
        stack->top = new_node;
    else
    {
        new_node->next = stack->top;
        new_node->prev = stack->top->prev;
        stack->top->prev->next = new_node;
        stack->top->prev = new_node;
        stack->top = new_node;
    }
}