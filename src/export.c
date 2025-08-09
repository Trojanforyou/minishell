/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:53:00 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/09 22:45:51 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * This is modified strcmp but for the "export" fucnction. The only difference is:
 * It Compares two strings up to '=' character or end of string
 */
int	env_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 &&  (*s1 == *s2) && *s1 != '=' && *s2 != '=')
	{
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

/**
 * Initializes environment variables linked list from env array
 * Parses each KEY=VALUE format string and adds to list as exported variable
 * "list" pointer to pointer of environment variables list head
 * "env" array of environment variable strings
 */
void	env_init(t_env **list, char **env)
{
	int		i;
	char	**arg;

	i = 0;
	while (env[i])
	{
		arg = ft_split(env[i], '=');
		add_in_list(list, arg[0], arg[1], 1);
		i++;
		// TODO Add free's
	}
}
/**
 * Converts environment variables linked list to KEY=VALUE format string array
 * Includes only exported variables if(exported == 1)
 * "list" pointer to pointer of environment variables list head
 */
char	**env_to_arr(t_env	**list)
{
	char	*tmp_key;
	char	*tmp_val;
	char	**arr;
	t_env	*curr;
	int	i;

	i = 0;
	curr = *list;
	arr = malloc(sizeof(char *) * (get_env_len(list) + 1));
	while (curr)
	{
		if (curr->exported == 1)
		{
			tmp_key = ft_strjoin(curr->key, "=");
			if (curr->value) 
				tmp_val = ft_strjoin(tmp_key, curr->value);
			else
				tmp_val = ft_strdup(tmp_key);
			arr[i++] = tmp_val;
		}
		curr = curr->next;
		// TODO Add free's
	}
	arr[i] = NULL;
	return (arr);
}

/**
 * Just an implementaion of Bubble sort alghoritm 
 * Used for sorting environment variables "alphabeticaly" when displaying export without arguments
 * "arr" string array to sort
 */
char	**bubble_sort(char	**arr)
{
	int	i;
	int	j;
	int	len;
	char *tmp;

	i = 0;
	len = 0;
	while (arr[len])
		len++;
	while (len - i - 1)
	{
		j = 0;
		while (len - j - 1)
		{
			if (env_strcmp(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
/**
 * Implementation of export command
 * Without arguments, displays all exported variables in sorted order
 * With arguments, adds new variables to list as exported.
 * "argv" command arguments array
 * "list" pointer to pointer of environment variables list head
 */
// Currently has the "duplication" issue. Which i'm gonna fix 
int	ft_export(char **argv, t_env **list)
{
	int i;
	int	j;
	char **arr;
	char **arg;

	i = 0;
	j = 0;
	if (argv[1] && ft_isalnum(argv[1][0]))
	{
		while (argv[++j])
		{
			arg = ft_split(argv[j], '=');
			add_in_list(list, arg[0], arg[1], 1);
		}
	}
	else if (argv[0] && !argv[1])
	{
		arr = env_to_arr(list);
		argv = bubble_sort(arr);
		while (argv[i])
			printf("declare -x %s\n", argv[i++]);
			// TODO Fix the duplication
	}
	return (1);
}
