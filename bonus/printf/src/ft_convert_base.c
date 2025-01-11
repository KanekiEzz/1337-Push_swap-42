/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:17:55 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 15:20:02 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_convert_base(unsigned int nbr, unsigned int base,
		const char *base_str, int *count)
{
	if (nbr >= base)
		ft_convert_base(nbr / base, base, base_str, count);
	ft_putchar(base_str[nbr % base], count);
}
