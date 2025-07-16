/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:53:00 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/16 17:55:42 by msokolov         ###   ########.fr       */
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
	t_env	*new; // Переменная нужна для создания нового элемента списка
	t_env	*last = 0;
	char	**arg;

	i = 0;
	while (env[i])
	{
		arg = ft_split(env[i], '='); // разбиваю env на до = после =
		new = malloc(sizeof(t_env)); // выделяю память для нее что бы этот элемент жил вне цикла и был доступен через указатель в списке
		new->key = (arg[0]); // аргумент до = это кеу
		new->value = (arg[1]); // аргумент после =
		new->exported = 1; // флаг для експорта
		new->next = NULL;
		if (!*list) // если список пустой
			*list = new ; // то тогда new первый элемент списка
		else // если там уже что то есть 
			last->next = new; // след элемент который идет после последнего это новый
		last = new; // Новый элемент становится последним
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
			tmp_val = ft_strjoin(tmp_key, curr->value);
			arr[i++] = tmp_val;
			// free(tmp_key);
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
	int i = 0;
	char **arr;
	char **tmp;
	if (*argv && ft_strncmp(argv[0], "export", 7) == 0)
	{
		arr = env_to_arr(list);
		tmp = bubble_sort(arr);
		if (argv[0] && !argv[1])
		while (tmp[i])
			printf("declare -x %s\n", tmp[i++]);
		
	}
}
