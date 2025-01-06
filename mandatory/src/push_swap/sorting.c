/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:12:07 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/01 17:57:11 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		ra(a);
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	if (stack_not_sorted(a))
	{
		min_node = get_min(*a);
		while ((*a)->value != min_node->value)
			ra(a);
		pb(b, a);
		sort_three(a);
		pa(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	if (stack_not_sorted(a))
	{
		min_node = get_min(*a);
		while ((*a)->value != min_node->value)
			ra(a);
		pb(b, a);
		sort_four(a, b);
		pa(a, b);
	}
}
