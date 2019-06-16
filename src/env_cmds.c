/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:48:56 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:10:28 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_env(char *cmd, char **env)
{
	char	**arr;

	arr = ft_strsplit(cmd, ' ');
	handle_expansions(arr, env);
	if (ft_strcmp(cmd, "env") != 0)
	{
		b_printf("usage: env [no arguments]\n");
		arrdel_str(arr, arr);
		return (1);
	}
	while (env && *env)
	{
		b_printf("%s\n", *env);
		env++;
	}
	arrdel_str(arr, arr);
	return (1);
}

int		cmd_setenv(char *cmd, char **env)
{
	char	**arr;
	char	*var_name;
	char	*var_value;

	arr = ft_strsplit(cmd, ' ');
	handle_expansions(arr, env);
	if (arr[1] == NULL && arrdel_str(arr, arr))
		return (cmd_env("env", env));
	if (arr[2] != NULL && arr[3] != NULL && arrdel_str(arr, arr))
	{
		b_printf("setenv: Too many arguments\n");
		b_printf("usage: setenv [variable name] [value]\n");
		return (1);
	}
	var_name = str_toupper(arr[1]);
	var_value = ft_strdup(arr[2]);
	change_env(var_name, var_value, env);
	ft_strdel(&var_name);
	arrdel_str(arr, arr);
	return (1);
}

int		cmd_unsetenv(char *cmd, char **env)
{
	char	**arr;
	char	*var;
	char	*tmp;
	int		i;

	arr = ft_strsplit(cmd, ' ');
	handle_expansions(arr, env);
	if (arr[1] == NULL && arrdel_str(arr, arr))
		return (b_printf("unsetenv: Too few arguments\n"));
	i = 0;
	while (arr && arr[++i])
	{
		tmp = str_toupper(arr[i]);
		if ((var = get_env_var(tmp, env)) && ft_strdel(&var))
			remove_env_var(tmp, env);
		ft_strdel(&tmp);
	}
	arrdel_str(arr, arr);
	return (1);
}

int		env_cmds(char *cmd, char **env)
{
	if (ft_strncmp(cmd, "env", 3) == 0 && !ft_isprint(cmd[3]))
		return (cmd_env(cmd, env));
	if (ft_strncmp(cmd, "setenv", 6) == 0 && !ft_isprint(cmd[6]))
		return (cmd_setenv(cmd, env));
	if (ft_strncmp(cmd, "unsetenv", 8) == 0 && !ft_isprint(cmd[8]))
		return (cmd_unsetenv(cmd, env));
	return (0);
}
