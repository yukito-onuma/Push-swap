/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:31:36 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/31 17:38:03 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

bool	check_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && arr[i] == arr[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*tmp;

	current = stack_a->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
		if (current == stack_a->top)
			break ;
	}
	current = stack_b->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
		if (current == stack_b->top)
			break ;
	}
}

void	compress_coordinates(t_stack *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack_a->top;
	while (current)
	{
		index = 1;
		compare = stack_a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
			if (compare == stack_a->top)
				break ;
		}
		current->index = index;
		current = current->next;
		if (current == stack_a->top)
			break ;
	}
}

int	check_is_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->top;
	while (current->next != stack_a->top)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
