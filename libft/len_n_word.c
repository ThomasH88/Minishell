/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_n_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:38:07 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/10 15:39:17 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len_n_word(char const *s, char c, int n)
{
	int		count;
	int		wn;

	wn = 0;
	count = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c && ++count)
		{
			s++;
			if (*s == '\0' || *s == c)
				wn++;
		}
		if (wn == n)
			return (count);
		count = 0;
	}
	return (0);
}
