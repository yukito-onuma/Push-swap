/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:16:37 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/30 20:38:32 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// struct
typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				direction;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

int					ft_lstsize(t_node *lst);
void				push_swap(t_stack *stack_a, t_stack *stack_b);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_isdigit(int c);
int					ft_printf(const char *format, ...);
void				push_stack(t_stack *stack, int value);
void				push(t_stack *src, t_stack *dst);
void				compress_coordinates(t_stack *stack_a);

// rotate_stack_a
void				rotate_stack_a(t_stack *stack_a, t_stack *stack_b);

// sort
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);

// sort1
void				calculate_cost1(t_stack *stack_a, t_stack *stack_b);
void				calculate_cost2(t_stack *stack_a, t_stack *stack_b);
void				calculate_cost3(t_stack *stack_a, t_stack *stack_b);
void				calculate_cost4(t_stack *stack_a, t_stack *stack_b);
void				process_node(t_node *current_a, t_node *current_b,
						int count_a, int count_b);
void				process_node2(t_node *current_a, t_node *current_b,
						int count_a, int count_b);
void				process_node3(t_node *current_a, t_node *current_b,
						int count_a, int count_b);
void				sort_a(t_stack *stack_a);
void				sort_large(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				sort_3(t_stack *stack_a);

// utils
int					print_error(void);
bool				check_duplicates(int *arr, int len);
int					get_min(t_stack *stack_a);
int					get_max(t_stack *stack_a);
void				init_cost(t_stack *stack_b);
void				minimum_cost(t_stack *stack_b);
int					check_input(char **argv, int *args, int argc);

// utils2
void				calc_cost_next(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				calc_cost_prev(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				define_ra_rra(t_stack *stack_a, t_stack *stack_b, int size);

int					check_is_sorted(t_stack *stack_a);
void				free_stack(t_stack *stack_a, t_stack *stack_b);

// utils3
int					current_b_next(t_stack *stack_b, t_node **current_b,
						int *count_b);
int					current_b_prev(t_stack *stack_b, t_node **current_b,
						int *count_b);
int					check(char **argv, int *args, int argc);

// sort_small
void				sort_small(t_stack *stack_a, t_stack *stack_b);

#endif
