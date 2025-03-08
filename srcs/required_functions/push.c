/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:10:01 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 15:04:19 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from) || !(*to) || !((*from)->value) || !((*to)->value))
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	tmp = ft_find_last(*from);
	// continue
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

int	ft_pa_int(t_stack **stack_a, t_stack **stack_b)
{
	ft_pa(stack_a, stack_b);
	return (1);
}

int	ft_pb_int(t_stack **stack_a, t_stack **stack_b)
{
	ft_pb(stack_a, stack_b);
	return (1);
}
