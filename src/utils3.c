/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:20:36 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/30 20:38:43 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	current_b_next(t_stack *stack_b, t_node **current_b, int *count_b)
{
	(*count_b)++;
	*current_b = (*current_b)->next;
	if (*current_b == stack_b->top)
		return (1);
	return (0);
}

int	current_b_prev(t_stack *stack_b, t_node **current_b, int *count_b)
{
	(*count_b)++;
	*current_b = (*current_b)->prev;
	if (*current_b == stack_b->top)
		return (1);
	return (0);
}

int	check(char **argv, int *args, int argc)
{
	if (args == NULL)
		return (0);
	if (check_input(argv, args, argc) == 1)
		return (print_error());
	if (!check_duplicates(args, argc - 1))
		return (print_error());
	return (0);
}
