/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:53:00 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/14 15:47:00 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_arr(t_env	**list)
{
	char	*tmp_key;
	char	*tmp_val;
	char 	*arr;
	while ((*list)->next)
	{
		tmp_key = ft_strjoin((*list)->key, "=");
		tmp_val = ft_strjoin(tmp_key, (*list)->value);
	}
}

char	bubble_sort(char	**list)
{
	int	i;

	i = get_len(list);
	if (i)
	{

	}
}
void	ft_export(char **argv, char **env, char **lst)
{
	if (ft_strncmp(argv[1], "export", 7) == 0)
	{

	}
}
