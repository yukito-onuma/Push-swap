/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:50:56 by marvin            #+#    #+#             */
/*   Updated: 2024/07/05 10:50:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_node *lst)
{
	int	i;
    t_node *top;

	if (!lst)
		return (0);
	i = 1;
    top = lst;
	while (lst->next != top)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}