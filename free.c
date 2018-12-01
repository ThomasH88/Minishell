/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:58:03 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 16:21:43 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		arrdel_str(char **arr, char **words_to_free)
{
	if (arr == NULL)
		return (1);
	while (words_to_free && *words_to_free)
	{
		ft_strdel(words_to_free);
		words_to_free++;
	}
	free(arr);
	arr = NULL;
	return (1);
}
