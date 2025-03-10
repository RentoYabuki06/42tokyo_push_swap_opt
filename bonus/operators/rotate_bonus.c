/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:35:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 15:48:10 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	ft_test_rotate(t_test_stack **stack)
{
	t_test_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_test_find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_test_ra(t_test_stack **stack_a)
{
	ft_test_rotate(stack_a);
}

void	ft_test_rb(t_test_stack **stack_b)
{
	ft_test_rotate(stack_b);
}

void	ft_test_rr(t_test_stack **stack_a, t_test_stack **stack_b)
{
	ft_test_rotate(stack_a);
	ft_test_rotate(stack_b);
}
