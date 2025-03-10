/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:26:22 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/10 12:38:15 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	ft_read_input(char *str, t_test_stack **a, t_test_stack **b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_test_sa(a);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_test_sb(b);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		ft_test_ss(a, b);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_test_pa(a, b);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_test_pb(a, b);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_test_ra(a);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_test_rb(b);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		ft_test_rr(a, b);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_test_rra(a);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_test_rrb(b);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		ft_test_rrr(a, b);
}

static bool	ft_check_input(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		return (false);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		return (false);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (false);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (false);
	return (true);
}

static void	ft_loop_wait(t_test_stack **a, t_test_stack **b)
{
	char	*str;

	while (true)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str || ft_strncmp(str, "stop\n", 5) == 0)
			break ;
		if (ft_check_input(str))
		{
			ft_putstr_fd("Error\n", 2);
		}
		else
			ft_read_input(str, a, b);
	}
}

static bool	ft_check_sorted(t_test_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_test_stack	*a;
	t_test_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit (EXIT_SUCCESS);
	ft_init_stack_test(&a, argv + 1);
	ft_loop_wait(&a, &b);
	if (ft_check_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
