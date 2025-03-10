/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:41:03 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 12:39:59 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	ft_test_push(t_test_stack **from, t_test_stack **to)
{
	t_test_stack	*node;

	if (!*from)
		return ;
	node = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	node->prev = NULL;
	if (!*to)
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

void	ft_test_pa(t_test_stack **stack_a, t_test_stack **stack_b)
{
	ft_test_push(stack_b, stack_a);
}

void	ft_test_pb(t_test_stack **stack_a, t_test_stack **stack_b)
{
	ft_test_push(stack_a, stack_b);
}
