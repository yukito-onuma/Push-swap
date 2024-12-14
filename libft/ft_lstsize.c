/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:36:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 20:21:25 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_node *lst)
{
	int		count;
	t_node	*tmp;

	if (!lst)
		return (0);
	count = 1;
	tmp = lst->next;
	while (tmp && tmp != lst)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
