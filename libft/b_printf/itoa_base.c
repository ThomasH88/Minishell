/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:55:36 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/21 16:51:38 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	itoa_base_printf(unsigned long nb, unsigned long base, int *count)
{
	if (nb >= base)
		itoa_base_printf(nb / base, base, count);
	if ((nb % base) >= 10 && (nb % base) <= 15)
		ft_putchar_printf(nb % base + 87, count);
	else
		ft_putchar_printf(nb % base + '0', count);
}
