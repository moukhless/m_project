/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:55:43 by hachahbo          #+#    #+#             */
/*   Updated: 2023/07/31 12:59:06 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_valid_command(t_list *head)
{
	if (check_d_quote(head))
		return (1);
	if (check_redirection(head))
		return (1);
	if (check_num_herdoc(head))
		return (1);
	if (check_pipes(head))
		return (1);
	return (0);
}

void	parser(t_list *head, t_env **env_list, char *input)
{
	t_list	*new_list;
	t_list	*new_list_w_s;
	t_list	*last_list;
	t_var	*vars;

	new_list = NULL;
	new_list_w_s = NULL;
	last_list = NULL;
	vars = init_vars(*env_list);
	ft_make_list(input, &head, vars);
	if (ft_valid_command(head) == 0)
	{
		ft_make_new_list(head, &new_list, *env_list);
		ft_make_new_list_w_s(new_list, &new_list_w_s);
		ft_finale_list(new_list_w_s, &last_list);
		ft_execution(last_list, env_list, vars);
		ft_lstclear(&head);
		ft_lstclear(&new_list);
		ft_lstclear(&new_list_w_s);
		ft_lstclear(&last_list);
		free(vars);
	}
	else
		ft_free_head_vars(vars, &head);
	ft_add_to_history(input);
}

void	ft_begin(int std_in, t_env **env_list)
{
	char	*input;
	t_list	*head;

	head = NULL;
	while (1)
	{
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
		get_value(0);
		dup2(std_in, 0);
		input = readline("[minishell][$]~> ");
		if (!input)
		{
			write(1, "exit\n", 5);
			clear_history();
			exit (127);
		}
		if (ft_strisspace(input) == 0)
			parser(head, env_list, input);
		else
			free(input);
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;
	int		std_in;

	if (ac != 1)
	{
		write (2, "bash: ", 6);
		write (2, av[1], ft_strlen(av[1]));
		write (2, ": No such file or directory\n", 28);
		exit(1);
	}
	env_list = NULL;
	make_copy_env_list_char(env, &env_list);
	g_state_exit = 0;
	rl_catch_signals = 0;
	std_in = dup(0);
	ft_begin(std_in, &env_list);
	return (0);
}
