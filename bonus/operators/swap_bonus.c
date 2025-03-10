/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:35:38 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/09 15:44:20 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	ft_test_swap(t_test_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	ft_test_sa(t_test_stack **stack_a)
{
	ft_test_swap(stack_a);
}

void	ft_test_sb(t_test_stack **stack_b)
{
	ft_test_swap(stack_b);
}

void	ft_test_ss(t_test_stack **stack_a, t_test_stack **stack_b)
{
	ft_test_swap(stack_a);
	ft_test_swap(stack_b);
}
