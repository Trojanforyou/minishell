/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:42:44 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/20 18:02:27 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define MAX_PID 4194304
# define MIN_PID 1

# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memmove(void *dest, const void *scr, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_striteri(char *str, void (*f) (unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

int		ft_atoi(const char *nptr);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_print_p(void *ptr);
int		ft_print_s(const char *s);
int		ft_print_x(unsigned int num, char typef);
int		ft_printf(const char *str, ...);
int		ft_put_u(unsigned int n);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_lstsize(t_list *lst);

char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *toFind, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*fr_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);

size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
#endif
