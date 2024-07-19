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

// void	push(t_stack *src, t_stack *dest)
// {
//     t_node	*tmp;

    
// }

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

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void    ra(t_stack *stack_a)
{
    stack_a->top = stack_a->top->next;
    ft_printf("ra\n");
}

void    rb(t_stack *stack_b)
{
    stack_b->top = stack_b->top->next;
    ft_printf("rb\n");
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void    rra(t_stack *stack_a)
{
    stack_a->top = stack_a->top->prev;
    ft_printf("rra\n");
}

void    rrb(t_stack *stack_b)
{
    stack_b->top = stack_b->top->prev;
    ft_printf("rrb\n");
}

void    push(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *tmp;

    if (!stack_b->top)
        return;
    tmp = stack_b->top;    
    stack_b->top->prev->next = stack_b->top->next;
    stack_b->top->next->prev = stack_b->top->prev;
    if (stack_b->top == stack_b->top->next)
        stack_b->top = NULL;
    else
        stack_b->top = stack_b->top->next;
    tmp->next = stack_a->top;
    tmp->prev = stack_a->top->prev;
    stack_a->top->prev->next = tmp;
    stack_a->top->prev = tmp;
    stack_a->top = tmp;
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_b, stack_a);
    ft_printf("pb\n");
}
