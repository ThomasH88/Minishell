/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:35:26 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/08 19:59:43 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*p1;
	char	*p2;

	p1 = (char *)dst;
	p2 = (char *)src;
	i = 0;
	while (n > 0)
	{
		p1[i] = *p2;
		n--;
		i++;
		p2++;
	}
	return (dst);
}
