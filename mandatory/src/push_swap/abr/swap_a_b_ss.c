/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:09:28 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 11:41:56 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, false);
	sb(b, false);
	ft_printf("ss\n");
}
