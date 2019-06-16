/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:56:38 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:40:26 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			cmd_clear(char *cmd)
{
	ft_strdel(&cmd);
	b_printf("\e[1;1H\e[2J");
	return (1);
}

int			cmd_echo(char *cmd, char *lc_cmd, char **env)
{
	char	**arr;
	char	*tmp;
	int		i;

	(void)env;
	tmp = remove_quotes(cmd);
	ft_strdel(&lc_cmd);
	arr = ft_strsplit(tmp, ' ');
	handle_expansions(arr, env);
	i = 0;
	ft_strdel(&tmp);
	while (arr[++i])
	{
		b_printf("%s", arr[i]);
		ft_strdel(&arr[i]);
		if (arr[i + 1] != NULL)
			b_printf(" ");
	}
	b_printf("\n");
	ft_strdel(&arr[0]);
	arrdel_str(arr, NULL);
	return (1);
}

int			cmd_cd(char *cmd, char *lc_cmd, char **env)
{
	char	**arr;
	char	*home;
	char	*opwd;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	ft_strdel(&lc_cmd);
	if (ft_strncmp(cmd, "cd", 2) != 0)
		return (1);
	arr = ft_strsplit(cmd, ' ');
	handle_expansions(arr, env);
	if (arr[1] && arr[2] && b_printf("usage: cd [target_directory]\n"))
		return (1);
	if ((arr[1] == NULL || ft_strcmp(arr[1], "~") == 0)
		&& (home = get_env_var("HOME", env)))
		cd_absolute_path(home, env);
	else if (ft_strcmp(arr[1], "-") == 0 && (opwd = get_env_var("OLDPWD", env)))
		cd_absolute_path(opwd, env);
	else if (arr[1][0] == '/')
		cd_absolute_path(ft_strdup(arr[1]), env);
	else
		cd_relative_path(ft_strdup(arr[1]), env);
	arrdel_str(arr, arr);
	change_env("OLDPWD", tmp, env);
	return (1);
}

int			cmd_exit(char *cmd)
{
	char	**arr;

	arr = ft_strsplit(cmd, ' ');
	if (arr[1] != NULL && arr[2] != NULL)
	{
		arrdel_str(arr, arr);
		b_printf("exit: too many arguments\n");
		return (1);
	}
	arrdel_str(arr, arr);
	return (0);
}
