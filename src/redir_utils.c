/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:45:13 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/10 21:54:01 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int  execute_trunc(t_redir *self)
{
    self->fd = open(self->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (self->fd == -1)
        return (perror("open"), -1);
    dup2(self->fd, STDOUT_FILENO);
    close(self->fd);
    return (0);
}
static int  execute_append(t_redir *self)
{
	self->fd = open(self->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (self->fd == -1)
        return (perror("open"), -1);
    dup2(self->fd, STDOUT_FILENO);
    close(self->fd);
    return (0);
}
static int  execute_input(t_redir *self)
{
    self->fd = open(self->filename, O_RDONLY, 0644);
    if (self->fd == -1)
        return (perror("open"), -1);
    dup2(self->fd, STDIN_FILENO);
    close(self->fd);
    return (0);
}
t_redir	*create_redirect(int type, char *filename)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	new->fd = -1;
	new->type = type;
	new->filename = filename;
	if (type == RE_TRUNC)
	    new->execute = execute_trunc;
	else if (type == RE_APPEND)
		new->execute = execute_append;
	else if (type == RE_INPUT)
		new->execute = execute_input;
	return (new);
}