/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:15:40 by yabukirento       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/10 17:34:51 by yabukirento      ###   ########.fr       */
=======
/*   Updated: 2025/03/10 15:24:34 by yabukirento      ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);

void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_large(t_stack **stack_a, t_stack **stack_b);

void	ft_init_stack_a(t_stack **stack, char **argv);

bool	ft_is_sorted(t_stack *stack);
int		ft_stack_len(t_stack *stack);
t_stack	*ft_find_last(t_stack *stack);
t_stack	*ft_find_min(t_stack *stack);
t_stack	*ft_find_max(t_stack *stack);

void	ft_init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	ft_init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	ft_set_median(t_stack *stack);

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);

void	ft_free_error(t_stack **stack);
void	ft_free_stack(t_stack **stack);

char	**ft_push_swap_split(char *s, char c);
void	ft_cost_cal(t_stack *stack_a, t_stack *stack_b);

#endif