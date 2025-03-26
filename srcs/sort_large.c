/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:48:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/26 14:43:52 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*ft_get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	ft_move_atob(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		ft_rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median) \
		&& !(cheapest_node->target_node->above_median))
		ft_rev_rotate_both(stack_a, stack_b, cheapest_node);
	ft_prep_for_push(stack_a, cheapest_node, 'a');
	ft_prep_for_push(stack_b, cheapest_node->target_node, 'b');
	ft_pb(stack_a, stack_b);
}

static void	ft_move_btoa(t_stack **stack_a, t_stack **stack_b)
{
	ft_prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	ft_pa(stack_a, stack_b);
}

static void	ft_min_on_top(t_stack **stack)
{
	t_stack	*min_node;

	min_node = ft_find_min(*stack);
	while ((*stack)->value != min_node->value)
	{
		if (min_node->above_median)
			ft_ra(stack);
		else
			ft_rra(stack);
	}
}

void	ft_sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stack_len(*stack_a);
	if (len-- > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	if (len-- > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b);
	while (len-- > 3 && !ft_is_sorted(*stack_a))
	{
		ft_init_nodes_a(*stack_a, *stack_b);
		ft_move_atob(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_init_nodes_b(*stack_a, *stack_b);
		ft_move_btoa(stack_a, stack_b);
	}
	ft_set_median(*stack_a);
	ft_min_on_top(stack_a);
}
