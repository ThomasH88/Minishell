/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:55:15 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/21 16:55:35 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar_printf(char c, int *count);
void	ft_putstr_printf(char *str, int *count);
void	ft_putnbr_printf(int nb, int *count);
void	itoa_base_printf(unsigned long nb, unsigned long base, int *count);
void	p_itoa_base(unsigned long nb, unsigned long base, int *count);
int		b_printf(const char *fmt, ...);

#endif
