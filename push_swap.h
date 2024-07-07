/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:08:16 by yonuma            #+#    #+#             */
/*   Updated: 2024/07/07 17:44:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdarg.h>
#include <stdio.h>

//struct
typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

int		ft_atoi(const char *str);
int     ft_lstsize(t_node *lst);
void    push_stack(t_stack *stack, int value);
void    push_swap(t_stack *stack_a, t_stack *stack_b);
// printf
int		ft_write_nbr(int n);
int		ft_putnbr(int n);
int		return_percent(void);
int		ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
int		return_int(int str);
int		return_chr(int c);
int		return_pointer(void *str);
int		print_unsigned_int(unsigned int n);
int		return_ten(unsigned int n);
int		return_str(char *str);
int		ft_format(va_list ap, const char str);
int		return_len_base(unsigned int n, char c);
// sort
void    sort_3(t_stack *stack_a);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rra(t_stack *stack_a);

int     is_empty(t_stack *stack);
void    radix_sort(t_stack *stack_a);

#endif