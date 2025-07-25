/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:33:08 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/25 17:41:26 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	t_env	*list = NULL;
	t_redir *link = NULL;
	env_init(&list, env);
	line_reader(argc, argv, env, &list, link);
	
}
/**
 *  TODO: make the function, which is gonna check if there's any redirections or not
 * Fix the output of redirection
 * Add error checks for the function that exist
 * Add free's
 */
