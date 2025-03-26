/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:09:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/26 14:32:45 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_len(*stack_a) == 2)
		ft_sa(stack_a);
	else if (ft_stack_len(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_stack_len(*stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ft_stack_len(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_large(stack_a, stack_b);
}

static void	ft_free_all(t_stack **a, char **nbr, bool is_split)
{
	ft_free_stack(a);
	ft_free_split(nbr, is_split);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**nbr;
	bool	is_split;

	stack_a = NULL;
	stack_b = NULL;
	nbr = NULL;
	is_split = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_SUCCESS);
	else if (argc == 2)
	{
		nbr = ft_push_swap_split(argv[1], ' ');
		is_split = true;
	}
	else
		nbr = argv + 1;
	if (ft_init_stack_a(&stack_a, nbr))
		ft_free_error(&stack_a, nbr, is_split);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_free_all(&stack_a, nbr, is_split);
	return (EXIT_SUCCESS);
}
