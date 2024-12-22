/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:16:37 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/22 20:18:50 by yonuma           ###   ########.fr       */
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
int					ft_isdigit(int c);
int					ft_printf(const char *format, ...);
void				push_stack(t_stack *stack, int value);
void				push(t_stack *src, t_stack *dst);
void				compress_coordinates(t_stack *stack_a);

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
void				search_sorted1(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				search_sorted2(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				search_sorted3(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				search_sorted4(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				rotate_stack_a(t_stack *stack_a, t_stack *stack_b, int max,
						int min);
void				sort_a(t_stack *stack_a);
void				sort_large(t_stack *stack_a, t_stack *stack_b, int min,
						int max);

// utils
int					print_error(void);
bool				check_duplicates(int *arr, int len);
int					get_min(t_stack *stack_a);
int					get_max(t_stack *stack_a);
void				init_cost(t_stack *stack_b);
void				minimum_cost(t_stack *stack_b);
int					check_input(char **argv, int *args);

// utils2
void				calc_cost_next(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				calc_cost_prev(t_stack *stack_a, t_stack *stack_b, int min,
						int max);
void				define_ra_rra(t_stack *stack_a, t_stack *stack_b, int size);

void	print_stack(t_stack *stack);

#endif
