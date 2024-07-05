/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:01:13 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 18:01:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sa(t_stack *stack_a)
{
    int tmp;

    tmp = stack_a->top->value;
    stack_a->top->value = stack_a->top->next->value;
    stack_a->top->next->value = tmp;
    ft_printf("sa\n");
}

void    sb(t_stack *stack_b)
{
    int tmp;

    tmp = stack_b->top->value;
    stack_b->top->value = stack_b->top->next->value;
    stack_b->top->next->value = tmp;
    ft_printf("sb\n");
}

void    ra(t_stack *stack_a)
{
    stack_a->top = stack_a->top->next;
    printf("ra\n");
}

void    rra(t_stack *stack_a)
{
    stack_a->top = stack_a->top->prev;
    printf("rra\n");
}