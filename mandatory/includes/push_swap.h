/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:09:21 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/05 15:12:50 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position_in_stack;
	struct s_stack	*next;
}	t_stack;

//	printf
int			ft_printf(const char *format, ...);
void		ft_putchar(char c, int *count);
void		ft_putstr(char *str, int *count);
void		ft_putnbr(int n, int *count);
void		ft_convert_base(unsigned int nbr, unsigned int base,
				const char *base_str, int *count);
void		ft_convert_base_p(unsigned long long nbr, unsigned int base,
				const char *base_str, int *count);

// Stack utils
t_stack		*lst_last(t_stack *head);
int			ft_lstsize(t_stack *head);
void		ft_lstadd_back(t_stack **stack, t_stack *new);
int			max_node_positon(t_stack *stack);
void		set_position(t_stack *stack);

t_stack		*valid_parse(int ac, char **av);

// Push utils
int			stack_not_sorted(t_stack **stack);
t_stack		*get_max(t_stack *stack);
t_stack		*get_min(t_stack *stack);
t_stack		*ft_lstnew(int value, int index);
t_stack		*create_stack(char **numbers);

// error_handling
void		free_stack(t_stack **stack);
int			check_strg_emtghi(int ac, char **av);

// Move to push_swap
void		move_to_b(t_stack **a, t_stack **b, int x, int i);
void		move_back_to_a(t_stack **a, t_stack **b);

// Push a/b
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);

// Swap a/b/ss
void		sa(t_stack **a, bool print);
void		sb(t_stack **b, bool print);
void		ss(t_stack **a, t_stack **b);

// Sorting
void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);

// Reverse a/b/r
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

// Reverse rotate a/b/r
void		rra(t_stack **a, bool print);
void		rrb(t_stack **b, bool print);
void		rrr(t_stack **a, t_stack **b);

// Utilities
void		free_string(char **ptr);
int			valid_number(const char str);
long		ft_atol(const char *str);
void		ft_lsadd_new(t_stack **stack, int value);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, int n);

#endif
