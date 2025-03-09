/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:10:01 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 20:22:25 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!*from)
		return ;
	node = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->next = NULL;
	node->prev = NULL;
	if (*to)
	{
		*to = node;
		node->next = NULL;
	}
	else
	{
		node->next = *to;
		node->next->prev = node;
		*to = node;
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
