/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:45:36 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/26 23:33:47 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Checks and processes the -n flag for echo command
 * Supports multiple -n flags like (-n, -nn, -nnn)
 * Returns 1 if at least one valid -n flag found
 * "argv" command arguments array
 * "i" pointer to index that will be updated to first non-flag argument
 */
int	n_case(char **argv, int *i)
{
	int j;

	*i = 1;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == 'n')
	{
		j = 2;
		while (argv[*i][j] == 'n')
			j++;
		if (argv[*i][j] != '\0')
			break ;
		(*i)++;
	}
	return (*i > 1);
}
int	arg_counter(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}


/**
 * TEMPORARY: Main interactive shell loop for reading and processing user commands.
 *
 * 	Core functionality:
 * - Uses readline() to get user input with prompt "➜"
 * - Maintains command history "add_history"
 * - Processes commands in infinite loop until "eof"
 *
 * Current parsing limitations:
 * - Currently uses tokens() function which handles basic quote parsing, but thats it
 * - Does not handle: pipes (|), single quotes, complex redirections, command chaining,
 * 	 variable expansion ($HOME, $USER)
 *
 * TODO: Replace with proper parser
 * For now, only tests individual built-in commands.
 *
 * "argv" command line arguments (gets overwritten by tokens())
 * "env" environment variables array
 * "list" pointer to environment variables linked list
 * "link" pointer to redirection handling structure (currently broken)
 */

void	line_reader(char **argv, char **env, t_env **list, t_redir *link)
{
	char	*line;
	int		saved;
	while ((line = readline("➜ ")) != NULL)
	{
		saved = dup(STDOUT_FILENO);
		if (*line)
		add_history(line);
		argv = tokens(line);
		build_red(&link, argv);
		ft_echo(argv);
		ft_pwd(argv);
		ft_cd(argv);
		ft_env(argv, env);
		cool_exit(argv);
		ft_export(argv, list);
		ft_unset(argv, list);
		dup2(saved, STDOUT_FILENO);
		close(saved);
	}
	free(argv);
	free(line);
}

/**
 * Handles the exit command with argument validation
 * Checks numeric arguments correctness and parameter count
 * Prints appropriate errors and exits program with correct exit code
 * "argv" command arguments array
 */
void	cool_exit(char **argv)
{
	int arg;
	if (*argv && ft_strncmp(argv[0], "exit", 5) == 0)
	{
		if (!argv[1])
			exit(0);
		arg = ft_atoi(argv[1]);
		if ((*argv[1] < 48 || *argv[1] > 58) && *argv[1] != '-')
		{
			write(2, "exit: numeric argument required\n", 33);
			exit (255);
		}
		if (argv[1] && argv[2])
			write(2, "exit: too many arguments\n", 26);
		else if ((arg >= 255 || arg <= 0 || arg > 0) && ft_strlen(argv[1]) < 19)
			exit((unsigned char)ft_atoi(argv[1]));
		else if (ft_strlen(argv[1]) > 19) // TODO Change strlen function with atoll
		{
			write (2, "exit: numeric argument required\n", 33);
			exit((unsigned char)ft_atoi(argv[1]));
		}
	}
}
/**
 * Counts the number of elements in environment variables linked list
 * "list" pointer to the head of environment variables linked list
 */
int	get_env_len(t_env **list)
{
	int	i;
	t_env	*curr;

	i = 0;
	curr = *list;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
/**
 * Adds a new environment variable to the end of the linked list
 * "list" pointer to pointer of environment variables list head
 * "key" variable name
 * "value" variable value
 * "exported flag" indicating if variable is exported (1 - yes, 0 - no)
 */
void	 add_in_list(t_env **list, char *key, char *value, int exported)
{
	t_env	*new;
	t_env	*last;

	last = 0;
	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = key;
	new->value = value;
	new->exported = exported;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}


