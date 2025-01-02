/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:08:53 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/02 23:06:15 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_movement(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(b, a);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(a, b);
	else
		(ft_printf("Error\n"), exit(1));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		(ft_printf("\033[0;31mError\n\033[0m"), exit(EXIT_FAILURE));
	stack_a = valid_parse(ac, av);
	line = get_next_line(0);
	while (line)
	{
		do_movement(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (stack_not_sorted(&stack_a))
		ft_printf("\033[0;31mKO\n\033[0m");
	else
		ft_printf("\033[0;31mOK\n\033[0m");
	free_stack(&stack_a);
	return (0);
}
