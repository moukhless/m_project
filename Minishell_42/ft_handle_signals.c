/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:49:26 by amoukhle          #+#    #+#             */
/*   Updated: 2023/07/28 00:19:18 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	nothing_minishell(int sig)
{
	(void)sig;
}

void	nothing(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
	else if (sig == SIGQUIT)
		write(1, "Quit: 3\n", 8);
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (get_value(-1) == 3)
		{
			close(0);
			get_value(4);
			g_state_exit = 1;
		}
		else
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_state_exit = 1;
			get_value(1);
		}
	}
	else if (sig == SIGQUIT)
		(void)sig;
}
