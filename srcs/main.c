/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:09:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/08 20:54:05 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_SUCCESS);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_init_stack_a(&stack_a, argv + 1);
	if (!ft_is_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) == 2)
			ft_sa(&stack_a);
		else if(ft_stack_len(stack_a) == 3)
			ft_sort_three(&stack_a);
		else if(ft_stack_len(stack_a) == 4)
			ft_sort_four(&stack_a, &stack_b);
		else if(ft_stack_len(stack_a) == 5)
			ft_sort_five(&stack_a, &stack_b);
		else 
			ft_sort_large(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (EXIT_SUCCESS);
}
