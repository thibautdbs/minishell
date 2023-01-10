/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:32:38 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 13:25:17 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> // size_t
# include <sys/types.h> // ssize_t

// #############################################################################
// ## Types                                                                    #
// #############################################################################

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_success
{
	FAILURE,
	SUCCESS
}	t_success;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_strlst
{
	char			*content;
	struct s_strlst	*next;
}	t_strlst;

typedef struct s_buf
{
	void	*buf;
	size_t	nmemb;
	size_t	size;
}	t_buf;

// #############################################################################
// ## Memory                                                                   #
// #############################################################################

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memdup(void const *buf, size_t size);
void	ft_memdel(void *ptrptr);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// #############################################################################
// ## Strings                                                                  #
// #############################################################################

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_strlfilter(char const *src, char *dst, char const *filter, int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	ft_tochar(int digit);

int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strspn(char const *str, char const *accept);
size_t	ft_strcspn(char const *str, char const *reject);
size_t	ft_strllen(char const *str, size_t size);
char	*ft_strtok(char	*str, char const *sep);
char	*ft_strtok_r(char *str, char const *sep, char **saveptr);

int		ft_atoi(const char *nptr);
t_bool	ft_isint(char const *nptr);

char	*ft_strdup(const char *s);
char	*ft_strndup(char const *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_sep(char const *s1, char const *s2, char const *sep);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_strsdel(char ***strs);

char	*ft_search_str(char const *str, char **strs, size_t size);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

t_bool	ft_strendswith(char const *str, char const *end);

// #############################################################################
// ## IO                                                                       #
// #############################################################################

char	*ft_gnl(int fd);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr_rpt_fd(char const *str, int n, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_puterr(char const *str);
void	ft_puterr_endl(char const *str);

// #############################################################################
// ## Linked lists                                                             #
// #############################################################################

t_list	*ft_lstnew(void *content);
t_list	*ft_lstnew_int(int n);
t_list	*ft_lstpush(void const *arr, size_t nmemb, size_t size);
t_list	*ft_lstload(void *arr, size_t nmemb);
void	*ft_lstflat(t_list *lst, size_t size);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstpop(t_list **lst, int n);

void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstat(t_list *lst, int n);
ssize_t	ft_lstindex(t_list *lst, void *content, size_t size);
t_bool	ft_lstuniq(t_list *lst, size_t size);

void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_lstget_int(t_list *node);

t_list	*ft_lstreadlines(int fd);

// #############################################################################
// ## Arrays                                                                   #
// #############################################################################

ssize_t	ft_indexof(void const *arr, void const *ref, size_t nmemb, size_t size);

void	*ft_mtrx2_new(size_t nmemb_out, size_t nmemb_in, size_t size);
void	ft_mtrx2_del(void *mtrx2, size_t nmemb);

// #############################################################################
// ## Maps                                                                     #
// #############################################################################

void	*ft_atoidup(void *nptr);

// #############################################################################
// ## Maths                                                                    #
// #############################################################################

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_min_arr(int const *nbrs, size_t size);
t_bool	ft_isneg(int n);
int		ft_abs(int n);
int		ft_count_digits(int n);
int		ft_mod(int n, int mod);

#endif // LIBFT_H
