/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:11:14 by hachahbo          #+#    #+#             */
/*   Updated: 2023/08/06 19:38:24 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libc.h>
# include <stdio.h>
# include <ctype.h>
# include <errno.h>
# include <dirent.h>
# include <termios.h>
# include <readline/readline.h>
# include <sys/stat.h>
# include <readline/history.h>
# include "libft/libft.h"

int	g_state_exit;

void	ft_make_list(char *input, t_list **head, t_var *vars);
int		is_spaces(char *str);
char	*skip_spaces(char *input);
char	*check_data(char *input, int *start, int *end);
void	ft_status(t_list *new, int *flag1, int *flag2);
int		ft_strcmp(char *s1, char *s2);
int		is_spaces(char *str);
int		ft_strisspace(const char *str);
char	*skip_spaces(char *input);
int		check_d_quote(t_list *head);
int		ft_empty(t_list *head);
int		check_pipes(t_list *head);
int		check_redirection(t_list *head);
int		check_num_herdoc(t_list *head);
void	ft_status(t_list *new, int *flag1, int *flag2);
char	*check_data(char *input, int *start, int *end);
void	ft_lstclear(t_list **lst);
void	ft_env(t_env *env_list, t_var *var);
void	ft_make_new_list(t_list *head, t_list **new_list, t_env *env_list);
void	ft_pwd(t_env *env_list, t_var *var);
char	*ft_expand_value(char *str, t_env *env_list);
int		rendering_cd(t_list *list, t_env **env_list);
int		ft_echo(t_list *head, t_var *var);
int		ft_builtins(t_list *list, t_env **env_list, t_var *var);
char	*handle_env(t_list *list, t_env *env_list, int num_env);
int		serche_for_doc(t_list *list);
void	ft_make_new_list_w_s(t_list *new_list, t_list **new_list_w_s);
int		skip_node(t_list *head, int num_env);
void	add_node(t_list **new_list, char *str, int in_join);
void	ft_finale_list(t_list *new_list_w_s, t_list **last_list);
int		count_arg(t_list *new_list_w_s);
void	free_double(char **str);
void	get_command(t_list *new_list_w_s, t_list **last_list);
void	sit_type(t_list *list);
void	ft_split_list(t_list **new_list_w_s,
			t_list **last_list, int *is_cmd, int *is_doc);
void	parser(t_list *head, t_env **env_list, char *input);
void	affiche_error(void);
int		is_doc(t_list *list);
char	*generate_value_of_env(char *str, char *tmp,
			t_list_str **list_str, t_list **new_list);
char	*join_list_str(char *s1, char *s2, t_list_str **list_str);
int		join_node(t_list *head);
void	ft_skip_node(t_var *var, t_list *head);
void	creat_word(t_list *head, t_list **new_list,
			t_list_str	**list_str, t_var *var);
int		is_word(t_list *head);
void	get_command_and_arg(char **cmd, t_list *new_list_w_s);
void	get_pipe(t_list *new_list_w_s, t_list **last_list);
void	get_doc(t_list **new_list_w_s, t_list **last_list);
char	**ft_str_double_dup(char **str);
int		ft_open_infile(t_list *node, t_var *var, t_env *env_list);
int		ft_open_outfile(t_list *node, t_var *var, t_env *env_list);
int		ft_open_append_file(t_list *node, t_var *var, t_env *env_list);
int		ft_open_heredoc(t_list *node, t_var *var);
char	*get_string_doc(t_list *list, t_var *var,
			t_env *env_list, t_list_str **list_str);
void	ft_skip_node_doc(t_list *list, t_var *var);
int		skip_node_doc(t_list *list, t_var *var);
void	ft_init_var(t_var *var);
char	*handle_env_doc(t_list *list, t_env *env_list, int num_env);
void	ft_msg_null_doc(t_list *node, t_var *var);
void	ft_msg_error_infile(char *str_DOC, t_var *var);
void	ft_msg_error_outfile(char *str_DOC, t_var *var);
char	*get_string_heredoc(t_list *list,
			t_var *var, t_list_str **list_str);
void	ft_skip_node_heredoc(t_list *list, t_var *var);
int		skip_node_heredoc(t_list *list);
char	*handle_env_heredoc(t_list *list, t_var *var);
void	fill_file(char *delimiter, int fd, t_var *var);
void	ft_expand_in_heredoc(t_var *var, char *line,
			t_list_str **list_str, int fd);
char	*get_string_delimiter(t_list *list, t_var *var,
			t_env *env_list, t_list_str **list_str);
void	ft_init_var_delimiter(t_var *var);
char	*handle_env_in_heredoc(t_list *list, t_env *env_list, int num_env);
int		skip_node_delimiter(t_list *list, t_var *var);
void	ft_skip_node_delimiter(t_var *var);
char	*handle_env_heredoc(t_list *list, t_var *var);
int		skip_node_heredoc(t_list *list);
void	ft_skip_node_heredoc(t_list *list, t_var *var);
char	*get_string_heredoc(t_list *list, t_var *var, t_list_str **list_str);
void	ft_msg_error_heredoc(char *name);
void	ft_delete_here_doc(char *name_file);
char	*ft_name_file(void);
int		ft_num_pipe(t_list *last_list);
char	**ft_spaces_split(char *s);
int		check_is_valid(t_env *new_env, t_var *var);
void	ft_free_head_vars(t_var *vars, t_list **head);
void	ft_add_to_history(char *input);
int		ft_creat_list_env(char **env, t_env **new_env_list);
void	ft_begin(int std_in, t_env **env_list);
void	init_var(t_var *var, int num_pipe);
char	**creat_env(void);
void	ft_child_proccess(t_list *last_list, t_env **env_list,
			t_var *var, t_list_str **list_heredoc);
void	ft_serche_for_doc(t_list *last_list, t_env *env_list,
			t_var *var, t_list_str **list_heredoc);
void	ft_serche_for_cmd(t_list **last_list);
void	serch_for_heredoc(t_var *var,
			t_list_str **list_heredoc, int *other_inf);
void	serch_for_inf(t_list *last_list,
			t_var *var, t_env *env_list, int *other_inf);
void	serch_for_outf(t_list *last_list,
			t_env *env_list, t_var *var, int *other_outf);
int		ft_listchr(t_list *list, int type);
void	ft_serche_for_heredoce(t_list *last_list,
			t_var *var, t_list_str **list_heredoc);
int		ft_serche_for_redir_in(t_list *last_list);
void	wait_childs(t_var *var, pid_t last_child);
void	exec_child(t_list *last_list,
			t_env **env_list, t_var *var, int num_pipe);
void	ft_position_start_end(t_list **last_list,
			t_list_str **list_heredoce_tmp);
void	ft_execution(t_list *last_list, t_env **env_list, t_var *var);
int		ft_pipe(t_var *var, int num_pipe);
void	ft_duplicate(t_var *var);
void	error_fork(void);
int		ft_is_builting_cmd(t_list *last_list, t_var *var);
int		get_value(int value);
void	nothing(int sig);
void	sig_handler(int sig);
void	nothing_minishell(int sig);
void	error_isdir(char **cmd);
void	error_cmd(char **cmd);
void	set_state_exit(int state);
void	ft_wait(t_var *var, pid_t last_child, t_list_str **list_heredoce);
pid_t	ft_fork(t_var *var, t_list **list,
			t_list_str **list_heredoce_tmp, t_env **env_list);
t_var	*init_vars(t_env *env_list);
int		ft_serche_in_list(t_list *last_list, char *cmd);
char	**check_cmd(t_list *last_list, t_env *env_list);
char	*check_cmd_is_exit(char **paths, char *cmd);
void	ft_serche_for_cmd(t_list **last_list);
char	**return_cmd(char **cmd, char *str, char **paths, char *cm);
char	**get_paths(t_env *env_list, char **cmd);
void	make_copy_env_list_char(char **env, t_env **new_env_list);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
t_env	*ft_lstlast_env(t_env *lst);
t_env	*ft_lstnew_env(char *str, char **env);
char	*delete_back_slash(char *str);
int		check_the_plus(char *str);
char	*until_equal_or_plus(char *big_str, char c);
int		ft_export(t_list *head, t_env **env_list, t_var *var);
void	ft_unset(t_list *list, t_env **env_list, t_var *var);
void	print_sysntax_error(t_list *head);
void	ft_status_next(t_list *new, int *flag1, int *flag2);
void	ft_unset(t_list *list, t_env **env_list, t_var *var);
void	remove_node_2(t_env **head, char *min);
void	hide_path(t_env **head, char *min);
void	free_here(t_env *current);
void	check_the_path(t_env *env_list);
int		check_home(t_env *save);
void	check_cd_one_case(t_env **env_list, t_list *head);
int		ft_check_args_of_cd(t_list *head, t_env **env_list);
int		rendering_cd(t_list *list, t_env **env_list);
void	cd_change_pwd(t_env **env_list, char *str);
void	insert(t_env **root, t_env *item);
int		check_double_key(t_env *new_list, t_env *new_env);
char	*until_equal_or_plus(char *big_str, char c);
void	remove_node(t_env **head, char *min);
t_env	*find_small(t_env *list);
void	ft_print_error(char *s, t_env *new_env, char *str, t_var *var);
void	change_the_value(t_env **env_list, t_env *new_env);
void	chaange_the_value_part_two(t_env *save, t_env *new_env);
void	ft_free_this(t_env *new_env, char *str);
void	ft_print_export(t_env *export_list, t_var *var);
void	ft_close_fd(t_var *var);

#endif