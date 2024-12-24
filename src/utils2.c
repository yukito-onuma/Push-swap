/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:31:36 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/24 22:18:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");
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

void    free_stack(t_stack *stack_a, t_stack *stack_b)
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
