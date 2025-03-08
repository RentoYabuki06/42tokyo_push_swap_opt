/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:10:13 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 15:37:46 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp_bottom;

	if (!stack || !(stack->value) || !(stack->next->value))
		return ;
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	tmp->next = NULL;
	tmp_bottom = (*stack)->bottom;
	(*stack)->bottom = tmp;
	tmp_bottom->next = tmp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		ft_rr(a, b);
	ft_current_index(*a);
	ft_current_index(*b);
}