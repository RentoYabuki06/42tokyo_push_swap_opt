/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:40:03 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 16:14:45 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	ft_test_reverse_rotate(t_test_stack **stack)
{
	t_test_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_test_find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	ft_test_rra(t_test_stack **stack_a)
{
	ft_test_reverse_rotate(stack_a);
}

void	ft_test_rrb(t_test_stack **stack_b)
{
	ft_test_reverse_rotate(stack_b);
}

void	ft_test_rrr(t_test_stack **stack_a, t_test_stack **stack_b)
{
	ft_test_reverse_rotate(stack_a);
	ft_test_reverse_rotate(stack_b);
}
