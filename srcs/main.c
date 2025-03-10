/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:09:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 20:48:01 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_len(*stack_a) == 2)
		ft_sa(stack_a);
	else if (ft_stack_len(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
		ft_sort_large(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**nbr;

	stack_a = NULL;
	stack_b = NULL;
	nbr = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_SUCCESS);
	else if (argc == 2)
		nbr = ft_push_swap_split(argv[1], ' ');
	else
		nbr = argv + 1;
	if (ft_init_stack_a(&stack_a, nbr))
		ft_free_error(&stack_a, nbr);
	if (!ft_is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_split(nbr);
	return (EXIT_SUCCESS);
}
