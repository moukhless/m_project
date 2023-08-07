/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:20:07 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/31 11:38:46 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_list_str
{
	char				*content;
	int					fd;
	struct s_list_str	*next;
}				t_list_str;

enum e_token
{
	WORD = -1,
	SPECIAL_CHAR = 0,
	WHITE_SPACE = ' ',
	QOUTE = '\'',
	DOUBLE_QUOTE = '\"',
	ENV = '$',
	Q_MARK = '?',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	PIPE_LINE = '|',
	HERE_DOC,
	DREDIR_OUT,
};

enum e_state
{
	IN_DQUOTE,
	IN_QUOTE,
	GENERAL,
};

typedef struct s_env
{
	char			*key;
	char			*val;
	char			*content;
	char			c;
	char			plus;
	char			**env;
	char			*hide_path;
	struct s_env	*next;
}t_env;

typedef struct s_list
{
	char			*content;
	char			**cmd;
	int				len;
	int				type;
	int				type_d;
	enum e_state	state;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_var
{
	int		flag1;
	int		flag2;
	int		start;
	int		end;
	int		in_join;
	int		num_env;
	int		skip;
	int		q_dq;
	int		*fd;
	int		n_cmd;
	int		num_cmd;
	int		std_in;
	int		std_out;
	char	*str;
	t_env	*env_list;
	int		is_built;
	int		error_doc;
}	t_var;

int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strnstr(const char *haystack, const char \
				*needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
unsigned long long	ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
t_list				*ft_lstnew(void *content, char **cmd);
t_list_str			*new_list_str(char *content, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list_str			*list_strlast(t_list_str *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				list_stradd_back(t_list_str **lst, t_list_str *new);
int					ft_lstsize(t_list *lst);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				list_strclear(t_list_str **lst);

#endif
