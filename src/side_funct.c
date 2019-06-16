/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:01:30 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:15:38 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_strchr_first_wd(char *cmd, int c)
{
	while (cmd && *cmd && ft_isprint(*cmd))
	{
		if (*cmd == c)
			return (1);
		cmd++;
	}
	return (0);
}

char		*remove_quotes(char *s)
{
	char	*new;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	MALLOCHECK(new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1));
	while (s[j])
	{
		if (s[j] != 34 && s[j] != 39)
			new[i++] = s[j];
		j++;
	}
	new[i] = '\0';
	return (new);
}

void		trim_cmds(char **arr)
{
	char	*tmp;

	if (arr == NULL || *arr == NULL)
		return ;
	while (*arr)
	{
		if (str_is_print(*arr) == 0)
			ft_strdel(arr);
		else
		{
			tmp = ft_strtrim(*arr);
			ft_strdel(arr);
			*arr = tmp;
		}
		arr++;
	}
}

char		**normalize_cmds(void)
{
	char			*line;
	char			**arr;
	char			*tmp;

	get_next_line(0, &line);
	tmp = ft_strtrim(line);
	ft_strdel(&line);
	arr = ft_strsplit(tmp, ';');
	ft_strdel(&tmp);
	trim_cmds(arr);
	return (arr);
}

void		handle_expansions(char **cmds, char **env)
{
	char	*home;
	char	*var;
	int		i;

	if (cmds == NULL)
		return ;
	i = 0;
	while (cmds[i])
	{
		if (ft_strcmp(cmds[i], "~") == 0 &&
			(home = get_env_var("HOME", env)) && ft_strdel(&cmds[i]))
			cmds[i] = home;
		else if (ft_strncmp(cmds[i], "~", 1) == 0 &&
				(home = get_env_var("HOME", env)))
		{
			var = cmds[i];
			cmds[i] = strsub_replace(cmds[i], "~", home);
			ft_strdel(&var);
			ft_strdel(&home);
		}
		else if (cmds[i][0] == '$' && ft_isprint(cmds[i][1]) &&
		(var = get_env_var(&cmds[i][1], env)) && ft_strdel(&cmds[i]))
			cmds[i] = var;
		i++;
	}
}
