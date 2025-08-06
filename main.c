/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:33:08 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/07 00:33:06 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_env	*list = NULL;
	t_redir *link = NULL;
	(void)argc;
	env_init(&list, env);
	line_reader(argv, env, &list, link);
	
}
