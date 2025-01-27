/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppagola- <ppagola-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:23:42 by ppagola-          #+#    #+#             */
/*   Updated: 2025/01/13 20:04:27 by ppagola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

size_t		ft_n_words(char **words);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strselfjoin(char *self, const char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
void		ft_free_split(char **result);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strclean(char *str, char c);
char		*ft_strreplace(char *str, char *old, char *new);

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);

int			ft_atoi(const char *str);
char		*ft_itoa(int n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_printf(const char *format, ...);
int			ft_printf2(const char *format, ...);

char		*ft_sprintf(const char *format, ...);
char		*ft_sprintf_main(const char *format, va_list args);
char		*ft_strselfjoin_sp(char *self, const char *s2);
char		*ft_special_sprintf(const char *format, va_list args, int *i);
char		*ft_compute_sp(char type, char *flags, va_list args);
int			ft_digits_sp(unsigned long long num, unsigned long long base);
char		*ft_ltoa_sp(long long num);
char		*ft_otoa_sp(unsigned long long num);
char		*ft_xtoa_sp(unsigned long long num, int upper);
char		*ft_ctoa_sp(int i);
char		*ft_stoa_sp(char *str);
char		*ft_ptoa_sp(void *address);

char		*ft_strdup_gnl(const char *s);
char		*ft_strndup_gnl(const char *s, size_t n);
char		*ft_strcpy_gnl(char *dest, const char *src);
char		*ft_strcat_gnl(char *dest, const char *src);
void		ft_free_pile(char **pile);
char		*get_next_line(int fd);
char		*ft_read_file(char *path_name);
void		ft_set_clean_gnl(void);

void		*ft_malloc(size_t size);
void		ft_free(void *ptr);
void		ft_free_all_malloc(void);

int			ft_open(char *filename, int mode);
void		ft_close_all(void);
void		ft_clean(void);
void		ft_exit(int i);

#endif
