/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <jmaydew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 17:29:44 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 15:08:26 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** SUBJECT BONUS
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del) (void *));
void			ft_lstclear(t_list **lst, void (*del) (void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

/*
** EXTRA BONUS
*/
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strcpy(char *dest, const char *src);
int				ft_strfind(const char **array, const char *str);
void			ft_putstrarr(char **arr);
void			ft_free_strnarr(char **arr, int arr_size);
void			ft_free_strarr(char ***strarr);
void			ft_list_remove_if(t_list **begin_list, void *data_ref,
	void (*free_fct)(void *));
int				ft_isblank(int c);
t_list			*ft_lstfind(t_list *begin, void *content);
int				ft_isnumber(char *s);
int				ft_atoi_overflow(const char *str, int *overflow);
void			ft_putintarr(int *arr, int len);
int				*ft_intarr_dup(int *arr, int len);
int				ft_intarr_min(int *arr, int len);
void			ft_swap_int(int *arr, int i1, int i2);
int				ft_isintarr_sort(int *arr, int len);
#endif
