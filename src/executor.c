/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:55:53 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/24 21:36:44 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	child_process(char **argv, char **env)
{

}
static char	*find_path(char **env)
{
	char *path;

	path = 0;
	while (*env++)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
		{
			path = ft_strdup(*env + 5);
			if (!path)
				return (NULL);
			return (path);
		}
	}
	return (NULL);
}
static char *get_command(char **env, char *cmd)
{
	char	*path;
	char	**sp_path;
	char	*final;
	char	*val;
	int		i;

	path = find_path(env);
	sp_path = ft_split(path, ":");
	val = 0;
	i = 0;
	final = 0;
	while (*sp_path)
	{
		val = ft_strjoin(*sp_path, "/");
		final = ft_strjoin(val, cmd);
		if (!access(final, F_OK))
			return (final);
		i++;
	}
}








































			dub = ft_strdup(*env + 5);
			spl = ft_split(dub, ":");
			while (*spl)
			{
				val = ft_strjoin(*spl, "/");
				final = ft_strjoin(val, cmd);
				if (access(final, F_OK))
					return (final);
				else
					*spl++;
			}
			free(spl);
			free(final);
			free(dub);
