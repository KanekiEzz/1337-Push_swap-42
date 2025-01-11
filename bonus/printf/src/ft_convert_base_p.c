/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:17:55 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/05 15:06:38 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_convert_base_p(unsigned long long nbr, unsigned int base,
		const char *base_str, int *count)
{
	if (nbr >= base)
		ft_convert_base_p(nbr / base, base, base_str, count);
	ft_putchar(base_str[nbr % base], count);
}
