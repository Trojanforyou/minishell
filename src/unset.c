/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:47:58 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/24 16:05:55 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    delete_var(char **argv, t_env **list)
{
    t_env   *curr;
    t_env   *prev;
    int     i;

    i = 0;
    prev = NULL;
    while (argv[i])
    {
        curr = *list;
        while (curr)
        {
            if (ft_strcmp(curr->key, argv[i]) == 0)
            {
                if (curr == *list)
                    (*list) = curr->next;
                else
                   prev->next = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }
        i++;
    }
    // TODO Add free's
}

void    ft_unset(char **argv, t_env **list)
{
    if (*argv && ft_strncmp(argv[0], "unset", 7) == 0)
    {
        if (!argv[1])
            write (2, "unset: not enough arguments\n", 29);
        else
            delete_var(argv, list);
    }
}
