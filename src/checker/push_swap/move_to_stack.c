/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:04:11 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 19:44:46 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static	void	handle_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
		sa(stack_a, false);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five(stack_a, stack_b);
	free_stack(stack_a);
	return ;
}

void	move_to_b(t_stack **a, t_stack **b, int x, int i)
{
	int	stack_size;

	stack_size = ft_lstsize(*a);
	if (stack_size <= 5)
		handle_small_stack(a, b);
	else if (stack_size <= 100)
		x = 16;
	else
		x = 36;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(b, a);
			i++;
		}
		else if ((*a)->index <= i + x)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	move_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	max_node_position;

	stack_size = ft_lstsize(*stack_b);
	while (stack_size)
	{
		set_position(*stack_b);
		max_node_position = max_node_positon(*stack_b);
		if (max_node_position < stack_size / 2)
		{
			while ((*stack_b)->position_in_stack != max_node_position)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->position_in_stack != max_node_position)
				rrb(stack_b, false);
		}
		pa(stack_a, stack_b);
		stack_size--;
	}
}
