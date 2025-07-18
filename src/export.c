/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:53:00 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/18 18:28:09 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 &&  (*s1 == *s2) && *s1 != '=' && *s2 != '=')
	{
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

void	env_init(t_env **list, char **env)
{
	int	i;
	char	**arg;

	i = 0;
	while (env[i])
	{
		arg = ft_split(env[i], '=');
		add_in_list(list, arg[0], arg[1], 1);
		// free(arg);
		i++;
		// TODO Add free's
	}
}
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
			if (curr->value) // Проверяется чуществует ли значение у переменной. Если есть "HELLO=World"
				tmp_val = ft_strjoin(tmp_key, curr->value); // Идет обьеденение "HELLO=" "World"
			else // Если значение 0
				tmp_val = ft_strdup(tmp_key); // Просто копируется "HELLO=" без значение
			arr[i++] = tmp_val; // Добавляет полученную строку в масив который потом вернет env_to_arr
		}
		curr = curr->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	**bubble_sort(char	**arr)
{
	int	i;
	int	j;
	int	len = 0;
	char *tmp;

	i = 0;
	while (arr[len])
		len++;
	while (len - i - 1)
	{
		j = 0;
		while (len - j - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
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
void	ft_export(char **argv, t_env **list)
{
	int i;
	int	j;
	char **arr;
	char **arg;

	i = 0;
	j = 0;
	if (*argv && ft_strncmp(argv[0], "export", 7) == 0)
	{
		if (argv[0] && argv[1] && isalnum(argv[1]))
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
		}
	}
}
