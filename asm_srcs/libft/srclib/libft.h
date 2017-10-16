/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:44:40 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/25 12:12:53 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include "../printf/printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_free(char *param);
void				ft_free_strtab(char **tab);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strdup(char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strlf1join(char *s1, char *s2, int len1, int len2);
char				*ft_strlf2join(char *s1, char *s2, int len1, int len2);
char				*ft_strrchr(const char *s, int c);
char				*ft_itoa(long long int nb);
char				*ft_itoa_base(unsigned long long int n, int base);
char				*ft_itoa_base_maj(unsigned long long int n, int base);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_cjoin(char *str, char c);
char				*ft_cljoin(char *str, char c, int len);
char				*ft_cmjoin(char *str, char c, int len);
char				*ft_strjoin(char const *s1, char const *s2, int fr);
char				*ft_strljoin(char *s1, char *s2, int len1, int len2);
char				*ft_strtrim(char const *s);
void				*ft_memjoin(void *s1, void *s2, int len1, int len2);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplitif(char const *s, int (*f)(char));
char				**ft_strsplitnbif(char const *s, int (*f)(char), int n);
char				**ft_strtab(char **tab, char *str);
int					ft_sqrt(int nb);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isstrdigit(char *str);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalnum(int c);
int					ft_isspace(char c);
int					ft_atoi(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_sort_params(int argc, char **argv);
int					get_next_line(const int fd, char **line);
int					*ft_range(int min, int max);
void				ft_putnbr(int n);
void				ft_putstr(char const *str);
void				ft_putchar(char c);
void				ft_strclr(char *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_foreach(int *tab, int length, void (*f)(int));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_back_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

#endif
