/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:39:57 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/21 16:52:02 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	ft_putnbr_printf(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr_printf("-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_printf('-', count);
	}
	if (nb)
	{
		if (nb >= 10)
			ft_putnbr_printf(nb / 10, count);
		ft_putchar_printf(nb % 10 + '0', count);
	}
}
