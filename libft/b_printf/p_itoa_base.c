/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:58:44 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/21 16:47:05 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	p_itoa_base(unsigned long nb, unsigned long base, int *count)
{
	ft_putstr_printf("0x", count);
	itoa_base_printf(nb, base, count);
}
