/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:41:29 by tholzheu          #+#    #+#             */
/*   Updated: 2018/09/18 19:25:05 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	i = 0;
	a = (unsigned char)c;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (n > 0)
	{
		p1[i] = *p2;
		if (*p2 == a)
			return (&dst[i + 1]);
		i++;
		p2++;
		n--;
	}
	return (NULL);
}
