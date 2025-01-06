/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:20:54 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 20:45:25 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_not_sorted(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		if (curr->next != NULL)
			if (curr->value > curr->next->value)
				return (1);
		curr = curr->next;
	}
	return (0);
}

t_stack	*ft_lstnew(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

t_stack	*create_stack(char **numbers)
{
	t_stack	*new_stack;
	int		i;
	long	check_number;

	i = 0;
	new_stack = NULL;
	while (numbers[i] != NULL)
	{
		check_number = ft_atol(numbers[i]);
		ft_lstadd_back(&new_stack, ft_lstnew((int)check_number, 0));
		i++;
	}
	free_string(numbers);
	return (new_stack);
}