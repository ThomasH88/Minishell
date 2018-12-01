/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:28:11 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/27 16:51:48 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		save_words_in_arr(char const *s, char **arr, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			arr[i][j] = *s;
			s++;
			j++;
		}
		i++;
		j = 0;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		wc;
	int		len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	arr[wc] = NULL;
	while (i < wc)
	{
		len = len_n_word(s, c, i + 1);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (0);
		arr[i++][len] = '\0';
	}
	save_words_in_arr(s, arr, c);
	return (arr);
}
