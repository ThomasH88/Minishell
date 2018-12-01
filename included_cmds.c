/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   included_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:29:18 by tholzheu          #+#    #+#             */
/*   Updated: 2018/10/29 19:11:42 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				nopath_cmds(char *cmd, char **env)
{
	pid_t	pid;
	char	**params;

	params = ft_strsplit(cmd, ' ');
	handle_expansions(params, env);
	if (check_access(params[0]) == -1)
		b_printf("minishell: command not found: %s\n", cmd);
	else if (check_access(params[0]) == -2)
		b_printf("minishell: permission denied: %s\n", cmd);
	if ((pid = fork()) == -1)
		b_printf("Error occured while doing the fork\n");
	else if (pid == 0)
	{
		execve(params[0], params, NULL);
		exit(1);
	}
	else
		wait(NULL);
	arrdel_str(params, params);
	return (1);
}

static int		execute_path_cmd(char **params, char **env)
{
	pid_t	pid;

	if (check_access(params[0]) < 0)
		return (0);
	if ((pid = fork()) == -1)
		b_printf("Error occured while doing the fork\n");
	else if (pid == 0)
	{
		execve(params[0], params, env);
		exit(1);
	}
	else
		wait(NULL);
	arrdel_str(params, params);
	return (1);
}

int				path_cmds(char *cmd, char **env)
{
	char	**path;
	char	**params;
	char	*p_tmp;
	int		i;

	i = 0;
	path = get_path_var(env);
	params = ft_strsplit(cmd, ' ');
	handle_expansions(params, env);
	p_tmp = params[0];
	while (path && path[i])
	{
		params[0] = ft_strjoin(path[i], params[0]);
		if (execute_path_cmd(params, env) &&
			arrdel_str(path, path) && ft_strdel(&p_tmp))
			return (0);
		ft_strdel(&params[0]);
		params[0] = p_tmp;
		i++;
	}
	arrdel_str(params, params);
	arrdel_str(path, path);
	return (1);
}
