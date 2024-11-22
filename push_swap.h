/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:16:37 by yonuma            #+#    #+#             */
/*   Updated: 2024/11/22 20:48:06 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

//struct
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
}   t_stack;

int	    ft_lstsize(t_node *lst);
void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc);
int	    ft_atoi(const char *str);
int	    ft_isdigit(int c);
int	    ft_printf(const char *format, ...);
void    push_stack(t_stack *stack, int value);
void    push(t_stack *src, t_stack *dst);
void    compress_coordinates(t_stack *stack_a);

//sort
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);

#endif