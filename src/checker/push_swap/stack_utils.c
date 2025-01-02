/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:17:26 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 19:44:40 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_stack	*lst_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_lstsize(t_stack *head)
{
	int	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	if (!stack || !new)
		return ;
	while (tmp)
	{
		if (tmp->value > new->value)
			tmp->index++;
		else
			new->index++;
		tmp = tmp->next;
	}
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = lst_last(*stack);
	last->next = new;
}

void	set_position(t_stack *stack)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = stack;
	while (curr)
	{
		curr->position_in_stack = i;
		i++;
		curr = curr->next;
	}
}

int	max_node_positon(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position_in_stack);
}
