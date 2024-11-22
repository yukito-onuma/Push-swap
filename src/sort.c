/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:30:08 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/22 19:56:35 by yonuma           ###   ########.fr       */
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

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pb\n");
}

void    push(t_stack *src, t_stack *dst)
{
    t_node  *tmp;

    if (src->top == NULL)
        return;
    tmp = src->top;    
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
