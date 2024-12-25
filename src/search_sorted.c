/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:34:13 by yonuma            #+#    #+#             */
/*   Updated: 2024/12/25 12:39:41 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_cost(t_node *current_b, int new_cost, int direction)
{
	if (current_b->cost > new_cost)
	{
		current_b->cost = new_cost;
		current_b->direction = direction;
	}
}

void	process_node(t_node *current_a, t_node *current_b, int count_a,
		int count_b)
{
	int	new_cost;

	if (current_a->prev->index < current_b->index
		&& current_b->index < current_a->index)
	{
		new_cost = 1 + count_a + count_b;
		update_cost(current_b, new_cost, 0);
	}
}

void	process_node2(t_node *current_a, t_node *current_b, int count_a,
		int count_b)
{
	int	new_cost;

	if (current_a->prev->index < current_b->index
		&& current_b->index < current_a->index)
	{
		new_cost = 1 + count_a + count_b;
		update_cost(current_b, new_cost, 1);
	}
}

void	process_node3(t_node *current_a, t_node *current_b, int count_a,
		int count_b)
{
	int	new_cost;

	if (current_a->prev->index < current_b->index
		&& current_b->index < current_a->index)
	{
		new_cost = 1 + count_a + count_b;
		update_cost(current_b, new_cost, 0);
	}
}
