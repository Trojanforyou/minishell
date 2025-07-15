/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:53:00 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/15 19:25:20 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_init(t_env **list, char **env)
{
	int	i;
	t_env	*new; // Переменная нужна для создания нового элемента списка
	t_env	**last = NULL;
	char	*arg;

	i = 0;
	while (env[i])
	{
		arg = ft_split(env[i], "="); // разбиваю env на до = после =
		new = malloc(sizeof(t_env)); // выделяю память для нее что бы этот элемент жил вне цикла и был доступен через указатель в списке
		new->key = arg[0]; // аргумент до = это кеу
		new->value = arg[1]; // аргумент после =
		new->exported = 1; // флаг для експорта
		new->next = NULL;
		if (!*list )
			last = new ;
		else
			new->next = new;
		last = new;
		free(arg);
		i++;
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
			tmp_val = ft_strjoin(tmp_key, curr->value);
			arr[i++] = tmp_val;
			// free(tmp_key);
		}
		curr = curr->next;
	}
	arr[i] = NULL;
	return (arr);
}

// char	bubble_sort(char	**list)
// {
// 	int	i;

// 	i = get_len(list);
// 	if (i)
// 	{

// 	}
// }
void	ft_export(char **argv, t_env **list)
{
	int i = 0;
	char **arr;
	if (argv[1] && ft_strncmp(argv[0], "export", 7) == 0)
	{
		arr = env_to_arr(list);
		while (arr[i])
			printf("%s", arr[i]);
	}
}
